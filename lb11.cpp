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
void printListRevers(DuoList*Head){
    while(Head->next)
        Head = Head->next;
    while(Head){
        cout << Head->inf << " ";
        Head = Head->prev;
    } cout << endl;
}

void deleteList(DuoList *& Head){
    while (Head){
        DuoList *q = Head;
        Head = Head->next;
        delete q;
    }
}

// у списку Р замінює перше входження списку G (якщо таке є) на списокQ;
void inPfindGwithQ(DuoList *& P, DuoList *G, DuoList *Q){
    DuoList *qP = P;
    DuoList *qG = G;
    DuoList *qQ = Q;

    bool isFound = false;
    while(qP->next && !isFound){
        qG = G;
        while (qG->next && !isFound)
        {
            if(qP->inf == qG->inf)
                isFound = true;
            qG = qG->next;
        }
        qP = qP->next;
    }
    cout << qP->inf << endl;

    DuoList *qDel = qP;
    qP = qP->prev;
    qDel->prev->next = qDel->next;
    qDel->next->prev = qDel->prev;
    delete qDel;

    DuoList *qP_Next = qP->next;
    qP->next = Q;
    Q->prev = qP;
    while(qQ->next)
        qQ = qQ->next;
    qQ->next = qP_Next;
    qP_Next->prev = qQ;
    
}

void makeCopyOfP(DuoList *& Q, DuoList *P){
    
}
/* v29 - 24 = 5
   5. Написати програму з функціями, яка:
а) у списку Р замінює перше входження списку G (якщо таке є) на списокQ;
б) будує список Q – копію списку Р;
в) додає до кінця списку Р інвертований список Р.   */

int main(){
    srand(time(NULL));

    DuoList *P=NULL, *G=NULL, *Q=NULL;

    for(int i = 0; i < 5; i++){
        addInEnd(P, i);
    }for(int i = 4; i >= 0; i--){
        addInEnd(G, i);
    }for(int i = 0; i < 5; i++){
        addInEnd(Q, 9);
    }
    cout << "P, G, Q :\n";
    printList(P);
    printList(G);
    printList(Q);

    cout << "\n5.a:\n";
    inPfindGwithQ(P,G,Q);

    cout << "P, G, Q :\n";
    printList(P);
    printList(G);
    printList(Q);


    return 0;
}
