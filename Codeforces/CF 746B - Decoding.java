import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int lengthOfWord = scanner.nextInt();
        scanner.nextLine();
        String encodedString = scanner.nextLine();

        if (lengthOfWord == 1 || lengthOfWord == 2) {
            System.out.println(encodedString);
        } else {
            char[] decodedString = new char[lengthOfWord];

            int leftPointer = 0, rightPointer = 0, midIndex = (lengthOfWord >> 1);

            if ((lengthOfWord & 1) == 0) {
                leftPointer = midIndex - 1;
                rightPointer = midIndex;
            } else {
                leftPointer = midIndex;
                rightPointer = midIndex + 1;
            }

            for (int i = 0; i < lengthOfWord; i++) {
                char ch = encodedString.charAt(i);

                if ((lengthOfWord & 1) == 0) {
                    if ((i & 1) == 0) {
                        decodedString[leftPointer--] = ch;
                    } else {
                        decodedString[rightPointer++] = ch;
                    }
                } else {
                    if (i == 0) {
                        decodedString[leftPointer--] = ch;
                        continue;
                    }

                    if ((i & 1) == 0) {
                        decodedString[rightPointer++] = ch;
                    } else {
                        decodedString[leftPointer--] = ch;
                    }
                }
            }

            System.out.println(decodedString);
        }
    }
}
