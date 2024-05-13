#include<iostream>
//#include<cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

#define n 8 // number of athletes
#define m 4 // number of snarjadiv


/* v29 - 15 = 14
В змаганнях зі спортивної гімнастики приймають участь декілька спортсменів. Вони
виконують вправи на 4 снарядах. Створити масив структур, що містить відомості про кожного
спортсмена: прізвище та оцінки на кожному снаряді. Вивести прізвища тих спортсменів, які
в сумі отримали найбільще балів.                                     */


struct human
{
    string name;
    int marks[4];
};


int countSum (int *arr){
    int sum = 0;
    for(int i = 0; i < m; i++) sum += arr[i];
    return sum;
}



int main(){
    srand(time(NULL));

    human h[n];

    h[0].name = "SMITH";
    h[1].name = "BROWN";
    h[2].name = "WILSON";
    h[3].name = "THOMSON";
    h[4].name = "ROBERTSON";
    h[5].name = "CAMPBELL";
    h[6].name = "STEWART";
    h[7].name = "ANDERSON";
    

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            h[i].marks[j] = rand() % 5 + 1;
        }
    }

    cout << "-----\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << h[i].marks[j] << "  ";
        }
        cout << "|  " << h[i].name << ": " << countSum(h[i].marks) << endl;
    }

    cout << "-----\n";
    int first = 0;
    for (int i = 0; i < n; i++){
        int sum = countSum(h[i].marks);
        if(sum > countSum(h[first].marks)) first = i;
    }
    cout << "FIRST IS " << h[first].name << endl;

    int second = 0;
    do{
        second = rand() % 5 + 1;
    } while (second == first);

    for (int i = 0; i < n; i++){
        int sum = countSum(h[i].marks);
        if(sum > countSum(h[second].marks) && i != first) second = i;
    }
    cout << "SECOND IS " << h[second].name << endl;

    int third = 0;
    do{
        third = rand() % 5 + 1;
    } while (third == first || third == second);

    for (int i = 0; i < n; i++){
        int sum = countSum(h[i].marks);
        if(sum > countSum(h[third].marks) && i != first && i != second) third = i;
    }
    cout << "THIRD IS " << h[third].name << endl;


    return 0;
}