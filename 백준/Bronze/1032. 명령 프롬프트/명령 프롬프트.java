import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        char[] c = sc.nextLine().toCharArray();

        for (int i = 1; i < n; i++) {
            char[] ch = sc.nextLine().toCharArray();
            for (int j = 0; j < c.length; j++) {
                if (c[j] != ch[j]) {
                    c[j] = '?';
                }
            }
        }
        System.out.println(new String(c));
    }
}