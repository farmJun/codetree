import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Integer[] arr2 = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        Arrays.sort(arr2);

        for(int a : arr2){
            System.out.print(a + " ");
        }
        System.out.println();

        Arrays.sort(arr2, Collections.reverseOrder());
        for(int a : arr2){
            System.out.print(a + " ");
        }        

    }
}