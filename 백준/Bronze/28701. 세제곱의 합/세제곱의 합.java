import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        int sumSquard = sum * sum;

        long cubicSum = 0;
        for (int i = 1; i <= n; i++) {
            cubicSum += (long) i * i * i;
        }
        
        System.out.println(sum);
        System.out.println(sumSquard);
        System.out.println(cubicSum);
    }
}