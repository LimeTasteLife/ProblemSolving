#include <iostream>
using namespace std;

int minn;

void f(int num, int cal, int cnt){
    // 1,2,3인지 확인.
    if(num == 1 && cal == -1){
        minn = 0;
        return;
    }else if((num == 2 || num ==3) && cal == -1){
        minn = 1;
        return;
    }

    // 초기 계산인지 확인.
    if(cal == -1){
        f(num/3, num%3, cnt+1);
        f(num/2, num%2, cnt+1);
        f(num-1, 0, cnt+1);
    }else if(cal == 0){
        if(num == 2 || num == 3){
            if(cnt+1 < minn){
                minn = cnt+1;
            }
        }else{
            f(num/3, num%3, cnt+1);
            f(num/2, num%2, cnt+1);
            f(num-1, 0, cnt+1);
        }
    }
    return;
}

int f1(int num, int cal, int cnt){
    if(num == 1){
        if(cnt < minn){
            minn = cnt;
        }
        return 0;
    }else if((num == 2 || num == 3)&& cal == -1){
        minn = 1;
        return 0;
    }else if(cal == -1){
        return f1(num/3, num%3, cnt+1) + f1(num/2, num%2, cnt+1) + f1(num-1, num-1, cnt+1);
    }else if(cal == 0){
        return f1(num/3, num%3, cnt+1) + f1(num/2, num%2, cnt+1) + f1(num-1, num-1, cnt+1);
    }
    return 0;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        minn = 1000001;
        int N;
        cin >> N;
        f(N, -1, 0);
        cout << minn << endl;
    }
    
    return 0;
}