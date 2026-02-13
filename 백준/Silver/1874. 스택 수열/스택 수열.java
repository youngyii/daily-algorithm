import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Stack<Integer> stack = new Stack<>();
        StringBuffer sb = new StringBuffer();

        int num;
        int lastNum = 0;
        for (int i = 0; i < n; i++) {
            num = sc.nextInt();
            if (stack.empty() || num > lastNum) {
                for (int j = lastNum + 1; j <= num; j++) {
                    stack.push(j);
                    lastNum = j;
                    sb.append("+\n");
                }
            }
            if (num == stack.peek()) {
                stack.pop();
                sb.append("-\n");
                continue;
            }
            break;
        }
        if (stack.empty()) {
            System.out.print(sb.toString());
        } else {
            System.out.println("NO");
        }
    }
}