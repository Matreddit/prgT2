#include<iostream>
#include<cmath>

using namespace std;

// 1
void A14(){
    for (float x = -M_PI/2; x < (3/2)*M_PI; x += M_PI/10){
        if (x <= 0)
            cout << x+2 << '\n';
        else if(0 < x && x < M_PI)
            cout << 2 * cos(2*x) << '\n';
        else if (x >= M_PI)
            cout << 2 << '\n';
    }
}

// 2
float Bi14(int a1, int b1, int c1, int a2, int b2, int c2){
    int min1 = a1;
    if (b1 < min1)
        min1 = b1;
    if (c1 < min1)
        min1 = c1;

    int min2 = a2;
    if (b2 < min2)
        min2 = b2;
    if (c2 < min2)
        min2 = c2;

    return sqrt(min1*min2);
}   

// 3
void trijka(int *nnn, int size){

    int * posR = new int[size/3]; 
    int * posB = new int[size/3]; 
    int * posF = new int[size/3]; 
    int ip1 = 0, ip2 = 0, ip3 = 0;
    for (int i = 0; i < size; i+= 3){
        if (nnn[i] == nnn[i+1] && nnn[i] == nnn[i+2]){
            posR[ip1] = i;
            ip1++;
        } else if (nnn[i] == nnn[i+1] || nnn[i] == nnn[i+2] || nnn[i+1] == nnn[i+2]){
            posB[ip2] = i;
            ip2++;
        } else {
            posF[ip3] = i;
            ip3++;
        }
    }


    cout << "rivnostoronni:\t";
    for (int i = 0; i < ip1; i++) {
        cout << nnn[posR[i]] << ' ' << nnn[posR[i]+1] << ' ' << nnn[posR[i]+2] << "    "; 
    }
    cout << "\nkilkist: " << ip1 << endl;
    cout << "rivnoBedrenni:\t";
    for (int i = 0; i < ip2; i++) {
        cout << nnn[posB[i]] << ' ' << nnn[posB[i]+1] << ' ' << nnn[posB[i]+2] << "    "; 
    }
    cout << "\nkilkist: " << ip2 << endl;
    cout << "inshi:\t";
    for (int i = 0; i < ip3; i++) {
        cout << nnn[posF[i]] << ' ' << nnn[posF[i]+1] << ' ' << nnn[posF[i]+2] << "    "; 
    }
    cout << "\nkilkist: " << ip3 << endl;



    delete[] posR, posB, posF;

}



int main(){
    // v29 - 15 = 14

    // 1 'a'
    cout << "TASK 1\n";
    A14();
    cout << "\n\n";



    // 2 'be'
    /*14. Дано дві трійки чисел a1, b1, c1 та a2, b2, c2. Обчислити вираз...*/
    cout << "TASK 2: " << Bi14(4, 7, 3, 9, 2, 11) << "\n\n\n";

    // 3 've'
 /* Дана послідовність n трійок (ai, bi, ci), де ai, bi, ci – цілі числа. Ці трійки поділимо на
    три види: 1) рівносторонні, тобто ai=bi=ci; 2) рівнобедрені, тобто в трійці є тільки два
    рівних числа; 3) інші трійки. Підрахувати кількість трійок кожного виду. Створити
    процедуру, яка визначає вид трійки. */
    cout << "TASK 3\n";

    int arr[] = {1,1,1, 1,2,3, 2,2,2, 3,2,1, 3,3,3, 9,8,7, 4,4,4, 6,7,8, 5,5,5, 6,3,6, 2,2,2, 3,3,1, 1,2,3, 1,2,2};

    trijka(arr, sizeof(arr)/sizeof(arr[0]));

    cout << "\n\n";
    
    return 0;
}