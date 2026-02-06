import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);

        int cnt = 0;
        int start = 0;
        int end = n - 1;
        int sum;
        while (start < end) {
            sum = arr[start] + arr[end];
            if (sum == m) {
                cnt++;
                start++;
                end--;
            } else if (sum < m) {
                start++;
            }
            else {
                end--;
            }
        }
        System.out.println(cnt);
    }
}