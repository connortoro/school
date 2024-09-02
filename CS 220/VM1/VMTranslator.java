//Connor Toro
//CS220 Spring 23

import java.util.Scanner;
import java.io.File;


public class VMTranslator {    
    public static void main(String[] args) 
    {
    	//instance:    	
    	String inFileName;
		String outFileName = "";
		
		File inFile = null;
		File outFile = null;
		
		CodeWriter writer;
		
		//get file name from command line
        if (args.length == 1) { 
            inFileName = args[0];
        }

        //get file name from keyboard input
        else {
        	Scanner kbd = new Scanner(System.in);
			System.out.print("Enter vm file name: ");
			inFileName = kbd.nextLine();				
			kbd.close();
        }

        //create file and writer objects
        inFile = new File(inFileName);
        outFileName = inFileName.substring(0, inFileName.indexOf(".")) + ".asm";
        outFile = new File(outFileName);
        writer = new CodeWriter(outFile);



            //create parser
            Parser parser = new Parser(inFile);
            Parser.CommandType commandType;

            //parse file loop
            while (parser.hasMoreCommands()) 
            {
                //advance line and get command type
                parser.advance();
                commandType = parser.getCommandType();

                //call writer function based on command type
                if (commandType == Parser.CommandType.C_ARITHMETIC) {
                    writer.writeArithmetic(parser.getArg1());
                } 
                else if (commandType == Parser.CommandType.C_POP || commandType == Parser.CommandType.C_PUSH) {
                    writer.writePushPop(commandType, parser.getArg1(), parser.getArg2());
                }
            }
        
        //close writer
        writer.close();
		
	}
}