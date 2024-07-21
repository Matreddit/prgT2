
#include <iostream>

using namespace std;

/*
– програма повинна містити функції, необхідні для вирішення завдання;
– кількість елементів масиву задається користувачем або визначається в процесі виконання
програми;
– на екран повинні виводитися початкові дані, а також результати всіх операцій;

Підвищений рівень

– програма повинна передбачати ініціалізацію масиву за вибором користувача: з клавіатури
або випадково (за умовчанням);
– програма повинна мати зрозумілий і доступний будь-якому користувачу інтерфейс;
– програма повинна виконуватися доти, поки користувач не захоче припинити роботу з
програмою.
*/


/*                         V29 - 24 = 5                         */
/*   Додати стовпець до двовимірного масиву у вказану позицію   */





void Delete2DimArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void ArrayRandFiller(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 90 + 10;
        }
    }
}

void CoutArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void CinArray(int** arr, int rows, int cols) {
    cout << "to continue enter " << rows * cols << " elements in array, or enter 1488 to break the loop:\n";
    bool isBreaked = false;

    for (int i = 0; i < rows; i++) {
        if (isBreaked)
            break;
        for (int j = 0; j < cols; j++) {
            cout << "enter " << j + 1 << "th element of " << i + 1 << "th row: ";
            int t = 0;
            cin >> t;
            if (t == 1488) {
                ArrayRandFiller(arr, rows, cols);
                isBreaked = true;
                break;
            }
            else arr[i][j] = t;
        }
    }
    cout << "You did it!\n";
}

void Fill1DimArrayRandomly(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 90 + 10;
    }
}

void AddColumn(int** arr, int* col, int rows, int cols, int posForCol, int fillWay, int** newArr, int newCols) {

    if (fillWay != 1) {
        Fill1DimArrayRandomly(col, rows);
    }
    else {
        cout << "enter " << rows << " elements of new column or enter 1488 to break\n";
        for (int i = 0; i < rows; i++) {
            cout << "enter " << i + 1 << "th element of new coloumn: ";
            int x = 0;
            cin >> x;
            if (x == 1488) {
                Fill1DimArrayRandomly(col, rows);
                break;
            }
            else {
                col[i] = x;
            }
        }
    }
    cout << "New column is:\n";
    for (int i = 0; i < rows; i++) {
        cout << col[i] << endl;
    }



    for (int i = 0; i < newCols; i++) {
        for (int j = 0; j < rows; j++) {
            if (posForCol == i) {
                newArr[j][i] = col[j];
            }
            else if (i < posForCol){
                newArr[j][i] = arr[j][i];
            }
            else {
                newArr[j][i] = arr[j][i - 1];
            }
        }

    }

}

int main()
{
    srand(time(NULL));


    int rows, cols;

    while (1) {


        cout << "welcome to \"Add a column to the two-dimensional array at the specified position\"-program.\n";
        cout << "enter 0 if u want it random.\n";

        cout << "Enter the number of rows: ";
        cin >> rows;

        cout << "Enter the number of columns: ";
        cin >> cols;

        if (rows == 0) {
            rows = rand() % 7 + 3; // (3, 9)
            cout << "rows num = " << rows << endl;
        }
        if (cols == 0) {
            cols = rand() % 7 + 3;
            cout << "cols num = " << cols << endl;
        }

        int** arr = new int* [rows];

        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }

        cout << "manual(1) or random array filling(0)?\n";
        int mrArrAns = 0;
        cin >> mrArrAns;
        if (mrArrAns == 0) {
            ArrayRandFiller(arr, rows, cols);
            cout << "your array is:\n";
            CoutArray(arr, rows, cols);
        }
        else {
            cout << "it's time to fill some nums!\n";
            CinArray(arr, rows, cols);
            cout << "your array is:\n";
            CoutArray(arr, rows, cols);
        }


        cout << "do you want to Add a column to the two-dimensional array at the specified position???\n(1 - yea, 0 - nope)\n";
        int adderAns = 0;
        int posForNewCol = rand() % cols;
        cin >> adderAns;
        if (adderAns == 1) {

            cout << "choose position for new coloumn (enter bigger than " << cols << " number to fill randomly): ";
            int posAns = -1;
            cin >> posAns;
            if (posAns > cols || posAns < 0) {
                cout << "pos for new col is " << posForNewCol << endl;
            }
            else
                posForNewCol = posAns;

            int* newColumn = new int[rows];
            cout << "Fill New column randomly or manually (0 or 1): ";
            int fillCAns = 0;
            cin >> fillCAns;
            int newCols = cols + 1;
            int** newArr = new int* [rows];
            for (int i = 0; i < rows; i++) {
                newArr[i] = new int[newCols];
            }
            AddColumn(arr, newColumn, rows, cols, posForNewCol, fillCAns, newArr, newCols);
            



            cout << "your result is:\n";

            cout << "the final result is:\n";
            CoutArray(newArr, rows, newCols);

            delete[] newColumn;
            Delete2DimArray(newArr, rows);

        }


        Delete2DimArray(arr, rows);

        cout << "thats all here, to quit enter 0, or 1 to run program again: ";
        int endAns = 0;
        cin >> endAns;
        if (endAns == 0)
            break;

    }

    
    return 0;
}