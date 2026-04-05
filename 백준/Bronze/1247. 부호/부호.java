import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 3; i++) {
            int n = sc.nextInt();
            BigInteger sum = BigInteger.ZERO;

            for (int j = 0; j < n; j++) {
                sum = sum.add(sc.nextBigInteger());
            }

            int res = sum.compareTo(BigInteger.ZERO);
            if (res == 0) System.out.println("0");
            else if (res > 0) System.out.println("+");
            else System.out.println("-");
        }
    }
}