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
    }cout << endl;
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

void addListAfterPos(DuoList *&head1,DuoList*head2, int pos){
    if(pos < 0){
        DuoList *q1 = head1;
        head1 = head2;
        while(head2->next)
            head2 = head2->next;
        head2->next = q1;
        q1->prev = head2;
    } else{
        int i = 0;
        while(i != pos && head1){
            i++;
            head1=head1->next;
        }
        DuoList *q1 = head1->next;
        head1->next = head2;
        head2->prev = head1;
        while(head2->next)
            head2 = head2->next;
        head2->next = q1;
        if(q1)
            q1->prev = head2;
    }
}

void replaceGwithQ(DuoList *& P, DuoList *g, DuoList *q){
    DuoList *qP = P;
    int pos = 0;
    bool isDone = false;
    while(qP->next && !isDone){
        DuoList *qG = g;
        while(qG && !isDone){
            if(qP->inf == qG->inf){
                addListAfterPos(P, q, pos);
                isDone = true;
            }
            qG = qG->next;
        }
        pos++;
        qP = qP->next;
    }

} 
/* v29 - 24 = 5
   5. Написати програму з функціями, яка:
а) у списку Р замінює перше входження списку G (якщо таке є) на списокQ;
б) будує список Q – копію списку Р;
в) додає до кінця списку Р інвертований список Р.   */

int main(){
    srand(time(NULL));



    DuoList *P=NULL, *G=NULL, *Q=NULL;

    for(int i = 0; i < 10; i++){
        int j = rand() % 10;
        addInEnd(P, j);
    }cout << "P list: ";
    printList(P);

    for(int i = 0; i < 10; i++){
        int j = rand() % 10;
        addInEnd(G, j);
    }cout << "G list: ";
    printList(G);

    for(int i = 0; i < 10; i++){
        int j = rand() % 10;
        addInEnd(Q, j);
    }cout << "Q list: ";
    printList(Q);


    replaceGwithQ(P,G,Q); // пофіксить пройоб Phead і вирізать зайвий вузол
    printList(P);
    printListRevers(P);


    return 0;
}
