#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "12224.h"

void List::InsertHead(int data){
    ListNode *newnode = new ListNode(data);
    
    if(head){
        head->prev = newnode;
        head->prev->next = head;
        head=head->prev;
        cnt++;
        if(cnt % 2 ==1 &&cnt !=1&&middle)middle = middle->prev; 
    } else {
        head = newnode;
        tail = head;
        middle = tail;
        cnt++;
    }
    
}
int List::RemoveHead(){
    int a;
    if(head){
        ListNode *bye = head;
        a = bye->data; 
        if(head->next){
            head = head->next;
            head->prev = nullptr;
        }
        else {
            head = nullptr;
            tail = nullptr;
        }
        
        cnt--;
        if(cnt%2==0)middle=middle->next;
        delete bye;
        return a;
    } else throw std::out_of_range("\n");
    
}
void List::InsertTail(int data){
    ListNode *newnode = new ListNode(data);
    if(tail){
        tail->next = newnode;
        tail->next->prev = tail;
        tail = tail->next;
        cnt++;
        if(cnt % 2 ==0&&middle)middle = middle->next; 
    } else {
        head = newnode;
        tail = head;
        middle = tail;
        cnt++;
    }
    
   
}
int List::RemoveTail(){
    int a;
    if(tail){
        ListNode *bye = tail;
        a = bye->data; 
        if(tail->prev){
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
        }
        delete bye;
        cnt--;
        if(cnt%2)middle=middle->prev;
        return a;
        
    } else throw std::out_of_range("\n");
    
}
void List::Swap(){
    if(cnt <=1) return;
    tail->next = head;
    head->prev = tail;
    tail = middle->prev;
    swap(middle,head);
    if(cnt%2){
        middle = middle->prev;
    }
    head->prev = nullptr,tail->next = nullptr;   
}
int List::getSize(){
    return cnt;
}
int List::getMiddle(){
    return pos;
}