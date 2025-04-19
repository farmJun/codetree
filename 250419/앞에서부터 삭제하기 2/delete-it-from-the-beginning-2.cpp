#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[100000];

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    pq.push(arr[N-1]);
    sum += arr[N-1];

    double maxAvg = 0;

    for(int i = N-2 ; i >= 1 ; i--){
        pq.push(arr[i]);
        sum += arr[i];
        
        double avg = (double)(sum - pq.top()) / (N - i - 1);
        maxAvg = max(maxAvg, avg);
    }
    cout << fixed;
    cout.precision(2);
    cout << maxAvg;

    return 0;
}
