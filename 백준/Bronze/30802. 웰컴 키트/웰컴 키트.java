import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long[] arr = new long[6];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        long t = Long.parseLong(st.nextToken());
        long p = Long.parseLong(st.nextToken());
        long cnt = 0;

        for (int i = 0; i < 6; i++) {
            if (arr[i] != 0 && arr[i] <= t) {
                cnt++;
            } else if (arr[i] % t == 0) {
                cnt += arr[i] / t;
            } else {
                cnt += arr[i] / t + 1;
            }
        }
        System.out.println(cnt);

        System.out.printf(n / p + " " + n % p);
    }
}