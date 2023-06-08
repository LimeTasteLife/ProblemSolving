#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int a[T];

    int min = 1000000;
    int max = -1000001;

    for(int i = 0; i < T; i++)
        cin >> a[i];

    for(int i = 0; i < T; i++){
        if(min > a[i]) min = a[i];
        if(max < a[i]) max = a[i];
    }

    cout << min << " " << max << endl;

    return 0;
}

/*
 * 이거는 일일히 확인하는 방법인데, sort로 푸는 방법도 있다.
 * 
*/