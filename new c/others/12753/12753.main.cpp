#include <iostream>
#include "12753.h"
#include "12753.cpp"
using namespace std;

int main()
{
    int n; cin >> n;
    // initialize health condition
    BigInt hi, kaminari, kedamono;
    cin >> hi; kaminari = kedamono = hi;
    // go on mission
    solution(hi, kaminari, kedamono, n);
    // output result
    cout << hi << endl;
    cout << kaminari << endl;
    cout << kedamono << endl;
}
