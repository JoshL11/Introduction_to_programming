#include "function.h"
#include <iostream>
void Array::move(int n) {
    cur+=n;
        if(cur <= 0) {
            cur = 1;
        } else if(cur > size) {
            cur = size;
        }
}

void Array::remove() {
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

void Array::reverse() {
    int *t = new int[size + 2];
    for(int i=size;i>=1;i--){
        t[i] = mem[i];
    }
    int j=1;
    //std::cout <<size;
    for(int i=size;i>=1;i--){
        mem[i] = t[j];
        j++;
    }
    
    cur = size-cur+1;
    if(rev == false)rev = true;
    else if(rev == true)rev = false;
}

void List::move(int n) {
    if(n > 0) {
        while(cur->nxt && n>0) {
            cur = cur->nxt;
            n--;
        }
    } else {
        while(cur->pre && n<0) {
            cur = cur->pre;
            n++;
        }
    }
}

void List::remove() {
    if(cur)cur = cur->remove();
    size--;
}

void List::reverse() {
    Node *current = cur,*temp = NULL,*head;
    while(current->pre){
        current = current->pre;
    }
    //std::cout << current->val;
    head = current;
    while (current != NULL) {
        temp = current->pre;
        current->pre = current->nxt;
        current->nxt = temp;            
        current = current->pre;
    }
    if(temp != NULL){
        head = temp->pre;
    }
    if(rev == false)rev = true;
    else if(rev == true)rev = false;
    //std::cout<<cur->val<<" ";
}

ContainerBase* create(int n, int *arr, int op2Cnt, int op3Cnt) {
    ContainerBase *c;
    if(op2Cnt > op3Cnt) {
        c = new Array(n,arr);
    } else {
        c = new List(n,arr);
    }
    return c;
}