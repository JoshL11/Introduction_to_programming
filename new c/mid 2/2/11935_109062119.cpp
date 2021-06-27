#include "function.h"
#include <iostream>
using namespace std;


void _stack::push(const _node N){
    _node *a = new _node(N);
    a->prev = End->prev;
    a->prev->next = a;
    a->next = End;
    End->prev = a;
}
void _stack::pop(){
    if(End->prev == Begin)return;
    _node *bye = End->prev;
    if(End->prev->prev!=Begin)End->prev = End->prev->prev;
    else End->prev = Begin;
    End->prev->next = End;
    delete bye;
}
_node*_stack::get_data(){
    if(End->prev != Begin){
        _node* a = End->prev;
        return a;
    } else return NULL;
}
void _queue::push(const _node N){
    _node *a = new _node(N);
    a->prev = End->prev;
    a->prev->next = a;
    a->next = End;
    End->prev = a;
}
void _queue::pop(){
    if(End->prev == Begin)return;
    _node *bye = Begin->next;
    Begin->next = Begin->next->next;
    Begin->next->prev = Begin;
    delete bye;
}
_node*_queue::get_data(){
    if(End->prev != Begin){
        _node* a = Begin->next;
        return a;
    } else return NULL;
}