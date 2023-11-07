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
    
    while(true) {
        int check = 0;
        int num[3];
        for(int i = 0; i < 3; i++){
            cin >> num[i];
            if(num[i] == 0) {
                check++;
            }
        }
        if(check == 3)
            break;

        sort(num, num+3, greater());

        if(num[0]*num[0] == num[1]*num[1] + num[2]*num[2]){
            cout << "right" << endl;
        }else {
            cout << "wrong" << endl;
        }
    }

    return 0;
}