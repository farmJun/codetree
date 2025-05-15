import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            nums[i] = sc.nextInt();
        }
        Arrays.sort(nums);

        int ans = 0;
        for(int i = 0 ; i < n; i++){
            int sum = nums[i] + nums[2 * n - 1 - i];
            if(sum > ans){
                ans = sum;
            }
        }
        System.out.print(ans);
    }
}