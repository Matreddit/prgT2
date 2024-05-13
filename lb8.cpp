#include <iostream>
#include <fstream>

#include <cstdlib>
#include <ctime>

using namespace std;
/* v29 - 15 = 14
Дано текстовий файл f цілих чисел, що не дорівнюють нулю.
Файл містить однакову кількість додатних і від'ємних чисел.
Використовуючи допоміжний файл h, переписати числа файлу f у файл g так,
щоб спочатку були записані всі додатні, а потім всі від'ємні числа.
*/

int main()
{
    srand(time(NULL));

    // create f file
    ofstream out_f("files8/f.txt");
    if (out_f){
        out_f << "3 -4 5 -6 7 -2 4 -1 5 -3 6 -2 12 -5 6 -9 7 -1 12 -3 5 -11";
    }
    out_f.close();


    ifstream in_f("files8/f.txt");
    ofstream out_gPos("files8/g.txt");
    ofstream out_hNeg("files8/h.txt");

    if(in_f && out_gPos && out_hNeg){
        int num;
        while(in_f >> num){
            if (num > 0)
                out_gPos << num << " ";
            else if (num < 0){
                out_hNeg << num << " ";
            }
        }
    } else {
        cout << "error\n";
    }
    // g << h
    out_hNeg.close();
    ifstream in_h("files8/h.txt");
    string str;
    getline(in_h, str);
    out_gPos << str;

    in_f.close();
    out_gPos.close();
    in_h.close();



    // Підвищений рівень, 14.
    // Інформація що входить до файлу: номер рейсу, вага багажу, кількість речей. Визначити середню вагу багажу.

    // create data file
    ofstream oData("files8/data.txt");
    if (oData){
        for(int i = 0; i < 50; i++){
            int raceNum = rand() % 9000 + 1000; // [1 - 5] = rand() % 5 + 1
            int bagWeight = rand() % 20 + 1;
            int itemNum = rand() % 100 + 1;
            oData << raceNum << "\t" << bagWeight << "\t" << itemNum << endl;
        }
    }
    oData.close();

    ifstream iData("files8/data.txt");

    float averageWeight = 0;
    if (iData){
        int raceNum, bagWeight, itemNum, i;
        for(i = 0; !iData.eof(); i++){
            iData >> raceNum >> bagWeight >> itemNum;
            averageWeight += bagWeight;
            // cout << i << ": " << bagWeight << "\t" << averageWeight << endl;
        }
        averageWeight = averageWeight/i;
    }

    cout << "Average weight is: "<<averageWeight << endl;
    
}
