#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int N = 0;
        bool flag = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                N++;
            }else{
                N--;
            }
            if(N < 0){
                flag = false;
            }
        }
        if(flag == false){
            cout << "NO" << endl;
        }else if(N == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}