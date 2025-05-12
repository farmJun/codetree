#include <iostream>
#include <vector>

using namespace std;

int n, m;
int numbers[100];
int before;
int realSize;

void move(int idx, int cnt){
    for(int i = idx; i < n; i++){
        numbers[i - cnt] = numbers[i];
    }
    n -= cnt;

}

void print(){
    //cout << "print\n";
    for(int i = 0; i < n; i++){
        cout << numbers[i] << '\n';
    }
    //cout << "finish\n";
}

vector<pair<int, int>> get(){

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        int next = i + 1;
        int cnt = 1;
        while(numbers[next] == numbers[i] && next < n){
            next++;
            cnt++;
        }
        if(cnt >= m){
            v.push_back({next, cnt});
            i = next - 1;
        }
    }

    return v;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int size = 0;
    do{
        //cout << "size = " << n <<'\n';
        
        vector<pair<int, int>> v = get();
        size = v.size();
        int before = 0;
        for(auto a : v){
            move(a.first - before, a.second);
            before += a.second;
            //cout << "a << " << a.second <<'\n';
            //print();
        }
    } while(size != 0);

    cout << n << '\n';
    print();

    // for(int i = 0; i < n; i++){
    //     int next = i + 1;
    //     int cnt = 1;
    //     while(numbers[next] == numbers[i]){
    //         next++;
    //         cnt++;
    //     }
    //     if(cnt >= m){
    //         v.push_back({next, cnt});
    //         //move(next, cnt);
    //         //print();
    //         i = next - 1;
    //     }
    // }



    // for(auto a : v){
    //     move(a.first - before, a.second);
    //     before += a.second;
    // }


    // print();
    // v.clear();
    // before = 0;
    // for(int i = 0; i < n; i++){
    //     int next = i + 1;
    //     int cnt = 1;
    //     while(numbers[next] == numbers[i]){
    //         next++;
    //         cnt++;
    //     }
    //     if(cnt >= m){
    //         v.push_back({next, cnt});
    //         //move(next, cnt);
    //         //print();
    //         i = next - 1;
    //     }
    // }



    // for(auto a : v){
    //     move(a.first - before, a.second);
    //     before += a.second;
    // }


    // print();
    // if(n < 0){
    //     cout << 0;
    //     return 0;
    // }

    // cout << n << '\n';
    // print();

    return 0;
}
