
/**
 * Assignment 2: Simple UNIX Shell
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#define MAX_LINE 80 // The maximum length command

/**
 * @brief parse out the command and arguments from the input command separated by spaces
 *
 * @param command
 * @param args
 * @return int
 */
int parse_command(char command[], char *args[])
{
    char* arg = strtok(command, " ");
    int idx = 0;
    while(arg != NULL) {
        args[idx] = arg;
        arg = strtok(NULL, " ");
        idx++;
    }
    args[idx] = NULL;
    return idx;
}
// TODO: Add additional functions if you need

/**
 * @brief The main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @param argc The number of arguments
 * @param argv The array of arguments
 * @return The exit status of the program
 */
int main(int argc, char *argv[])
{
    char command[MAX_LINE];                // the command that was entered
    char *args[MAX_LINE / 2 + 1];          // hold parsed out command line arguments
    int should_run = 1;                    /* flag to determine when to exit program */
    bool should_wait;                      // flag to determine if "&" is present
    bool should_output;                    // flag to determine if >
    bool should_input;                     // flag to determine if <
    bool is_piped;                         // flag to determine if |
    char* file_name;                       // file name of input/output file
    char last_command[MAX_LINE] = {'\0'};  // holds last command
    int pipefd[2];                         // file descriptor pipe
    int pipe_idx;                          // index of pipe character in command
    char *consumer_args[MAX_LINE / 2 + 1];

    // TODO: Add additional variables for the implementation.

    while (should_run)
    {
        // Set flags each iteration
        is_piped = false;
        should_input = false;
        should_output = false;
        should_wait = true;

        printf("osh>");
        fflush(stdout);

        // Read the input command
        fgets(command, MAX_LINE, stdin);

        // Remove the newline character at end
        if(command[1] != '\0') {
            command[strcspn(command, "\n")] = '\0';
        }

        if(strcmp(command, "exit") == 0) {
            return 0;
        }

        // Check for !!, copy last_command -> command and do opposite if not
        if(strcmp(command, "!!") == 0) {
            if(last_command[0] == '\0') {
                cout << "No command history found" << endl;
                continue;
            }
            for(int i = 0; i < MAX_LINE; i++) {
                command[i] = last_command[i];
            }
            cout << command << endl;
        } else {
            for(int i = 0; i < MAX_LINE; i++) {
                last_command[i] = command[i];
            }
        }

        // If "&" exists, set should_wait flag and remove it from command cstring
        if (command[strlen(command) - 1] == '&') {
            should_wait = false;
            command[strlen(command) - 1] = '\0'; // Remove '&' by replacing it with null terminator
        }


        // Parse the input command
        int num_args = parse_command(command, args);

        // Parse for <, >, or |. set flags and fix args array
        for(int i = 0; i < num_args; i++) {
            if(strcmp(args[i], "<") == 0) {
                should_input = true;
                file_name = args[i+1];
                args[i] = NULL;
                break;
            }
            if(strcmp(args[i], ">") == 0) {
                should_output = true;
                file_name = args[i+1];
                args[i] = NULL;
                break;
            }
            if(strcmp(args[i], "|") == 0) {
                is_piped = true;
                args[i] = NULL;
                pipe_idx = i;

                break;
            }
        }


        // TODO: Add your code for the implementation
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) parent will invoke wait() unless command included &
         */

        pid_t pid = fork();

        if(pid == -1) {
            cerr << "Fork Failed!" << endl;

        } else if(pid == 0) {
            // Child Process


            // Redirect stdout --> file_name
            if(should_output) {
                int fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }

            // Make file an input
            if(should_input) {
                int fd = open(file_name, O_RDONLY);
                dup2(fd, STDIN_FILENO);
                close(fd);
            }

            //set up producer/consumer pipes and process
            if(is_piped) {

                //copy args after pipe to new array
                int j = 0;
                for(int i = pipe_idx+1; i < MAX_LINE / 2 + 1; i++) {
                    consumer_args[j] = args[i];
                    j++;
                }

                //setup pipe and fork
                pipe(pipefd);
                pid_t consumer_pid = fork();

                //redirect output for consumer / producer
                if(consumer_pid == 0) {
                    close(pipefd[1]);
                    dup2(pipefd[0], STDIN_FILENO);
                    close(pipefd[0]);

                    execvp(consumer_args[0], consumer_args);
                    
                    cerr << "Bad Command" << endl;
                    return 1;
                } else {
                    close(pipefd[0]);
                    dup2(pipefd[1], STDOUT_FILENO);
                    close(pipefd[1]);
                }
            }

            if(num_args > 0) {
                execvp(args[0], args);
            }


            //only reaches here if failure
            cerr << "Command not found" << endl;
            return 1;
        } else {
            // Parent Process
            if (should_wait) {
                wait(NULL);
            }
        }
    }
    return 0;
}
