#include <iostream>

using namespace std;

int n;
int dp[1001];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;


    for(int i = 3; i <= n; i++){

        dp[i] = (dp[i-1]*2 + dp[i-2] * 3) % 1000000007;

        for(int j = i -3 ; j>=0; j--){
            dp[i] = (dp[i] + 2 * dp[j]) % 1000000007;
        }



    }
    cout << dp[n];

    return 0;
}
