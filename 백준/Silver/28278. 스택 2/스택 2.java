import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(st.nextToken());
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());

            switch (m) {
                case 1:
                    stack.push(Integer.parseInt(st.nextToken()));
                    break;
                case 2:
                    if (!stack.isEmpty()) bw.write(stack.pop() + "\n");
                    else bw.write("-1\n");
                    break;
                case 3:
                    bw.write(stack.size() + "\n");
                    break;
                case 4:
                    if (!stack.isEmpty()) bw.write("0\n");
                    else bw.write("1\n");
                    break;
                case 5:
                    if (!stack.isEmpty()) bw.write(stack.peek() + "\n");
                    else bw.write("-1\n");
            }
        }
        bw.flush();
        bw.close();
    }
}