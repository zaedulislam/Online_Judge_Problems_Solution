import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String firstLayout = scanner.nextLine();
        String secondLayout = scanner.nextLine();
        String typedText = scanner.nextLine();

        char[] characterMap = new char[26];

        int firstLayoutLength = firstLayout.length();
        for (int i = 0; i < firstLayoutLength; i++) {
            int keyIndex = firstLayout.charAt(i) - 97;
            characterMap[keyIndex] = secondLayout.charAt(i);
        }

        int typedTextLength = typedText.length();
        for (int i = 0; i < typedTextLength; i++) {
            char key = typedText.charAt(i);

            if (key >= '0' && key <= '9') {
                System.out.print(key);
            } else if (key >= 'A' && key <= 'Z') {
                char keyLowerCase = (char) (key + 32);
                char intendedKey = characterMap[keyLowerCase - 97];
                System.out.print((char) (intendedKey - 32));
            } else {
                System.out.print(characterMap[key - 97]);
            }
        }

        System.out.println();
    }
}
