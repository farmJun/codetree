import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String t = sc.next();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = sc.next();
        }

        List<String> result = Arrays.stream(words)
        .filter(w -> w.startsWith(t))
        .sorted()                              
        .collect(Collectors.toList());  

        System.out.print(result.get(k-1));
    }
}