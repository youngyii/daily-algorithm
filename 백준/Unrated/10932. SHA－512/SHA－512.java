import java.io.*;
import java.security.MessageDigest;
import java.util.*;
import java.security.NoSuchAlgorithmException;

public class Main {
    public static void main(String[] args) throws IOException, NoSuchAlgorithmException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String str = br.readLine();

        MessageDigest digest = MessageDigest.getInstance("SHA-512");

        byte[] hashBytes = digest.digest(str.getBytes("UTF-8"));

        for (int i = 0; i < hashBytes.length; i++) {
            sb.append(Integer.toString((hashBytes[i] & 0xff) + 0x100, 16).substring(1));
        }

        String result = sb.toString();
        System.out.println(result);
    }
}