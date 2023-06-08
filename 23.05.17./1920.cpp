#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a+N);

    int M;
    cin >> M;
    int b[M];
    for(int i = 0; i < M; i++)
        cin >> b[i];

    int ans = 0;
    for(int i = 0; i < M; i++){
        bool found = binary_search(a, a+N, b[i]);
        if(found == true){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    
    return 0;
}