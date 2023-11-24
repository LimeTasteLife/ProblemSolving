#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.second == )
    return a.second < b.second;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    vector<pair<pair<int ,int>,int>> v;

    int a, b;
    while(T--){
        cin >> a >> b;
        v.push_back(make_pair(make_pair(a,b), b-a));
    }

    sort(v.begin(), v.end(), compare);

    return 0;
}