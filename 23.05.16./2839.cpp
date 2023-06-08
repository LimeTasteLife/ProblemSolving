#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;


    int result = -1;
    for(int i = 0; i < 5; i ++){
        int num;
        num = N - 3*i;
        if(num < 0){
            break;
        }

        if(num % 5 == 0){
            result = num/5 + i;
            break;
        }
    }

    cout << result << endl;
    return 0;
}