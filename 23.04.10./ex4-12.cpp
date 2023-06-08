#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Array {
    T *buf;
    int size;
    int capacity;
public:
    explicit Array(int cap = 100):buf(0), size(0), capacity(cap){
        buf = new T[capacity];
    }

    ~Array() { delete[] buf; }

    void Add(T data) {
        buf[size++] = data;
    }

    T operator[] (int idx) const {
        return buf[idx];
    }

    int Getsize() const { return size;}
};

int main() {
    Array<int> iarr; // 정수 (클라이언트가 T 타입 결정) Array 객체
    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);

    for(int i = 0; i < iarr.Getsize(); ++i)
        cout << iarr[i] << " ";
    cout << endl;

    Array<double> darr; // 실수 (클라이언트가 T 타입 결정) Array 객체
    darr.Add(1.1);
    darr.Add(2.2);
    darr.Add(3.3);

    for(int i = 0; i < darr.Getsize(); ++i)
        cout << darr[i] << " ";
    cout << endl;

    Array<string> sarr; // 문자열 (클라이언트가 T 타입 결정) Array 객체
    sarr.Add("ABC");
    sarr.Add("DEF");
    sarr.Add("GHI");

    for(int i = 0; i < sarr.Getsize(); ++i)
        cout << sarr[i] << " ";
    cout << endl;

    return 0;
}