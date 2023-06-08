#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> st;

int stackF(string& s){
    int result = -2;

    if(s == "push"){
        int num;
        cin >> num;
        st.push(num);
        result = -2;
    }else if(s == "top"){
        if(st.empty() == true){
            result = -1;
        }else {
            result = st.top();
        }
    }else if(s == "size"){
        result = st.size();
    }else if(s == "empty"){
        if(st.empty() == true){
            result = 1;
        }else {
            result = 0;
        }
    }else if(s == "pop"){
        if(st.empty() == true){
            result = -1;
        }else {
            result = st.top();
            st.pop();
        }
    }
            
    return result;
}

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string s;
        cin >> s;

        int result = stackF(s);
        if( result != -2) cout << result << endl;
    }

    return 0;
}