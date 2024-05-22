#include<iostream>

using namespace std;
/* v29 - 24 = 5
   5. Написати програму з функціями, яка:
а) у списку Р замінює перше входження списку G (якщо таке є) на списокQ;
б) будує список Q – копію списку Р;
в) додає до кінця списку Р інвертований список Р.   */

struct DuoList
{
    int inf;
    DuoList *prev, *next;
};


void addInEnd (DuoList *& Head, int inf){
    DuoList *q = new DuoList;
    q->inf = inf;
    q->next = NULL;
    if(Head){
        DuoList *Tail = Head;
        while(Tail->next)
            Tail = Tail->next;
        q->prev = Tail;
        Tail->next = q;
    } else{
        q->prev = NULL;
        Head = q;
    }
}

void addInBeg(DuoList *& Head, int inf){
    DuoList *q = new DuoList;
    q->inf = inf;
    q->prev = NULL;
    if(!Head){
        q->next = NULL;
        Head = q;
    } else{
        q->next = Head;
        Head->prev = q;
        Head = q;
    }
}

void printList(DuoList *Head){
    while(Head){
        cout << Head->inf << " ";
        Head = Head->next;
    }
    cout << endl;
}


int main(){
    

    DuoList *Head = NULL;
    for(int i = 0; i < 20; i++)
        addInBeg(Head, i);


    printList(Head);


    for(int i = 0; i < 20; i++)
        addInEnd(Head, i);

    printList(Head);


    return 0;
}
