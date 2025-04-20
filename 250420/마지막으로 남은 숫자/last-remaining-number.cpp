#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100000];

int main() {
    priority_queue<int> pq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    while(pq.size() >= 2){
        int top = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();

        if(top != top2){
            pq.push(top - top2);
        }
    }

    if(pq.empty()){
        cout << -1;
    } else{
        cout << pq.top();
    }

    return 0;
}
