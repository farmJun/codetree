#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int grid[100][100];
int r, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[100][100];

queue<pair<int, int>> q;

bool isIn(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

int bfs(int start){
    int maxNum = 0;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int curX = cur.second + dx[i];
            int curY = cur.first + dy[i];


            if(!isIn(curY, curX)){
                continue;
            }

            if(grid[curY][curX] >= start){
                continue;
            }

            if(!visited[curY][curX]){
                visited[curY][curX] = true;
                maxNum = max(maxNum, grid[curY][curX]);
                q.push({curY, curX});
            }
        }
    }
    return maxNum;
}

pair<int, int> find(int num){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == num && visited[i][j]){
                return {i, j};
            }
        }
    }
    return {0, 0};
}

void clear(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    pair<int, int> position = {r-1, c-1};
    while(k--){
        int y = position.first;
        int x = position.second;
        visited[y][x]=true;
        q.push({y, x});

        int maxNum = bfs(grid[y][x]);
    
        if(maxNum == 0){
            break;
        }
        pair<int, int> next = find(maxNum);

        position.first = next.first;
        position.second = next.second;
        clear();
    }
    
    cout << position.first + 1 << ' ' << position.second + 1;

    return 0;
}
