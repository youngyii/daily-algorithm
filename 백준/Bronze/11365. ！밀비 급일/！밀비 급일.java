import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        while (true) {
            String str = br.readLine();
            
            // 1. Check for null (end of stream) or the "END" keyword
            if (str == null || str.equals("END")) {
                break;
            }

            // 2. Efficiently reverse and append
            StringBuilder temp = new StringBuilder(str);
            result.append(temp.reverse()).append("\n");
        }
        
        // 3. Print everything at once
        System.out.print(result);
    }
}