import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] n = new int[27];

        for (int i = 0; i < 26; i++) {
            n[i] = -1;
        }

        String s = sc.nextLine();
        for (int i = 0; i < s.length(); i++) {
            if (n[s.charAt(i) - 'a'] != -1) continue;
            n[s.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < 26; i++) {
            System.out.print(n[i] + " ");
        }
    }
}