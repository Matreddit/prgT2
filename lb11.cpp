#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

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

void deleteList(DuoList *& Head){
    while (Head){
        DuoList *q = Head;
        Head = Head->next;
        delete q;
    }
}
/* v29 - 24 = 5
   5. Написати програму з функціями, яка:
а) у списку Р замінює перше входження списку G (якщо таке є) на списокQ;
б) будує список Q – копію списку Р;
в) додає до кінця списку Р інвертований список Р.   */

int main(){
    srand(time(NULL));



    DuoList *P=NULL, *D=NULL, *Q=NULL;

    for(int i = 0; i < 10; i++){
        int j = rand() % 10;
        addInEnd(P, j);
    }
    cout << "P list: ";
    printList(P);
    for(int i = 0; i < 10; i++){
        int j = rand() % 10;
        addInEnd(P, j);
    }
    cout << "P list: ";
    printList(P);


    return 0;
}
