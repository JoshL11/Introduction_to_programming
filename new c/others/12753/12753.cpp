#include <iostream>
#include "12753.h"
#include <iomanip>
#include <cstring>

BigInt::BigInt(){
    sign = false;
    for(int i=0;i<N;i++){
        bigInt[i] = 0;
    }
}

BigInt::BigInt(char* str){
    int end = 0, sz = 0;
    sign = false;
    for (int i = strlen(str) - 1; i >= end; i -= 8) {
        int num = 0;
        for (int j = 7; j >= 0; j--) {
            if (i-j < end) continue;
            num = num * 10 + (str[i-j] - '0');
        }
        bigInt[sz] = num;
        sz++;
    }
    for (int i = sz; i < N; i++) bigInt[i] = 0;
}

BigInt::BigInt(const BigInt& a){
    sign =a.sign;
    for(int i=0;i<N;i++){
        bigInt[i] = a.bigInt[i];
    }
}

BigInt& BigInt::operator = (const BigInt& a){
    sign = a.sign;
    for (int i = 0; i < N; i++) bigInt[i] = a.bigInt[i];
    return *this;
}

bool BigInt::operator < (BigInt a){
    if(sign == 1&& a.sign == 0)return true;
    else if(sign == 0&& a.sign == 1)return false;
    else if(sign == 1&& a.sign == 1){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return true;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return false;
                break;
            }
        }
        return false;
    }
    else if(sign == 0&& a.sign == 0){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return false;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return true;
                break;
            }
        }
        return false;
    }
}

bool BigInt::operator > (BigInt a){
    if(sign == 1&& a.sign == 0)return false;
    else if(sign == 0&& a.sign == 1)return true;
    else if(sign == 1&& a.sign == 1){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return false;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return true;
                break;
            }
        }
        return false;
    }
    else if(sign == 0&& a.sign == 0){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return true;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return false;
                break;
            }
        }
        return false;
    }
}

bool BigInt::operator == (BigInt a){
    if(sign == 1&& a.sign == 0)return false;
    else if(sign == 0&& a.sign == 1)return false;
    else if(sign == 1&& a.sign == 1){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return false;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return false;
                break;
            }
        }
        return true;
    }
    else if(sign == 0&& a.sign == 0){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return false;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return false;
                break;
            }
        }
        return true;
    }
}

bool BigInt::operator >= (BigInt a){
    if(sign == 1&& a.sign == 0)return false;
    else if(sign == 0&& a.sign == 1)return true;
    else if(sign == 1&& a.sign == 1){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return false;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return true;
                break;
            }
        }
        return true;
    }
    else if(sign == 0&& a.sign == 0){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return true;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return false;
                break;
            }
        }
        return true;
    }
}

bool  BigInt::operator <= (BigInt a){
    if(sign == 1&& a.sign == 0)return true;
    else if(sign == 0&& a.sign == 1)return false;
    else if(sign == 1&& a.sign == 1){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return true;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return false;
                break;
            }
        }
        return true;
    }
    else if(sign == 0&& a.sign == 0){
        for(int i=N-1;i>=0;i--){
            if(bigInt[i] > a.bigInt[i]){
                return false;
                break;
            }
            else if(bigInt[i] < a.bigInt[i]){
                return true;
                break;
            }
        }
        return true;
    }
}

/*BigInt operator + (BigInt);
    BigInt operator - (BigInt);
    // insertion & extraction operator
    friend istream& operator >> (istream&, BigInt&);
    friend ostream& operator << (ostream&, BigInt&);*/


BigInt BigInt::operator + (BigInt b) {
    BigInt res;
    //res.sign = b.sign;
    for(int i=0;i<N;i++){
        res.bigInt[i] += bigInt[i] + b.bigInt[i];
        if(res.bigInt[i] >= BASE){
            res.bigInt[i+1] += res.bigInt[i] / BASE;
            res.bigInt[i] %= BASE;
        } 
    }
    return res;
}

BigInt BigInt::operator - (BigInt b) {
    BigInt res;
    // deal with the result of subtract to avoid negative result
    if((*this).sign){
        res = (*this) + b;
        res.sign = true;
    } else {
        if((*this) >= b){
            for(int i=0;i<N;i++){
                res.bigInt[i] += bigInt[i] - b.bigInt[i];
                if(res.bigInt[i] < 0){
                    res.bigInt[i+1]--;
                    res.bigInt[i]+=BASE;
                }
            }   
        } else {
            for(int i=0;i<N;i++){
                res.bigInt[i] += b.bigInt[i] - bigInt[i];
                if(res.bigInt[i] < 0){
                    res.bigInt[i+1]--;
                    res.bigInt[i]+=BASE;
                }
            }
            res.sign = true;
        }
    }
    return res;
}
 
   
      
    
istream& operator >> (istream &is, BigInt &b) {
    char str[b.N*8+5];
    is >> str;
    b = str;
    return is;
}

ostream& operator << (ostream &os, BigInt &b) {
   int i = b.N-1;
   if(b.sign)os << '-';
   while(i>=0 && b.bigInt[i]==0)i--;
   if(i==-1)os << '0';
   else os << b.bigInt[i];
   i--;
   for(;i>=0;i--){
       os << setw(8) << setfill('0') << b.bigInt[i];
   }
   return os;
}

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n) {
    while (n--) {
        BigInt a;
        cin >> a;
        if(inosuke >= tanjiro && inosuke >= zenitsu)inosuke = inosuke - a;
        else if(tanjiro >= inosuke && tanjiro >= zenitsu)tanjiro = tanjiro - a;
        else if(zenitsu >= inosuke && zenitsu >= tanjiro)zenitsu = zenitsu - a;
    }
}