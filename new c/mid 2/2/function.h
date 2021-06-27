
#include <cstddef>
#include <iostream>
class _node{
    public:
    int data;
    _node* next,*prev;
    _node(int d=0){data = d; next=prev=NULL;}
};
class _dequeue{
    protected:
    _node* Begin,*End;

    public:
    _dequeue(){
        Begin = new _node(0);
        End = new _node(0);
        Begin->next=End;
        End->prev=Begin;
    }
    bool Empty(){
        if(Begin==NULL || Begin->next==End) return true;
        return false;
    }
    virtual void push(const _node) = 0;
    virtual void pop() = 0;
    virtual _node* get_data() = 0;
};

class _stack : public _dequeue{
    public:
    _stack():_dequeue(){}
    void push(const _node N){
        _node *a = new _node(N);
        a->prev = End->prev;
        a->prev->next = a;
        a->next = End;
        End->prev = a;
    }
    void pop(){
        if(End->prev == Begin)return;
        _node *bye = End->prev;
        if(End->prev->prev!=Begin)End->prev = End->prev->prev;
        else End->prev = Begin;
        End->prev->next = End;
        delete bye;

    }
    _node* get_data(){
        if(End->prev != Begin){
        _node* a = End->prev;
        return a;
        } else return NULL;
    }

};
class _queue : public _dequeue{
    public:
    _queue():_dequeue(){}
    void push(const _node N){
        _node *a = new _node(N);
        a->prev = End->prev;
        a->prev->next = a;
        a->next = End;
        End->prev = a;
    }
    void pop(){
        if(End->prev == Begin)return;
        _node *bye = Begin->next;
        if(Begin->next->next != End)Begin->next = Begin->next->next;
        else Begin->next = End;
        Begin->next->prev = Begin;  
        delete bye;
    }
    _node* get_data(){
        if(End->prev != Begin){
            _node* a = Begin->next;
            return a;
        } else return NULL;
    }

};
