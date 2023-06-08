#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const vector<int>& a, const vector<int>& b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int main() {
    int T;
    cin >> T;
    vector<vector<int>> arr(T, vector<int>(2, 0));
    for(int i = 0; i < T; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    sort(arr.begin(), arr.end(), compare);
    for(int i = 0; i < T; i++){
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    return 0;
}