//Connor Toro
//CS220 Spring 23


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
 
public class Parser 
{
    //COMMAND ENUM
	public enum CommandType {
        C_ARITHMETIC,
        C_PUSH,
        C_POP,
        C_LABEL,
        C_GOTO,
        C_IF,
        C_FUNCTION,
        C_RETURN,
        C_CALL
    }
    

    
    //instance variables
    private Scanner fileScanner;
    private String currentCommand;
    private CommandType argType;
    private String arg1;
    private int arg2;

   //CONSTRUCTOR
    public Parser(File inFile) {

        //open input file
        try {
            fileScanner = new Scanner(inFile);
            String line = "";
            String rawLine = "";
            
            //clean every line from file and put into rawLine String
            while(fileScanner.hasNext()) {
                line = removeComments(fileScanner.nextLine()).trim();
                if (line.length() > 0) {
                    rawLine += line + "\n";
                }
            }
            //set scanner to read from rawLine variable
            fileScanner = new Scanner(rawLine.trim());
        } catch (FileNotFoundException e) {
            System.out.println("error: cannot find file");
        }
    }

	//HAS MORE COMMANDS
    public boolean hasMoreCommands() {
       return fileScanner.hasNextLine();
    }

    //ADVANCE
    public void advance() {

        currentCommand = fileScanner.nextLine();
        String[] segment = currentCommand.split(" ");

        switch(segment[0]) {
            case "add":
            case "sub":
            case "neg":
            case "eq":
            case "gt":
            case "lt":
            case "and":
            case "or":
            case "not":
                argType = CommandType.C_ARITHMETIC;
                arg1 = segment[0];
                break;
            case "return":
                argType = CommandType.C_RETURN;
                arg1 = segment[0];
                break;
            default:
                if(segment.length > 1) arg1 = segment[1];
                break;
        }

        switch(segment[0]) {
            case "push":
                argType = CommandType.C_PUSH;
                break;
            case "pop":
                argType = CommandType.C_POP;
                break;
            case "label":
                argType = CommandType.C_LABEL;
                break;
            case "if":
                argType = CommandType.C_IF;
                break;
            case "goto":
                argType = CommandType.C_GOTO;
                break;
            case "function":
                argType = CommandType.C_FUNCTION;
                break;
            case "call":
                argType = CommandType.C_CALL;
                break;
        }


        if (segment.length == 3 && (argType == CommandType.C_PUSH || argType == CommandType.C_POP || argType == CommandType.C_FUNCTION || argType == CommandType.C_CALL)) {
            try {
                arg2 = Integer.parseInt(segment[2]);
            } catch (Exception e) {
                throw new IllegalArgumentException("error: arg2 is not an integer: " + segment[2]);
            }
        }
        
    }
    
	//GET COMMAND TYPE
    public CommandType getCommandType() {
      return argType;
    }
	
    //GET ARG1
    public String getArg1() {
        if (getCommandType() != CommandType.C_RETURN) {
            return arg1;
        } else {
            throw new IllegalStateException("error: no arg1 on return type command");
        }
    }
    
	//GET ARG2
    public int getArg2() {
        if (getCommandType() == CommandType.C_PUSH || getCommandType() == CommandType.C_POP || getCommandType() == CommandType.C_FUNCTION || getCommandType() == CommandType.C_CALL) {
            return arg2;
        }
        else {
            throw new IllegalStateException("error: no arg2");
        }
    }
    
    //GET FILE EXTENSION
    public static String getExtension(String fileName) {
        int index = fileName.lastIndexOf('.');
        if (index != -1) return fileName.substring(index);
        return "";
        
    }
    
    //REMOVE COMMENTS
    private static String removeComments(String line) {
        int position = line.indexOf("//");
        if (position != -1) {
            line = line.substring(0, position);
        }
        return line;
    }
}
