#include<iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

/* v29 - 25 = 4
4. Відсортувати елементи одновимірного і двовимірного динамічних масивів
(сортування Шелла і сортування злиттям (Merge sort) ) за спаданням (розмірність масивів: 23,
9х15). */

void bubbleSort12(int *arr, int size);
void bubbleSort21(int *arr, int size);

int main(){
    srand(time(NULL));

    int N = 23, n = 9, m = 15;

    int *arr = new int[N];

    for(int i = 0; i < N; i++){
        arr[i] = rand() % 91 + 10; // 10 - 100
    }

    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    


    bubbleSort21(arr, N);





    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    delete[] arr;


    return 0;
}


void bubbleSort12(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                // for(int i = 0; i < size; i++){cout << arr[i] << " ";}cout << endl;
            }
        }
    }
}

void bubbleSort21(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] < arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                // for(int i = 0; i < size; i++){cout << arr[i] << " ";}cout << endl;
            }
        }
    }
}
