import java.util.Scanner;

public class TicTacToe {
  private static final int BOARDSIZE = 3;
  enum Status {
    WIN,
    DRAW,
    CONTINUE,
  }
  private char[][] board = new char[3][3];
  private boolean firstPlayer = true;
  private boolean gameOver = false;

  public TicTacToe() {
    for(int i = 0; i < BOARDSIZE; i++) {
      for(int j = 0; j < BOARDSIZE; j++) {
        board[i][j] = ' ';
      }
    }
  }

  public void printBoard() {
    System.out.println("________________________");
    System.out.println("|       |       |       |");
    System.out.println("|   " + board[0][0] + "   |   " + board[0][1] + "   |   " + board[0][2] + "   |");
    System.out.println("|_______|_______|_______|");
    System.out.println("|       |       |       |");
    System.out.println("|   " + board[1][0] + "   |   " + board[1][1] + "   |   " + board[1][2] + "   |");
    System.out.println("|_______|_______|_______|");
    System.out.println("|       |       |       |");
    System.out.println("|   " + board[2][0] + "   |   " + board[2][1] + "   |   " + board[2][2] + "   |");
    System.out.println("|_______|_______|_______|\n");
  }

  public void play() {
    printBoard();
    Scanner scanner = new Scanner(System.in);
    int row = -1, col = -1;
    while(!gameOver) {
      
      char player = firstPlayer ? 'O' : 'X';
      System.out.println("Player " + player + "'s turn");

      boolean valid = false;
      while(!valid) {
        System.out.print("Player " + player + ": Enter Row (0, 1, or 2): ");
        row = scanner.nextInt();
  
        System.out.print("Player " + player + ": Enter Column (0, 1, or 2): ");
        col = scanner.nextInt();

        valid = validMove(row, col);
        if(!valid) {
          System.out.println("Invalid move, try again");
        }
      }


      board[row][col] = player;
      printBoard();
      Status status = gameStatus();
      if(status == Status.DRAW) {
        gameOver = true;
        System.out.println("Draw");
      } else if(status == Status.WIN) {
        gameOver = true;
        System.out.println("Player " + player + " wins");
      }
      firstPlayer = firstPlayer ? false : true;
    }
  }

  private boolean validMove(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2) {
      return false;
    }
    if(board[row][col] != ' ') {
      return false;
    }
    return true;
  }

  private Status gameStatus() {
    char winner = ' ';

    //check for draw / space left
    boolean space = false;
    for(int i = 0; i < BOARDSIZE; i++) {
      for(int j = 0; j < BOARDSIZE; j++) {
        if(board[i][j] == ' ') {
          space = true;
        }
      }
    }
    if(!space) {
      return Status.DRAW;
    }

    for(int i = 0; i < BOARDSIZE; i++) {
      //check horiztonal
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
        winner = board[i][0];
      }
      //check vertical
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
        winner = board[0][i];
      }
    }
    //check diagnoals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
      winner = board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[2][0] != ' ') {
      winner = board[0][2];
    }

    return winner == ' ' ? Status.CONTINUE : Status.WIN;
  }

  private void printSymbol(int column, char value) {
    //unclear what this function is supposed to do
    return;
  }

  private void printStatus(int player) {
    //unclear what this function is supposed to do
    System.out.println(" ");
  }
}

