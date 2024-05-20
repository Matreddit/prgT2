#include<iostream>

using namespace std;
// v29 - 24 = 5
/*
Написати програму з функціями, яка:
а) перевіряє, чи впорядковано елементи списку Р за зростанням; б)
вставляє до списку Р новий елемент після першого елемента списку; в)
вставляє новий елемент Е1 за кожним входженням елемента Е.
*/

struct List
{
    int inf;
    List* next;
};


int main(){

    List *Head = NULL, *Tail = NULL;

    List *p = new List;
    p->inf = 3;
    p->next = NULL;

    Head = p;
    Tail = p;

    delete p;

    

    
    
    
    return 0;
}