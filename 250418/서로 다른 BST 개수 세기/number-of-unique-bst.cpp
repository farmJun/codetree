#include <iostream>

using namespace std;

int n;
int dp[20];


int main() {
    cin >> n;

    dp[1] = 1;
    // dp[2] = 2;
    //dp[3] = 5;

    // 1번부터 n번까지 head를 하겠다는 뜻
   // for(int i = 2; i <= n; i++){

        for(int z= 1; z <= n; z++){

            for(int k = 1; k <= z; k++ ){

                int left = ( k -1 ) - 1;

                int right = z - (k + 1);

                if(left < 0 && right >= 0){
                    dp[z] += dp[right + 1];
                }

                if(left >= 0 && right < 0){
                    dp[z] += dp[left + 1];
                }

                if(left >= 0 && right >= 0){
                    dp[z] += dp[left + 1] * dp[right + 1];
                }
        }


        }
        
  //  }
    

    cout << dp[n];
    return 0;
}

