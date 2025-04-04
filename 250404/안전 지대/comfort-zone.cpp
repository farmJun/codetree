#include <iostream>

using namespace std;

int N, M;
int grid[50][50];
bool visited[50][50];
int dx[] = {1, -1, 0,0};
int dy[] ={0,0, 1, -1};
int house;

bool isIn(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < M;
}

void dfs(int y, int x, int k){
    visited[y][x] = true;

    for(int i = 0; i < 4; i++){
        int curX = x + dx[i];
        int curY = y + dy[i];

        if(grid[curY][curX] <= k){
            continue;
        }

        if(!isIn(curY, curX)){
            continue;
        }

        if(!visited[curY][curX]){
            house++;
            dfs(curY, curX, k);
        }
    }
}



int main() {
    cin >> N >> M;
    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            maxHeight = max(maxHeight, grid[i][j]);
        }
    }
    int ans = 0;
    int ansK = 0;

    int area = 0;
    int maxArea = 0;

    for(int k = maxHeight; k >= 1; k--){
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j] && grid[i][j] > k){
                    dfs(i, j, k);
                    area++;
                }
            }
        }

        if(area >= maxArea){
            ansK = k;
            maxArea = area;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                visited[i][j] = false;
            } 
        }
        area = 0;
    }

    cout << ansK << ' ' << maxArea;

    return 0;
}
