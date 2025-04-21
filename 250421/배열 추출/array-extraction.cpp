#include <iostream>
#include <queue>

using namespace std;

int n;
int x[200000];

int main() {
    priority_queue<int> pq;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];

        if(x[i] == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            } else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(x[i]);
        }
    }

    // Please write your code here.

    return 0;
}
