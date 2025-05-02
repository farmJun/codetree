#include <iostream>

using namespace std;

int n;
int grid[100][100];
long long dp[100][100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][n-1] = grid[0][n-1];

    for(int i = n - 2; i >=0; i--){
        dp[0][i] = dp[0][i+1] + grid[0][i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if(j == n-1){
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }else{
                dp[i][j] = min(dp[i][j+1], dp[i-1][j]) + grid[i][j];
            }
        }
    }

    cout << dp[n-1][0];
    return 0;
}
