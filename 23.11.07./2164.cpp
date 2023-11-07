#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main(void){
    int N;
    cin >> N;
    queue<int> q;

    for(int i = 1; i <= N; ++i){
        q.push(i);
    }

    while(q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}

/*
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> vec;
    for(int i = 0; i < N; i++){
        vec.push_back(i+1);
    }

    for(int i = 0; i < N-1; i++){
        vec.erase(vec.begin());
        int num = vec.front();
        vec.erase(vec.begin());
        vec.push_back(num);
    }

    cout << vec.front() << endl;

    return 0;
}

처음 코드, vector는 동적배열이다.
따라서 erase(vec.begin())의 시간복잡도가 O(N)이다.

*/