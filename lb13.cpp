#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;


/*  При розв’язуванні задач використати динамічну структуру бінарного дерева пошуку.
14. Знайти крайній правий листок непорожнього дерева Т.*/


struct Tree
{
    int data;
    Tree *left, *right;

    
    // геніальний метод ініціалізацї
    Tree(int value){
        data = value;
        left = right = NULL;
    }
    
};


void deleteTree(Tree* &root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    //cout << "Deleting node with value: " << root->data << endl;
    delete root;
    root = NULL;
}


void printTree(Tree* root) {
    if (root == NULL) {
        return;
    }
    //cout << endl;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

void printTreePlus(Tree* root, string indent = "", bool isLeft = true) {
    if (root != NULL) {
        cout << indent;
        if (isLeft) {
            cout << "L---";
            indent += "|   ";
        } else {
            cout << "R---";
            indent += "    ";
        }
        cout << root->data << endl;
        printTreePlus(root->left, indent, true);
        printTreePlus(root->right, indent, false);
    }
}


void PlantTree(Tree *& T) {
    if(T)return;
    srand(time(0));
    T = new Tree(rand() % 10);
    T->right = new Tree(rand() % 10);
    T->left = new Tree(rand() % 10);

    T->right->right = new Tree(rand() % 10);
    T->right->left = new Tree(rand() % 10);

    T->left->left = new Tree(rand() % 10);
    T->left->right = new Tree(rand() % 10);

    T->right->right->left =new Tree(rand() % 10);
    T->right->right->right =new Tree(rand() % 10);
    T->right->left->right =new Tree(rand() % 10);
    T->right->left->left =new Tree(rand() % 10);

    T->left->left->right =new Tree(rand() % 10);
    T->left->left->left =new Tree(rand() % 10);
    T->left->right->right =new Tree(rand() % 10);
    T->left->right->left =new Tree(rand() % 10);

}

Tree *FindUltraRightLeaf(Tree *T){
    Tree *a = T;
    while(a->right)
        a = a->right;
    return a;
}

int main(){
    
    srand(time(NULL));

    Tree *T = NULL;



    PlantTree(T);


    printTree(T); cout << endl;
    printTreePlus(T);
    
    cout << "deutsches leaf = " << FindUltraRightLeaf(T)->data;


    deleteTree(T);



    cout << "\n\n\n";

    return 0;
}
