#include <iostream>

using namespace std;

int N;
int grid[20][20];
int ans;

bool possible(int i, int j){
    return j + 3 <= N && i + 3 <= N;
}

int calcaulate(int i, int j){
    int cnt = 0;
    for(int y = i; y < i + 3; y++){
        for(int x = j ; x < j + 3; x++){
            if(grid[y][x] == 1){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i< N; i++){
        for(int j = 0; j < N ; j++){
            if(!possible(j, i)){
                continue;
            }
            int cur = calcaulate(i,j);
            ans = max(ans, cur);

        }
    }

    cout << ans;
    return 0;
}

