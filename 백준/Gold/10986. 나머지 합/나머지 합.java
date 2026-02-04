import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long[] arr = new long[n + 1];
        long[] remain = new long[m + 1];
        long cnt = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = (arr[i - 1] + Integer.parseInt(st.nextToken())) % m;
            remain[(int) arr[i]]++;
        }

        cnt += remain[0];
        for (int i = 0; i < m; i++) {
            if (remain[i] > 0 && n != 1) {
                cnt += remain[i] * (remain[i] - 1) / 2;
            }
        }
        System.out.println(cnt);
    }
}