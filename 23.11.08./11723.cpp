#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

long long number = 0;
long long all = pow(2, 22) - 1;

// cin에서 한 번에 받으면, 숫자를 안 받았을 때 문자열이 들어가면서 반복횟수 생략됨.
// endl 대신에 그냥 '\n' 쓰자... 시간초과...

void func(string s){
    int num;
    if(s == "add"){
        cin >> num;
        number = number | (1LL << num);
    }else if(s == "check"){
        cin >> num;
        if(number & (1LL << num))
            cout << "1" << '\n';
        else
            cout << "0" << '\n';
    }else if(s == "remove"){    
        cin >> num;
        number = number & ~(1LL << num);
    }else if(s == "toggle"){
        cin >> num;
        number = number ^ (1LL << num);
    }else if(s == "all"){
        number = number | all;
    }else if(s == "empty"){
        number = 0;
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    string s;
    while(T--){
        cin >> s;
        func(s);
    }
}


/*
 * 아래와 같이 구현하면 시간초과. 비트마스킹을 활용하자.
bool set[21] = { false };

void func(string s, int num){
    if(s == "add"){
        set[num] = true;
    }else if(s == "check"){
        if(set[num]) 
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }else if(s == "remove"){
        set[num] = false;
    }else if(s == "toggle"){
        if(set[num])
            set[num] = false;
        else
            set[num] = true;
    }else if(s == "all"){
        for(int i = 1; i <= 20; i++){
            set[i] = true;
        }
    }else if(s == "empty"){
        for(int i = 1; i <= 20; i++){
            set[i] = false;
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    string s;
    int num;
    while(T--){
        cin >> s >> num;
        func(s, num);
    }

    return 0;
}

*/