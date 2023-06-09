#include <iostream>

using namespace std;

int func1(int a, int b);

int main(void){
    int a, b;
    int ans1, ans2;
    cin >> a >> b;

    int min = func1(a, b);
    ans1 = min;

    a = a / min;
    b = b / min;
    
    ans2 = min * a * b;

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}

int func1(int a, int b){
    if(b == 0)
        return a;
    else
        return func1(b, a % b);
}