#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<int> v(T);
    for(int i = 0; i < T; i++){
        cin >> v[i];
    }

    vector<int> cv(v);
    sort(cv.begin(), cv.end());

    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    // unique를 통해 중복 값을 제거한다.

    for(int i = 0; i < T; i++){
        // i번째 요소값의 위치 it
        // 이걸 이렇게 뽑을 수 있는 줄은 몰랐네....
        auto it = lower_bound(cv.begin(), cv.end(), v[i]);

        cout << it - cv.begin() << ' ';
    }
}