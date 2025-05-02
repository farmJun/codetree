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


    dp[0][0]= grid[0][0];
    dp[0][1]= grid[0][1] + dp[0][0];
    dp[0][2]= grid[0][2] + dp[0][1];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == 0){
                dp[i][j] =  dp[i-1][j] + grid[i][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
    }


    cout << dp[n-1][n-1];
    return 0;
}
