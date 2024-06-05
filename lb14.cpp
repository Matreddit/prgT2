#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

/* Розробити програму з метою виконання відповідного варіанту для одного з нижче наведених завдань за допомогою рекурсії.
v29-16=13
13. Обчислити число зерен, вирощених селянином за N років, якщо він
посадив 10 зерен. Річний врожай складає 22 зерна на кожне посаджене зерно.  

    якщо farmer один раз посіяв і чекає кілька років, як вони там примножуються, то буде так:
*/
int CountWeed(int years){
    if (years == 0) return 10;
    return CountWeed(years - 1) * 22;
}



int count(int years){
    int zerns = 10;
    for(int i = 0; i < years; i++){
        zerns *= 22;
    }
    return zerns;
}


int main(){
    
    int years = 3;

    cout << "farmer has " << CountWeed(years) << " pieces of weed in "<<years<<" years\n\n\n";

    //cout << "farmer has " << count(years) << " pieces of zern\n\n\n";


    return 0;
}