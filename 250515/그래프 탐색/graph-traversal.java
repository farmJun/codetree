import java.util.*;

public class Main {

    static ArrayList<Integer>[] graph = new ArrayList[1001];
    static boolean[] isVisited = new boolean[1001];
    static int ans = 0;

    public static void dfs(int now){
        
        for(int next : graph[now]){
            if(!isVisited[next]){
                isVisited[next] = true;
                ans++;
                dfs(next);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] u = new int[m];
        int[] v = new int[m];

        for (int i = 0; i < 1001; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            u[i] = sc.nextInt();
            v[i] = sc.nextInt();
            graph[u[i]].add(v[i]);
            graph[v[i]].add(u[i]);
        }
        
        isVisited[1] = true;
        dfs(1);
        System.out.print(ans);

    }
}