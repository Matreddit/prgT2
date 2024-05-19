#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

/* v29 - 25 = 4
4. Відсортувати елементи одновимірного і двовимірного динамічних масивів
(сортування Шелла і сортування злиттям (Merge sort або "смерть sort") ) за спаданням (розмірність масивів: 23,
9х15). */

void bubbleSort12(int *arr, int size);
void bubbleSort21(int *arr, int size);

void insertSort12(int *arr, int size);
void insertSort21(int *arr, int size);

void shellGSort12(int *arr, int size);
void shellGSort21(int *arr, int size);

void shellSort(int *arr, int n);

int main(){
    srand(time(NULL));

    int N = 23, n = 9, m = 15;

    int *arr = new int[N];
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 91 + 10; // 10 - 100
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }cout << endl << endl;
    

    // bubbleSort21(arr, N);
    // insertSort21(arr, N);
    shellSort(arr, N);


    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    // двовимірного динамічних масивів
    int **matrix = new int*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new int[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = rand() % 90 + 10; // 10 - 99
        }
    }

    cout << "\n\nbefore\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < n; i++){
        bubbleSort21(matrix[i], m); // розчесуєм горизонтально
    }
    for(int i = 0; i < m; i++){
        int *arr0 = new int[n];
        for(int j = 0; j < n; j++){
            arr0[j] = matrix[j][i];
        }
        bubbleSort21(arr0, n); // розчісуєм горизонтально
        for(int j = 0; j < n; j++){
            matrix[j][i] = arr0[j];
        }
        delete[] arr0;
    }

    cout << "after\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;


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
            }
        }
    }
}

void insertSort12(int *arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i], j = i - 1;
        for(; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void insertSort21(int *arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i], j = i - 1;
        for(; j >= 0 && arr[j] < key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void shellGSort12(int *arr, int size){
    // Початкова відстань (gap)
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Виконуємо сортування методом вставок для кожного підмасиву з елементами, розташованими через gap
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellGSort21(int *arr, int size){
    // Початкова відстань (gap)
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Виконуємо сортування методом вставок для кожного підмасиву з елементами, розташованими через gap
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSort(int *arr, int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
    }
}
