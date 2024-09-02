import java.util.HashMap;

public class SymbolTable {

    //CONSTANTS
    public static final String INITIAL_VALID_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_.$:)";
    public static final String ALL_VALID_CHARS = INITIAL_VALID_CHARS + "1234567890";

    //VARIABLES
    public HashMap<String, String> symbolTable;

    //CONSTRUCTOR
    public SymbolTable() {
        symbolTable = new HashMap<>();
        symbolTable.put("SP", "0");
        symbolTable.put("LCL", "1");
        symbolTable.put("ARG", "2");
        symbolTable.put("THIS", "3");
        symbolTable.put("THAT", "4");
        symbolTable.put("R0", "0");
        symbolTable.put("R1", "1");
        symbolTable.put("R2", "2");
        symbolTable.put("R3", "3");
        symbolTable.put("R4", "4");
        symbolTable.put("R5", "5");
        symbolTable.put("R6", "6");
        symbolTable.put("R7", "7");
        symbolTable.put("R8", "8");
        symbolTable.put("R9", "9");
        symbolTable.put("R10", "10");
        symbolTable.put("R11", "11");
        symbolTable.put("R12", "12");
        symbolTable.put("R13", "13");
        symbolTable.put("R14", "14");
        symbolTable.put("R15", "15");
        symbolTable.put("SCREEN", "16384");
        symbolTable.put("KBD", "24576");
    }

    //CHECKS SYMBOL FOR VALIDITY
    public boolean isValidName(String symbol) {
        if(symbol.length() == 0) return false;
        if(INITIAL_VALID_CHARS.indexOf(symbol.charAt(0)) == -1) return false;

        for(int i = 0; i < symbol.length(); i++) {
            if(ALL_VALID_CHARS.indexOf(symbol.charAt(i)) == -1) return false;
        }
        return true;
    }

    //ADDS ENTRY
    public boolean addEntry(String symbol, int address) {
        if(!isValidName(symbol)) return false;
        if(symbol.charAt(symbol.length() - 1) == ')') {
            symbolTable.put(symbol.substring(0, symbol.length() - 1), address+"");
            return true;
        }
        symbolTable.put(symbol, address+"");
        return true;
    }

    //CHECKS IF SYMBOL IS IN TABLE
    public boolean contains(String symbol) {
        return symbolTable.containsKey(symbol);
    }

    //GETS ADDRESS ASSOCIATED WITH SYMBOL
    public int getAddress(String symbol) {
        return Integer.parseInt(symbolTable.get(symbol));
    }

}
