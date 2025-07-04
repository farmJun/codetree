#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[100000];
int maxNum;
queue<int>q[10];

void radixSort(){

    int now = 1;

    while(true){
        if(now >= maxNum){
            break;
        }
        now *= 10;
    }


    for(int i = 1; i < now; i *= 10){
    
        for(int j =0; j < n; j++){
            if(arr[j] < i){
                q[0].push(arr[j]);
            } else{
                int cur = (arr[j] / i) % 10;
                q[cur].push(arr[j]);
            }
        }
        int k = 0;
        for(int j = 0; j < 10; j++){
            while(!q[j].empty()){
                arr[k] = q[j].front();
                q[j].pop();
                k++;
            }
        }

    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxNum = max(arr[i], maxNum);
    }

    radixSort();

    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}
