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
    
    int N, K;
    cin >> N >> K;

    vector<int> vec;
    for(int i = 1; i <= N; i++){
        vec.push_back(i);
    }

    
    int idx = 0;
    int num = N-1;
    cout << "<";
    while(num--){
        idx = (idx + (K-1)) % vec.size();
        cout << vec[idx] << ", ";
        vec.erase(vec.begin() + idx);
    }
    cout << vec.front() << ">" << endl;

    return 0;
}