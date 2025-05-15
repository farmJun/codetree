import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word1 = sc.next();
        String word2 = sc.next();

        if(word1.length() != word2.length()){
            System.out.print("No");
            return;
        }

        char[] arr1 = word1.toCharArray();
        char[] arr2 = word2.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        word1 = new String(arr1);
        word2 = new String(arr2);
        
        if(word1.equals(word2)){
            System.out.print("Yes");
        } else{
            System.out.print("No");
        }

    }
}