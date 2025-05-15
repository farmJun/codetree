import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        ArrayList<Integer> list = new ArrayList();

        for(int i = 0; i < n; i++){

            list.add(arr[i]);

            if(list.size() % 2 == 1){
                Collections.sort(list);
                System.out.print(list.get(list.size()/2) + " ") ;
            }
        }

    }
}