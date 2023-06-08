#include <iostream>
using namespace std;

template<typename T>
void Swap(T& a, T& b) {
    T Temp = a;
    a = b;
    b = Temp;
}

template<typename T>
void Print(K a, K b){
    cout << a << ", " << b << endl;
}

int main() {
    int n1 = 10, n2 = 20;
    double d1 = 10.5, n2 = 2.8;

    Print(n1, n2);
    Swap(n1, n2);
    Print(n1, n2);
    cout << endl;

    Print(d1, d2);
    Swap(d1, d2);
    Print(d1, d2);
    cout << endl;

    return 0;
}