#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    char a[T];
    cin >> a;

    int sum = 0;
    for(int i = 0; i < T; i++){
        sum += (int)a[i] - 48;
    }

    cout << sum << endl;
    return 0;
}