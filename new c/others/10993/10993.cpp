#include<iostream>
#include"10993.function.h"
using namespace std;
#define MAX(a,b) a>b?a:b
/*
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
    */
Polynomial::Polynomial(){
    for(int i=0;i<=101;i++){
        coefficients[i] = 0;
    }
    greatestPower = 0;
}
Polynomial::Polynomial(const int a,const int coef[51]){
    for(int i = a+1;i<=101;i++){
        coefficients[i] = 0;
    }
    for(int i=a;i>=0;i--){
        coefficients[i] = coef[i];
    }
    greatestPower = a;
}
Polynomial Polynomial::add(const Polynomial b) const {
    int n;
    n = MAX(greatestPower,b.greatestPower);
    Polynomial copy1;
    copy1.greatestPower = n;
    for(int i=n;i>=0;i--){
        copy1.coefficients[i] = coefficients[i] + b.coefficients[i];
    }
    return copy1;
} // add function
Polynomial Polynomial::subtract(const Polynomial b) const {
    int n;
    n = MAX(greatestPower,b.greatestPower);
    Polynomial copy1;
    copy1.greatestPower = n;
    for(int i=n;i>=0;i--){
        copy1.coefficients[i] = coefficients[i] - b.coefficients[i];
    }
    return copy1;
}
Polynomial Polynomial::multiplication(const Polynomial b) const {
    int n;
    n = MAX(greatestPower,b.greatestPower);
    Polynomial copy1;
    copy1.greatestPower = greatestPower + b.greatestPower;
    for(int i=greatestPower;i>=0;i--){
        for(int j = b.greatestPower;j>=0;j--){
            int q = i+j;
            copy1.coefficients[q] +=   coefficients[i] * b.coefficients[j];
        }
    }
    return copy1;
}

 void Polynomial::output() const{
     for(int i = greatestPower;i>=0;i--){
         if(i != 0)
            cout << coefficients[i] << " ";
            else
            cout << coefficients[i] ;
     }
}