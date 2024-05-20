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

}

int main(){

    List *Head = NULL; // створили поводок щоб не загубить список

    for(int i = 0; i < 50; i++){
        addToEnd(Head, i);
    }
    

    printList(Head);

    cout << "\n\n\n";
    if(doesSorted12(Head)) cout << "true\n";
    else cout << "false\n";


    
    // deletin
    while(Head){
        List *pD = Head;
        Head = Head->link;
        delete pD;
    }
    
    return 0;
}
