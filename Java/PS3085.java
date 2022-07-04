package Java;

import java.util.Scanner;

public class PS3085 {
  public static char[][] board;
  public static int n;
  public static int maxNum = 0;

  // 사탕 개수 세는 메소드
  public static void countCandy() {
    // 가로로 세기
    for (int i = 0; i < n; i++) {
      int count = 1;
      for (int j = 0; j < n - 1; j++) {
        if (board[i][j] == board[i][j + 1])
          count += 1;
        else
          count = 1;

        maxNum = Math.max(maxNum, count);
      }
    }
    for (int i = 0; i < n; i++) {
      int count = 1;
      for (int j = 0; j < n - 1; j++) {
        if (board[j][i] == board[j + 1][i])
          count++;
        else
          count = 1;

        maxNum = Math.max(maxNum, count);
      }
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    board = new char[n][n];

    for (int i = 0; i < n; i++) {
      String str = sc.next();
      for (int j = 0; j < n; j++) {
        board[i][j] = str.charAt(j);
      }
    }

    // 가로로 바꾸기
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {

        char temp = 0;
        temp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = temp;

        countCandy();

        temp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = temp;
      }
    }

    // 세로로 바꾸기
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {

        char temp = 0;
        temp = board[j][i];
        board[j][i] = board[j + 1][i];
        board[j + 1][i] = temp;

        countCandy();

        temp = board[j][i];
        board[j][i] = board[j + 1][i];
        board[j + 1][i] = temp;
      }
    }

    System.out.println(maxNum);

    sc.close();
  }

}
