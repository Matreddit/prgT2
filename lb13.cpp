#include<iostream>

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



// void addLeftBranch(Tree *& T, int inf){
//     Tree *Branch = new Tree;
//     Branch->data = inf;
//     Branch->left=NULL; Branch->right=NULL;
//     if(!T)
//         T = Branch;
//     else{
//         Tree *qT = T;
//         while(qT->left)
//             qT = qT->left;
//         qT->left = Branch;
//     }
// }

// Функція для прямого обходу дерева (in-order traversal)
void inOrder(Tree* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void printTree(Tree* root, string indent = "", bool isLeft = true) {
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
        printTree(root->left, indent, true);
        printTree(root->right, indent, false);
    }
}

int main(){

    Tree *T = NULL;

    T = new Tree(0);
    T->left = new Tree(-1);
    T->left->left = new Tree(-4);

    T->left->right = new Tree(-2);
    
    T->right = new Tree(1);
    T->right->right = new Tree(4);
    T->right->left = new Tree(2);

    

    printTree(T);

    cout << "\n\n\n------\n\n";
    Tree *zxc = T;
    while (zxc)
    {
        cout << zxc->data << endl;
        zxc = zxc->left;
    }
    




    return 0;
}
