#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

template <typename T>
void print(T last){
    cout << last << endl;
}

template <typename T, typename ... Args>
void print(T head, Args ... tail){
    cout << head << ", ";
    print(tail...);
}

template <ull N>
struct Factorial 
{
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> 
{
    enum { value = 1 };
};

int main(){
    ull x = Factorial<50>::value;
    cout << x << endl;
}