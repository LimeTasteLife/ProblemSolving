#include <iostream>
#include <string>

using namespace std;

int checkPainting(string board[8]){
    int result1 = 0;
    int result2 = 0;

    for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
            if((i+j) % 2 == 0){
                if(board[i][j] != 'W') result1++;
                if(board[i][j] != 'B') result2++;
            }else{
                if(board[i][j] != 'B') result1++;
                if(board[i][j] != 'W') result2++;
            }
        }
    }

    if(result1 < result2){
        return result1;
    }else{
        return result2;
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    string a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    string board[8];
    int min = 2501;
    for(int i = 0; i < N-7; i++){
        for(int j = 0; j < M-7; j++){
            /* 보드 복사 */
            for(int k = 0; k < 8; k++){
                string subs = a[k+i].substr(j, 8);
                board[k].assign(subs);
            }
            /*
             * 보드 잘 나오는지 확인.
            for(int k = 0; k < 8; k++){
                cout << board[k] << endl;
            }
            cout << "=====" << endl;
            */
            int fres = checkPainting(board);
            if(fres < min) min = fres;
        }
    }

    cout << min << endl;

    return 0;
}