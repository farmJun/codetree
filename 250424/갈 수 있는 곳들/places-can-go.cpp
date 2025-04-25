#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


queue<pair<int, int>> q;

bool isIn(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

int bfs(){
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int curX = cur.second + dx[i];
            int curY = cur.first + dy[i];

            if(!isIn(curY, curX)){
                continue;
            }


            if(grid[curY][curX]){
                continue;
            }
            
            if(!visited[curY][curX]){
                visited[curY][curX] = true;
                q.push({curY, curX});  
                cnt++; 
            }
        }
    }
    return cnt;
}





int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    int ans = 0;
    for(int i = 0; i < k; i++){
        int y = r[i] - 1;
        int x = c[i] - 1;

        if(!visited[y][x]){
            q.push({y, x});
            visited[y][x] = true;
            ans += (bfs() + 1);
        }
    }

    cout << ans;
    return 0;
}
