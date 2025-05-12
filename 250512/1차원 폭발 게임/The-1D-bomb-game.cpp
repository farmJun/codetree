#include <iostream>

using namespace std;

int n, m;
int numbers[100];

void move(int idx, int cnt){

    for(int i = idx; i < n; i++){
        numbers[i - cnt] = numbers[i];
    }
    n -= cnt;
}

void print(){
    for(int i = 0; i < n; i++){
        cout << numbers[i] << '\n';
    }
    //cout << "finish";
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }


    for(int i = 0; i < n; i++){
        //cout << "i = " << i << '\n';
        int next = i + 1;
        int cnt = 1;

        while(numbers[next] == numbers[i]){
            //cout << "i = " << i << " next = " << next << '\n';
            //cout << "i = " << numbers[i] << " next = " << numbers[next] << '\n';
            next++;
            cnt++;
        }

        //cout << next << ' ' << cnt << '\n';
        if(cnt >= m){
            move(next, cnt);
            //print();
            i = -1;
        }
    }


    cout << n << '\n';
    print();

    return 0;
}
