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


// 5.a
bool doesSorted12(List*head){
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

int main(){

    List *Head = NULL; // створили поводок щоб не загубить список

    for(int i = 0; i < 50; i++){
        addToEnd(Head, i);
    }
    addToEnd(Head, 333);
    
    List *p = Head->link;
    p = p->link;
    p = p->link;
    p->inf = 997;

    printList(Head);

    cout << "\n";
    if(doesSorted12(Head)) cout << "true\n";
    else cout << "false\n";

    // b
    addAsSecond(Head, 18);
    printList(Head);

    
    // deletin
    while(Head){
        List *pD = Head;
        Head = Head->link;
        delete pD;
    }
    
    return 0;
}
