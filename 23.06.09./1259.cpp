#include <string>
#include <iostream>

using namespace std;

int main(void){
    string S;
    bool loop = true;
    while(loop){
        cin >> S;
        int n = S.length();

        if(S == "0"){
            loop = false;
        }else{
            bool flag = true;
            for(int i = 0; i < n/2; i++){
                if(S[i] != S[n-i-1]){
                    flag = false;
                    break;
                }
            }

            if(flag == true){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}