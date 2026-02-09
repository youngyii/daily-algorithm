import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int s = sc.nextInt();
        int p = sc.nextInt();
        String arr = sc.next();
        int[] minCnt = new int[4];
        int[] nowCnt = new int[4];
        for (int i = 0; i < 4; i++) {
            minCnt[i] = sc.nextInt();
        }
        for (int i = 0; i < p; i++) {
            if (arr.charAt(i) == 'A') {
                nowCnt[0]++;
            } else if (arr.charAt(i) == 'C') {
                nowCnt[1]++;
            } else if (arr.charAt(i) == 'G') {
                nowCnt[2]++;
            } else if (arr.charAt(i) == 'T') {
                nowCnt[3]++;
            }
        }

        int cnt = 0;
        int start = 0;
        int end = start + p - 1;
        while (end != s) {
            int pw = 1;
            for (int i = 0; i < 4; i++) {
                if (nowCnt[i] < minCnt[i]) {
                    pw = 0;
                }
            }
            if (pw == 1) {
                cnt++;
            }

            if (arr.charAt(start) == 'A') {
                nowCnt[0]--;
            } else if (arr.charAt(start) == 'C') {
                nowCnt[1]--;
            } else if (arr.charAt(start) == 'G') {
                nowCnt[2]--;
            } else if (arr.charAt(start) == 'T') {
                nowCnt[3]--;
            }
            start++;
            if (end + 1 == s) break;
            end++;
            if (arr.charAt(end) == 'A') {
                nowCnt[0]++;
            } else if (arr.charAt(end) == 'C') {
                nowCnt[1]++;
            } else if (arr.charAt(end) == 'G') {
                nowCnt[2]++;
            } else if (arr.charAt(end) == 'T') {
                nowCnt[3]++;
            }
        }
        System.out.println(cnt);
    }
}