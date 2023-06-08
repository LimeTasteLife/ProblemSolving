#include <iostream>
using namespace std;

template<typename T, int size>
void PrintArray(T* arr) {
    for(int i = 0; i < size; ++i)
        cout << "[" << i << "]: " << arr[i] << endl;
    cout << endl;
}

int main() {
    int arr1[5] = { 10, 20, 30, 40, 50 };
    PrintArray<int, 5>(arr1);
    // 명시적 호출

    double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    PrintArray<double, 5>(arr);
    // 명시적 호출

    return 0;
}