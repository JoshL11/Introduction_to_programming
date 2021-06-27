#include <cstring>
#include "11417.function.h"
#include <iostream>

Str::Str(const Str &a){
    Char *newcur = a.head;
    head = new Char(newcur->text);
    Char *newcurr = head;
    while(newcur->next){
        newcur = newcur->next;
        newcurr->next = new Char(newcur->text);
        newcurr = newcurr->next;
    }
    tail = newcurr;
}


Str::Str(char *a){
    Char *curr;
    head = new Char(a[0]);
    curr = head;
    int i=1;
    while(a[i] != '\0'){
        curr->next = new Char(a[i]);
        curr = curr->next;
        i++;
    }
    tail = curr;
    
}

Str& Str::strInsert(const Str &b){
    Char *newchar = b.head;
    Char *newcur = tail;
    
    while(newchar){
        newcur->next = new Char(newchar->text);
        newcur = newcur->next;
        newchar = newchar->next;
    }

            tail = newcur;
			return *this;

}