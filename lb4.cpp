#include <iostream>
#include <cstring>

using namespace std;


///////////// V29 - 15 = 14
    /*14. Підрахувати кількість відкритих та закритих фігурних дужок у рядку та вивести номери
    їх позицій. Вилучити усі символи, які розташовані всередині дужок. (Вважати, що для
    кожної відкритої дужки існує відповідна закрита, і між ними інших дужок немає). Якщо
    дужок у рядку немає, то вивести про це інформацію.*/

int main(){
    
    char str1[] = "hello{zxcv} zxc {zxc}zxc {}";

    int *br1pos = new int[strlen(str1)];
    int i11 = 0;

    int brkNum = 0;
    bool shouldDelete = false;
    for (int i = 0; str1[i] != '\0'; i++){
        if (str1[i] == '{'){
            brkNum++;
            shouldDelete = true;
            br1pos[i11] = i; i11++;

        } else if (str1[i] == '}'){
            shouldDelete = false;
            br1pos[i11] = i; i11++;
        }
        if (shouldDelete && str1[i] != '{'){
            str1[i] = '*';
        }
    }
    
    char * str1p = new char[strlen(str1)];

    //cout << str1 << endl << endl;

    int i1 = 0;
    for (int i = 0; str1[i] != '\0'; i++){
        if (str1[i] != '*'){
            str1p[i1] = str1[i];
            i1++;
        } 
    }

    cout << str1p << endl;
    cout << "kilkist duszok: " << brkNum << endl;
    cout << "duzhka vidkrylas v: ";
    for (int i = 0; i < i11; i+=2){
        cout << br1pos[i] << " ";
    }
    cout << "\nduzhka zakrylas v: ";
    for (int i = 1; i < i11; i+=2){
        cout << br1pos[i] << " ";
    }
    cout << "\n";
    delete[] str1p;
    delete[] br1pos;

    //////////////////////////// 222222222222222222 ///////////////////////////////// 222222222222222222
/*14. Дано масив, слів і в кожному слові від 1 до 8 малих українських літер. У кожному слові
кожну букву повторити (наприклад, зі слова «ох» отримати слово «оохх»).   */
    cout <<"\n\n";


    char str2[] = "salo sho kum ljah hohol";

    char * pstr2 = new char [strlen(str2)*2];
    int i2 = 0;
    for (int i = 0; str2[i] != '\0'; i++){
        if (str2[i] != ' '){
            pstr2[i2] = str2[i];
            pstr2[i2+1] = str2[i];
            i2+=2;
        } else{
            pstr2[i2] = ' ';
            i2++;
        }
    }

    cout << pstr2 << endl;
    delete[] pstr2;

    return 0;
}