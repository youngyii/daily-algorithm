import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double max = -1;
        double[] score = new double[n];
        double sum = 0;

        for (int i = 0; i < n; i++) {
            score[i] = sc.nextInt();
            if (score[i] > max) max = score[i];
            sum += score[i];
        }

        System.out.println(sum * 100 / max / n);
    }
}