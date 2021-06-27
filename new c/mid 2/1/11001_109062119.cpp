#include "function.h"
#include <iostream>
using namespace std;

std::ostream &operator<<(std::ostream & os, const Polynomial & a){
    for(int i = a.greatestPower;i>=0;i--){
        if(i!=0)cout << a.coefficients[i]<<" ";
        else cout << a.coefficients[i];
    }
}
Polynomial::Polynomial(const int & a, const int b[51]){
    for(int i = a+1;i<101;i++){
        coefficients[i] = 0;
    }
    for(int i=a;i>=0;i--){
        coefficients[i] = b[i];
    }
    greatestPower = a;
}
Polynomial Polynomial ::operator+( const Polynomial & a) const{
    int n = (greatestPower>a.greatestPower)?greatestPower:a.greatestPower;
    Polynomial re;
    re.greatestPower = n;
    for(int i = n;i>=0;i--){
        re.coefficients[i] = coefficients[i] + a.coefficients[i];
    }
    return re;
}
Polynomial Polynomial ::operator-( const Polynomial & a) const{
    
    int n;
    n = (greatestPower>a.greatestPower)?greatestPower:a.greatestPower;
    Polynomial copy1;
    copy1.greatestPower = n;
    for(int i=n;i>=0;i--){
        copy1.coefficients[i] = coefficients[i] - a.coefficients[i];
    }
    return copy1;


}