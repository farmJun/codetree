#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int, int>> q;

bool isIn(int y, int x){
    return y >= 0 && y < n && x >=0 && x < m;
}


void bfs(){
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();


        for(int i = 0; i < 4; i++){
            int curX = cur.second + dx[i];
            int curY = cur.first + dy[i];


            if(a[curY][curX] == 0){
                continue;
            }

            if(!isIn(curY, curX)){
                continue;
            }

            if(!visited[curY][curX]){
                visited[curY][curX] = true;
                q.push({curY, curX});
            }
        }

    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    q.push({0, 0});
    visited[0][0] = true;
    bfs();

    if(visited[n-1][m-1]){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
