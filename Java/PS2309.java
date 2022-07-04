package Java;

import java.util.Arrays;
import java.util.Scanner;

public class PS2309 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int[] heights = new int[9];
    int sum = 0;
    int notDwarf1 = 0, notDwarf2 = 0;
    boolean found = false;

    for (int i = 0; i < 9; i++) {
      heights[i] = sc.nextInt();
      sum += heights[i];
    }
    Arrays.sort(heights);

    for (int i = 0; i < heights.length - 1; i++) {
      for (int j = i + 1; j < heights.length; j++) {
        if (sum - heights[i] - heights[j] == 100) {
          notDwarf1 = heights[i];
          notDwarf2 = heights[j];
          found = true;
          break;
        }
      }
      if (found == true) {
        break;
      }
    }
    for (int i = 0; i < heights.length; i++) {
      if (heights[i] == notDwarf1 || heights[i] == notDwarf2) {
        continue;
      }
      System.out.println(heights[i]);
    }

    sc.close();
  }
}
