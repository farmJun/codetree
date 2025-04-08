#include <iostream>

using namespace std;

int n, m, ans;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int cur  = grid[i][0];
        int cnt  = 0;

        for (int j = 0; j < n; j++) {
            if(grid[i][j] == cur){
                cnt ++;
            } else{
                cnt = 1;
            }

            if(cnt == m){
                ans ++;
                break;
            }

            cur = grid[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        int cur  = grid[0][i];
        int cnt  = 0;
        for (int j = 0; j < n; j++) {
            if(grid[j][i] == cur){
                cnt ++;
            } else{
                cnt = 1;
            }
            
            if(cnt == m){
                ans ++;
                break;
            }
            cur = grid[j][i];
        }
    }
    

    cout << ans;

    return 0;
}

