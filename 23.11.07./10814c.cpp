#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b)
{
    return a.first < b.first;
}
int main() {
    int num;
    cin >> num;
    pair<int,string> tmp;
    vector<pair<int,string>> arr;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    stable_sort(arr.begin(),arr.end(),compare);
    for(int i = 0; i < num; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}

/*

 * 왜 이 코드는 시간초과가 될까?

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    pair<int, string> arr[T];

    for(int i = 0; i < T; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    stable_sort(arr, arr + T, compare);
    // sort할 때, 첫번째 인자만 비교해서 두 번째 인자인 이름은 들어온 순서대로 출력하게 한다. 

    for(int i = 0; i < T; i++){
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }

    return 0;
}

*/