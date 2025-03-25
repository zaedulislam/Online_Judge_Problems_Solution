import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int numberOfKeyboards = sc.nextInt();
        int minIndex = Integer.MAX_VALUE;
        int maxIndex = Integer.MIN_VALUE;
 
        for (int i = 0; i < numberOfKeyboards; i++) {
            int keyboardIndex = sc.nextInt();
 
            minIndex = Integer.min(keyboardIndex, minIndex);
            maxIndex = Integer.max(keyboardIndex, maxIndex);
        }
 
        System.out.println(maxIndex - minIndex - numberOfKeyboards + 1);
    }
}
