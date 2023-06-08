#include <iostream>
#include <string>
using namespace std;

// begin은 배열의 시작 주소, end는 배열의 끝 주소,
// pf는 클라이언트 함수 포인터입니다.
template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) {
    while (begin != end) {
        pf(*begin++);
    }
}

template<typename T>
void PrintFunctor (T data) {
    string sep; // 출력 구분자 정보

    explicit PrintFunctor(const string& s=" "):sep(s) {}

    void operator()(T data) const {
        cout << data << sep;
    }
};

int main() {
    int arr[5] = { 10, 20, 30, 40, 50 };
    // 컴파일러는 템플릿 인자를 추론할 수 없으므로 명시적으로 표현.
    For_each(arr, arr+5, PrintFunctor<int>()); // 정수 출력
    // 아래는 명시적 호출 버전
    // For_each<int*, void(*)(int)>(arr, arr+5, PrintInt);
    cout << endl;

    string str[5] = { "Hello", "C++", "World", "Good", "Morning" };
    For_each(str, str+5, PrintFunctor<string>("*\n")); // 문자열 출력
    // 아래는 명시적 호출 버전
    // For_each(string*, void(*)(string)>(str, str+5, PrintString))
    cout << endl;

    return 0;
}

/**
 * 컴파일러는 코드를 보고 For_each() 함수 템플릿의 두 인스턴스를 만듬.
 * For_each<int*, void(*)(int)> 와 For_each<string*, void(*)(string)>.
*/