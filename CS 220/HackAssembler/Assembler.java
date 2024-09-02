import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;

public class Assembler {
    
    //MAIN METHOD
    public static void main(String[] args) {

        //INSTANCE VARIABLES
        String inFileName, outFileName;
        SymbolTable symbolTable;

        //GET  IN FILE NAME
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter file name to be assembled: ");
        inFileName = scanner.nextLine();
        scanner.close();

        //SAVE OUT FILE NAME
        outFileName = inFileName.substring(0, inFileName.indexOf(".")) + ".hack";

        //CREATE OUT FILE & INTIALIZE
        try {
            PrintWriter outputFile = new PrintWriter(new FileOutputStream(outFileName));
            symbolTable = new SymbolTable();
            firstPass(inFileName, symbolTable);
            System.out.println(symbolTable.symbolTable);
            secondPass(inFileName, outputFile, symbolTable);
            outputFile.close();
        } catch (FileNotFoundException e) {
            handleError("Could not open out file: " + outFileName);
        }
    }

    //FIRST PASS OF ASM
    public static void firstPass(String inFileName, SymbolTable symbolTable) {
        int rom = 0;
        String symbol;
        try {
            Parser parser = new Parser(inFileName);
            while(parser.hasMoreCommands()) {
                parser.advance();
                Command commandType = parser.getCommandType();
                
                if(commandType == Command.A_COMMAND || commandType == Command.C_COMMAND) rom++;

                if(commandType == Command.L_COMMAND) {
                    symbol = parser.getSymbol();
                    if(!symbolTable.contains(symbol)) {
                        if(!symbolTable.addEntry(symbol, rom)) {
                            handleError("ERROR: Invalid symbol in ASM");
                        }
                    }
                }
            }
        } catch(FileNotFoundException e) {
            handleError("ERROR: Invalid Symbol");
        }
    }

    //SECOND PASS OF ASM
    public static void secondPass(String inFileName, PrintWriter outFile, SymbolTable symbolTable) {
        CInstructionMapper cMapper = new CInstructionMapper();
        int ram = 16;
        String comp = "";
        String dest = "";
        String jump = "";
        String symbol = "";
        String binary;

        try {
            Parser parser = new Parser(inFileName);

            while(parser.hasMoreCommands()) {
                binary = "";
                parser.advance();
                Command commandType = parser.getCommandType();
                
                switch(commandType) {
                    case A_COMMAND:
                        int num;
                        symbol = parser.getSymbol();
                        try {
                            num = Integer.parseInt(symbol);
                            binary += decimalToBinary(num);
                        } catch(NumberFormatException e) {
                            if(symbolTable.contains(symbol)) {
                                binary += decimalToBinary(symbolTable.getAddress(symbol));
                            } else {
                                if(!symbolTable.addEntry(symbol, ram)) {
                                    handleError("ERROR: Invalid symbol");
                                }
                                binary += decimalToBinary(ram);
                                ram++;
                            }
                        }
                        outFile.write(binary + "\n");
                        break;
                    
                    case C_COMMAND: 
                        comp = cMapper.comp(parser.getComp());
                        dest = cMapper.dest(parser.getDest());
                        jump = cMapper.jump(parser.getJump());
                        binary = "111" + comp + dest + jump;
                        outFile.write(binary + "\n");
                        break;
                    case L_COMMAND:
                        break;
                    case NO_COMMAND:
                        break;
                }
            }

        } catch(FileNotFoundException e) {
            handleError("ERROR: could not open input file");
        }
    }

    
    
    //HANDLE ERRORS
    public static void handleError(String errormsg) {
        System.err.println(errormsg);
        System.exit(0);
    }

    //CONVERT TO 16 DIGIT BINARY
    public static String decimalToBinary(int num) {
        String bin = Integer.toBinaryString(num);
        String zeroes = "";
        for(int i = 16-bin.length(); i > 0; i--) {
            zeroes += "0";
        }
        return zeroes + bin;
    }
}
