#include<iostream>

using namespace std;


/*  При розв’язуванні задач використати динамічну структуру бінарного дерева пошуку.
14. Знайти крайній правий листок непорожнього дерева Т.*/

struct Tree
{
    int data;
    Tree *left, *right;

    /*
    // геніальний метод ініціалізацї
    Tree(int value){
        data = value;
        left = right = NULL;
    }
    */
};



void addLeftBranch(Tree *& T, int inf){
    Tree *Branch = new Tree;
    Branch->data = inf;
    Branch->left=NULL; Branch->right=NULL;
    if(!T)
        T = Branch;
    else{
        Tree *qT = T;
        while(qT->left)
            qT = qT->left;
        qT->left = Branch;
    }
}

int main(){

    Tree *T = NULL;

    addLeftBranch(T, 3);
    addLeftBranch(T, 14);
    addLeftBranch(T, 88);



    Tree *zxc = T;
    while (zxc)
    {
        cout << zxc->data << endl;
        zxc = zxc->left;
    }
    



    return 0;
}