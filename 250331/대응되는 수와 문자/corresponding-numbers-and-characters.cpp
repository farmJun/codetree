#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
string words[100000];
string queries[100000];

int main() {
    unordered_map<string, string> m1;
    unordered_map<string, string> m2;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        string num = to_string(i);
        m1[num] = words[i];
        m2[words[i]] = num;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];

        if(m1.find(queries[i]) != m1.end()){
            cout << m1[queries[i]] << '\n';
        }else{
            cout << m2[queries[i]] << '\n';
        }
    }

    // Please write your code here.

    return 0;
}
