import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);

        int cnt = 0;
        int sum;
        for (int i = n - 1; i >= 0; i--) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                if (end == i) {
                    end--;
                    continue;
                } else if (start == i) {
                    start++;
                    continue;
                }

                sum = arr[start] + arr[end];
                if (sum == arr[i]) {
                    cnt++;
                    break;
                } else if (sum < arr[i]) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        System.out.println(cnt);
    }
}