#include <iostream>

#include "function.h"


ContainerBase* create(int n, int* arr, int a, Operation* z) {
    int op2 = 0,op3= 0;
    for(int i=0;i<a;i++) {
        if (z[i].type == 2)op2++;
        else if(z[i].type == 3)op3++;
    }
    ContainerBase *c;
    if(op2 > op3) {
        c = new Array(n,arr);
    }
    else {
        c = new List(n,arr);
    }
    return c;
}



void Array::move(int n) {
        cur+=n;
        if(cur <= 0) {
            cur = 1;
        } else if(cur > size) {
            cur = size;
        }
}
void Array::remove(){
    if(cur == size) {
        size--;
        mem[cur] = 0;
        cur--;
    } else if (cur == 1) {
        for(int i=2;i<=size;i++) {
            mem[i-1] = mem[i];
        }
        size--;
    } else {
        for(int i=cur;i<=size;i++) {
            mem[i] = mem[i+1];
        }
        size--;
    }
}
void List::move(int n){
    if(n > 0) {
        while(cur->getNxt() && n>0) {
            cur = cur->getNxt();
            n--;
        }
    } else {
        while(cur->getPre() && n<0) {
            cur = cur->getPre();
            n++;
        }
    }
}
void List::remove(){
    if(cur)cur = cur->remove();
    size--;
}