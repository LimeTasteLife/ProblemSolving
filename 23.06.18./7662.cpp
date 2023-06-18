#include <iostream>
#include <set>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        char order;
        int num;
        multiset<int> ms;

        cin >> N;
        while(N--){
            cin >> order >> num;
            if(order == 'I'){
                ms.insert(num);
            }else{
                if(!ms.empty() && num == -1){
                    ms.erase(ms.begin());
                }else if(!ms.empty() && num == 1){
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }

        if(ms.empty()){
            cout << "EMPTY" << '\n';
        }else{
            auto iter = ms.end();
            iter--;
            cout << *iter << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}