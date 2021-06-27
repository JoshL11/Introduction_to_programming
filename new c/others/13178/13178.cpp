
#include <iostream>
#include <cstring>
#include "13178.h"
Node::~Node(){
    Node *bye;
    if(neighbors[0]) bye = neighbors[0];
    else bye = neighbors[1];
    if(bye){
        bye->unLink(this);
    }
    delete bye;
}

void List::init(std::string s){
    head = new Node(s[0]);
    Node *a = head;
    for(int i=1;i<s.size();i++){
        Node *newcur = new Node(s[i]);
        a->link(newcur);
        newcur->link(a);
        a=newcur;
    }
    tail = a;
    
}

void List::merge(List &front, List &back){
    if(front.tail == nullptr)head = back.head,tail = back.tail;
    else if(back.tail == nullptr)head = front.head,tail = front.tail;
    else{
        front.tail->link(back.head);
        back.head->link(front.tail);
        head = front.head;
        tail = back.tail;
    }
}


void List::swap(List &swapList){
    Node *cur = head,*curr = tail;
    head = swapList.head;
    tail = swapList.tail;
    swapList.head = cur;
    swapList.tail = curr;
}

void List::reverse(){
    Node *tmp = head;
    head = tail;
    tail = tmp;
    
}
List::~List(){
    if(head)
        delete head;
}