import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Parser {
    
    //INSTANCE VARIABLES
    private Scanner inputFile;
    private int lineNumber;
    private String rawLine;
    private String cleanLine;
    private Command commandType;
    private String symbol;
    private String compMnemonic;
    private String destMnemonic;
    private String jumpMnemonic;

    //CONSTRUCTOR
    public Parser(String inFileName) throws FileNotFoundException {
        if(inFileName != null) {
            lineNumber = 0;
            rawLine = "";
            cleanLine = "";
            inputFile = new Scanner(new File(inFileName));
            commandType = Command.NO_COMMAND;
            symbol = "";
            compMnemonic = "";
            destMnemonic = "";
            jumpMnemonic = "";
        } else {
            throw new FileNotFoundException();
        }
    }

    //CHECKS IF FILE HAS MORE COMMANDS (LINES)
    public boolean hasMoreCommands() {
        try {
            if(inputFile.hasNextLine()) {
                return true;
            } 
            return false;
        } catch(IllegalStateException e) {
            return false;
        }
    }

    //READS NEXT LINE, THEN PARSES
    public void advance() {
        lineNumber++;
        rawLine = inputFile.nextLine();
        cleanLine = cleanLine(rawLine);
        parse();
    }

    //CLEANS LINE OF SPACES AND COMMENTS
    public String cleanLine(String rawLine) {
        String clean = rawLine;
        if(rawLine.indexOf("/") != -1) {
            clean = clean.substring(0, rawLine.indexOf("/"));
        }
        clean = clean.trim();
        return clean;
    }

    //PARSES LINE, UPDATING INSTANCE VARIABLES
    public void parse() {
        commandType = parseCommandType(cleanLine);

        if(commandType == Command.A_COMMAND || commandType == Command.L_COMMAND) {
            parseSybmol();
        }

        if(commandType == Command.C_COMMAND) {
            parseComp();
            parseDest();
            parseJump();
        }
    }

    //FIND COMMAND TYPE OF LINE
    public Command parseCommandType(String line) {

        //no command
        if(line.length() == 0) return Command.NO_COMMAND;

        //A command
        if(line.charAt(0) == '@') return Command.A_COMMAND;

        //C command
        if(line.contains("=") || line.contains(";")) return Command.C_COMMAND;

        //L command
        if(line.charAt(0) == '(') return Command.L_COMMAND; 
        
        return Command.NO_COMMAND;
    }

    //PARSE SYMBOL, WHEN A OR L COMMAND
    public void parseSybmol() {
        if(commandType == Command.A_COMMAND) {
            symbol = cleanLine.substring(1);
        }
        symbol = cleanLine.substring(1, cleanLine.length());
    }

    //PARSE COMP, WHEN C COMMAND
    public void parseComp() {
        if(cleanLine.indexOf("=") != -1) {
            if(cleanLine.indexOf(";") == -1) {
                compMnemonic = cleanLine.substring(cleanLine.indexOf("=")+1);
            } else {
                compMnemonic = cleanLine.substring(cleanLine.indexOf("=")+1, cleanLine.indexOf(";"));
            }
        } else {
            compMnemonic = cleanLine.substring(0, cleanLine.indexOf(";"));
        }
    }

    //PARSE DEST, WHEN C COMMAND
    public void parseDest() {
        if(cleanLine.indexOf("=") != -1) {
            destMnemonic = cleanLine.substring(0, cleanLine.indexOf("="));
        } else {
            destMnemonic = "null";
        }
    }

    //PARSE JUMP, WHEN C COMMAND
    private void parseJump() {
        if(cleanLine.indexOf(";") == -1) {
            jumpMnemonic = "null";
        } else {
            jumpMnemonic = cleanLine.substring(cleanLine.indexOf(";")+1);
        }
    }

    //COMMAND TYPE GETTER
    public Command getCommandType() {
        return this.commandType;
    }

    //SYMBOL GETTER
    public String getSymbol() {
        return this.symbol;
    }

    //COMP GETTER
    public String getComp() {
        return this.compMnemonic;
    }

    //DEST GETTER
    public String getDest() {
        return this.destMnemonic;
    }

    //JUMP GETTER
    public String getJump() {
        return this.jumpMnemonic;
    }

    //CLEAN LINE GETTER
    public String getCleanLine() {
        return this.cleanLine;
    }

    //RAW LINE GETTER
    public String getRawLine() {
        return this.rawLine;
    }

    //LINE NUMBER GETTER
    public int getLineNumber() {
        return this.lineNumber;
    }
}
