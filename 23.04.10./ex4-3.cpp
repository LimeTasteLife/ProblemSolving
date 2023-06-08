#include <iostream>
using namespace std;

template<typename T1, typename T2>
void Print(T1 a, T2 b) {
    cout << a << ", " << b << endl;
}
int main() {
    Print(10, 20);
    Print(10.5, 20.7);
    Print("ABC", "abcde");

    Print<int>(10, 20);
    Print<double>(10.5, 20.7);
    Print<const char*>("ABC", "abcde");

    return 0;
}