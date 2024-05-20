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
    List* link;
};


void addToEnd(List *& Head, int inf){
    List *p = new List;
    p->inf = inf;
    p->link = NULL;
    if(!Head){
        Head = p;
    } else{
        List *TmpHead = Head;
        while(TmpHead->link){
            TmpHead = TmpHead->link;
        } 
        TmpHead->link = p;
    }

}

List *findLast(List * node){
    while(node->link)
        node = node->link;
    return node;
}

void printList(List * Head){
    while(Head){
        cout << Head->inf << " ";
        Head = Head->link;
    }
    cout << endl;
}

void addInPos(List *& Head, int pos, int inf){
    List *p = new List;
    if(pos == 0){
        p->inf = inf;
        p->link = Head;
        Head = p;
    } else if(pos == 1){
        p->inf = inf;
        p->link = Head->link;
        Head->link = p;
    } else{
        p->inf = inf;
        List *p0 = Head;
        for(int i = 0; i < pos -1 && p0; i++){
            p0 = p0->link;
        }
        if(p0){
            p->link = p0->link;
            p0->link = p;
        } else
            cout << "pos error! p0==NULL!\n";
    }
}


// 5.a
bool isSorted12(List*head){
    if (!head) return 0;
    int next;
    List *p = head;
    while (head){
        if(head->link){
            p = head->link;
            next = p->inf;
            if (head->inf > next){
                return 0;
            }
        }
        head = head->link;
    }
    return 1;
}

// 5.b
void addAsSecond(List *& Head, int inf){
    List *p = new List;
    p->inf = inf;
    p->link = Head->link;
    Head->link = p;

}

// 5->v   вставляє новий елемент Е1 за кожним входженням елемента Е
void addE1afterE(List *& Head, int E1, int E){
    for(List *pi = Head; pi; pi = pi->link){
        if (pi->inf == E){
            List *p = new List;
            p->inf = E1;
            p->link = pi->link;
            pi->link = p;
        }
    }


}

int main(){

    List *Head = NULL; // створили поводок щоб не загубить список

    for(int i = 0; i < 13; i++){
        addToEnd(Head, i);
    }
    
    // addInPos(Head, 4, 11);
    printList(Head);
    cout << "is sorted by growth?\n";
    if (isSorted12(Head)) cout << "yes\n\n";
    else cout << "no\n\n";

    addAsSecond(Head, 11);
    printList(Head); cout << endl;

    addE1afterE(Head, 66, 11);
    printList(Head); cout << endl;

    
    



    
    // deletin
    while(Head){
        List *pD = Head;
        Head = Head->link;
        delete pD;
    }
    
    return 0;
}
