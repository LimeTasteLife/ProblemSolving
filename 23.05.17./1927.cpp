#include <iostream>
#include <queue>

using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T;

    int num;
    for(int i = 0; i < T; i++){
        cin >> num;
        if(num == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            pq.push(num);
        }
    }
}
