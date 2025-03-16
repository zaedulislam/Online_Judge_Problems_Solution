import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numberOfDigits = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine();

        String S = scanner.nextLine();

        char[] digitArray = S.toCharArray();

        if (numberOfDigits == 1 && k != 0) {
            System.out.println(0);
            return;
        }

        for (int i = 0; i < numberOfDigits && k > 0; i++) {
            if (i == 0) {
                if (digitArray[i] != '1') {
                    digitArray[i] = '1';
                    k--;
                }
                continue;
            }

            if (digitArray[i] == '0') {
                continue;
            } else {
                digitArray[i] = '0';
            }

            k--;
        }

        System.out.println(digitArray);
    }
}
