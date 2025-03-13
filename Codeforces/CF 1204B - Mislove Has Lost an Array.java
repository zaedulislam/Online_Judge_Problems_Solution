import java.util.Scanner;

public class Main {
    public static int powerOfTwo(int exponent){
        return 1 << exponent;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        int minimumSum = powerOfTwo(l) - 1 + (n - l);
        int maximumSum = powerOfTwo(r) - 1 + powerOfTwo(r - 1) * (n - r);

        System.out.println(minimumSum + " " + maximumSum);
    }
}
