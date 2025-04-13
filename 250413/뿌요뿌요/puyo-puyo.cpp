#include <iostream>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];
int cnt;

int dx[] = {1, -1, 0,0};
int dy[] ={0,0, 1, -1};

bool isIn(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

void dfs(int y, int x){
    visited[y][x] = true;

    for(int i = 0; i < 4; i++){
        int curX = x + dx[i];
        int curY = y + dy[i];

        if(grid[y][x] != grid[curY][curX]){
            continue;
        }

        if(!isIn(curY, curX)){
            continue;
        }

        if(!visited[curY][curX]){
            cnt++;
            dfs(curY, curX);
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ansCnt =0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]){
                dfs(i, j);
                ans = max(ans, cnt);
                if(cnt >= 3){
                    ansCnt++;
                }
                cnt = 0;
            }
        }
    }
    
    cout << ansCnt << ' ' << ans + 1;

    return 0;
}
