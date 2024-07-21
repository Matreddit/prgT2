#include <iostream>
#include <cstring>


using namespace std;

const int N = 512;

int findChr(char * str, char symb){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == symb){
            return i;
        }
        i++;
    }
    cout << "Chr not found";
    return -1;
}

int findLastChr(char* str, char symb){
    int i = 0;
    int k = -1;
    while (str[i] != '\0'){
        if (str[i] == symb){
            k = i;
        }
        i++;
    }
    if (k == -1){
        cout << "Chr not found";
    }
    return k;
}

void CoutPath(char *string) {
    int j = findLastChr(string, '\\') + 1;
    for(int i = 0; i < j; i++){
        cout << string[i];
    }
}

void CoutFileName(char *string){
    int i = findLastChr(string, '\\') + 1;
    while (string[i] != '\0'){
        cout << string[i];
        i++;
    }
}

void CoutFileExtension(char * str){
    int i = findLastChr(str, '.');
    while (str[i] != '\0'){
        cout << str[i];
        i++;
    }
}

void CoutNameOnly(char* str){
    int s = findLastChr(str, '\\') +1;
    int f = findLastChr(str, '.');
    while (s < f){
        cout << str[s];
        s++;
    }
}

void CoutLastFolder(char* str){
    int s = findLastChr(str, '\\');
    char str2[N];
    strncpy(str2, str, s);
    CoutFileName(str2);
}

void CoutHtmlFile(char* str, char *extention){
    CoutPath(str);
    CoutNameOnly(str);
    cout << extention;
}

int main()
{
    char str[N] = "D:\\Programs\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\game\\bin\\win64\\cs2.exe";

    CoutPath(str);
    cout << endl;

    CoutFileName(str);
    cout << endl;

    CoutFileExtension(str);
    cout << endl;

    CoutNameOnly(str);
    cout << endl;

    CoutLastFolder(str);
    cout << endl;

    CoutHtmlFile(str, ".html");
    cout << endl;

    return 0;
}
