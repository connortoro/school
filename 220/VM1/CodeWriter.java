//Connor Toro
//CS220 Spring 23

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class CodeWriter 
{
    //simple arithemtic template
    public static final String arithmeticTemplate = "@SP\n" + "AM=M-1\n" + "D=M\n" + "A=A-1\n";

	//instance variables
    private int arithmeticJumpFlag;
    private PrintWriter outputFile;
    
   	//CONSTRUCTOR
    public CodeWriter(File outFile) {
        try {
            outputFile = new PrintWriter(outFile);
            arithmeticJumpFlag = 0;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    	
   	//WRITE ARITHMETIC
    public void writeArithmetic(String command) {
        System.out.println(command);
        outputFile.print("\n//" + command + "\n");
        switch(command) {
            case "add":
                outputFile.print(arithmeticTemplate + "M=M+D\n");
                break;
            case "sub":
                outputFile.print(arithmeticTemplate + "M=M-D\n");
                break;
            case "and":
                outputFile.print(arithmeticTemplate + "M=M&D\n");
                break;
            case "or":
                outputFile.print(arithmeticTemplate + "M=M|D\n");
                break;
            case "gt":
                outputFile.print(arithmeticTemplate("JLE")); 
                arithmeticJumpFlag++;
                break;
            case "lt":
                outputFile.print(arithmeticTemplate("JGE"));
                arithmeticJumpFlag++;
            case "eq":
                outputFile.print(arithmeticTemplate("JNE")); 
                arithmeticJumpFlag++;
            case "not":
                outputFile.print("@SP\nA=M-1\nM=!M\n");
                break;
            case "neg":
                outputFile.print("D=0\n@SP\nA=M-1\nM=D-M\n");
                break;
            default:
                throw new IllegalArgumentException("error: bad arg passed to writeArithmetic(): " + command);
        }
    }
    
    //WRITE PUSH OR POP
    public void writePushPop(Parser.CommandType command, String fragment, int index) {
        outputFile.print("\n//" + command + " " + fragment + "\n");
        if (command == Parser.CommandType.C_PUSH ) {
            System.out.println(command + " : " + fragment);
            switch(fragment) {
                case "constant":
                    outputFile.print("@" + index + "\n" + "D=A\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
                    break;
                case "local":
                    outputFile.print(pushTemplate("LCL",index,false));
                    break;
                case "argument":
                    outputFile.print(pushTemplate("ARG",index,false));
                    break;
                case "this":
                    outputFile.print(pushTemplate("THIS",index,false));
                    break;
                case "that":
                    outputFile.print(pushTemplate("THAT",index,false));
                    break;
                case "temp":
                    outputFile.print(pushTemplate("R5", index + 5,false));
                    break;
                case "pointer":
                    if(index == 0) outputFile.print(pushTemplate("THIS",index,true));
                    if(index == 1) outputFile.print(pushTemplate("THAT",index,true)); 
                    break;
                case "static":
                    outputFile.print(pushTemplate(String.valueOf(16 + index),index,true));
                    break;
                default:
                    throw new IllegalArgumentException("error: bad arg fragment1 passed to writePushPop(): " + fragment);
            }
        } else if(command == Parser.CommandType.C_POP) {
            System.out.println(command + " : " + fragment);
            switch(fragment) {
                case "local":
                    outputFile.print(popTemplate("LCL",index,false));
                    break;
                case "argument":
                    outputFile.print(popTemplate("ARG",index,false));
                    break;
                case "this":
                    outputFile.print(popTemplate("THIS",index,false));
                    break;
                case "that":
                    outputFile.print(popTemplate("THAT",index,false));
                    break;
                case "temp":
                    outputFile.print(popTemplate("R5", index + 5,false));
                    break;
                case "pointer":
                    if(index == 0) outputFile.print(popTemplate("THIS",index,true));
                    if(index == 1) outputFile.print(popTemplate("THAT",index,true)); 
                    break;
                case "static":
                    outputFile.print(popTemplate(String.valueOf(16 + index),index,true));
                    break;
                default:
                    throw new IllegalArgumentException("error: bad arg fragment 2 passed to writePushPop(): " + command);
            } 
        } else {
            throw new IllegalArgumentException("error: bad command passed to writePushPop(): " + command);
        }
    }
        
   	//ARITHMETIC TEMPLATE
    private String arithmeticTemplate(String jump) {
        return arithmeticTemplate + "D=M-D\n" + "@FALSE" + arithmeticJumpFlag + "\n" + "D;" + jump + "\n" + "@SP\n" + "A=M-1\n" + "M=-1\n" + "@CONTINUE" + arithmeticJumpFlag + "\n" + "0;JMP\n" + "(FALSE" + arithmeticJumpFlag + ")\n" + "@SP\n" + "A=M-1\n" + "M=0\n" + "(CONTINUE" + arithmeticJumpFlag + ")\n";
    }

    //PUSH TEMPLATE
    private String pushTemplate(String fragment, int index, boolean direct) {
        String noPointer = "";
        if(!direct) {
            noPointer += "@" + index + "\n" + "A=D+A\nD=M\n";
        }
        return "@" + fragment + "\n" + "D=M\n"+ noPointer + "@SP\n" + "A=M\n" + "M=D\n" + "@SP\n" + "M=M+1\n";
    }
    
   //POP TEMPLATE
    private String popTemplate(String fragment, int index, boolean isDirect) {
        String noPointerCode = (isDirect)? "D=A\n" : "D=M\n@" + index + "\nD=D+A\n";
        return "@" + fragment + "\n" + noPointerCode + "@R13\n" + "M=D\n" + "@SP\n" + "AM=M-1\n" + "D=M\n" + "@R13\n" + "A=M\n" + "M=D\n";
    }
    
    //CLOSE WRITER
    public void close() {
        outputFile.close();
    }
}
