#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int arr[100000];
bool visited[100000];

int main() {
    unordered_map<long long, int> m;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    long long count = 0;
    long long count2 = 0;
    for(auto i = m.begin(); i != m.end(); i++){
        int value = k - i->first;

        if( i->second > 1 && i -> first == value){
            count += (i->second) * (i->second -1) / 2;
            continue;
        }

        auto index = m.find(value);
        if(index != m.end()){
            int num = i->second * index -> second;
            count2+=num;
        }
    }

    cout << count + count2/2;

    return 0;
}
