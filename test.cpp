#include <iostream>

using namespace std;



void bubbleSort(int * arr, int size){
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



int main() {

    const int N = 10;

    // int array[N] = {7,2,8,5,4};

    int *array = new int[N];

    array[0] = 9;
    array[1] = 7;
    array[2] = 8;
    array[3] = 6;
    array[4] = 3;
    array[5] = 4;
    array[6] = 5;
    array[7] = 2;
    array[8] = 1;
    array[9] = 10;

    for(int i = 0; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "---------\n";


    shellSort(array, N);

    cout << "---------\n";
    for(int i = 0; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl << endl;






    int matrix[3][5] = {
        {5, 2, 7, 9, 3},
        {3, 5, 6, 1, 4},
        {1, 3, 5, 7, 6}
    };
    cout << "before"<< endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    for(int i = 0; i < 3; i++){
        bubbleSort(matrix[i], 5);
    }
    for(int i = 0; i < 5; i++){
        int *arr0 = new int[3];
        for(int j = 0; j < 3; j++){
            arr0[j] = matrix[j][i];
        }
        bubbleSort(arr0, 3);
        for(int j = 0; j < 3; j++){
            matrix[j][i] = arr0[j];
        }

        delete[] arr0;
    }

    cout << "after"<< endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}
