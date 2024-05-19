#include <iostream>
#include <cstring>


using namespace std;

const int N = 512;

int CharToInt (char *str){
    return atoi(str);
}

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
////////// 2
 
int CountStrInStr(char* str, char * str0){
    int count = 0;
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
        
        
        if(str[i] == str0[j]){
            j++;
            if(j == strlen(str0)){
                count++;
                j = 0;
            }
        }
        i++;
    }
    return count;

}

void Transliterationen(char*str, char*str2,char*str3){
    int i = 0, j = 0;
    while (str[i] != '\0'){
        while(str2[j] != '\0'){
            if (str[i] == str2[j]){
                str[i] = str3[j];
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void HidePassword(char * str){
    char p[9] = "password";
    int pLen = 8;
    bool isPswdFound = false;
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        int l = i;
        while(isPswdFound){
            str[l] = '*';
            l++;
            if(l >= i+8)
                isPswdFound = false;
        }
        if (str[i] == p[j]){
            j++;
            if(j == strlen(p)){
                isPswdFound = true;
                j = 0;
            }
        }
        i++;
    }
}

void strcatN(char *str, char *str0, int n){
    if(n > strlen(str0)){
        cout << "zrada: n > len of str0\n";
        return;
    }
    int end = 0;
    while(str[end]!='\0'){
        end++;
    }
    for(int i = 0; i < strlen(str0); i++){
        str[end + i] = str0[n + i];
    } 
}

void TakeInBr(char* str, char* str1){
    char * str0 = new char[strlen(str)*2];
    int i = 0, ii = 0;
    while(str[i] != '\0'){
        str0[ii] = str[i];
        if (str[i] == str1[0]){
            bool issFound = true;
            for (int s = 0; s < strlen(str1); s++)
            {
                if(str[i + s] != str1[s]){
                    issFound = false;
                    break;
                }
            }
            if (issFound){
                str0[ii] = '(';
                strcat(str0, str1);
                ii += strlen(str1) + 1;

                str0[ii] = ')';
                i += strlen(str1)-1;
            }
        }
        i++;
        ii++;
    }

    strcpy(str, str0);
    delete[] str0;

}

//
void strcatN3(char*str1, char *str2){
    int end = 0;
    while (str1[end] != '\0'){
        end++;
    }
    for (int i = 0; str2[i]!='\0';i++){
        if(str1[end+i] == '\0')
           str1[end+i] = str2[i];
    }
}
//

//// 3.1
/*
int strSum(char * str){
    int ch1 = 0, sum = 0;
    char znak = '+';
    char chyslo[9] = "0";
    
    for(int i = strlen(str); i > 0; i--){
        if(!isdigit(str[i])){
            if (str[i]=='+')
                znak = '+';
            if(str[i]=='-')
                znak = '-';

            if (znak == '+'){
                sum += CharToInt(chyslo);
            } else if (znak == '-'){
                sum -= CharToInt(chyslo);
            }
        }
        
        int j = i; 
        while(isdigit(str[j])){
            char sstr[2]; sstr[0] = str[j];
            strcatN3(chyslo, sstr);

            j++;
        }
        i = j;
        
        
    }
    

    return sum;
}
*/


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
    
    ///// 2.2
    char aaa[N] = "abc abcabc000kj ABCBCABCiug bABCabc"; //4
    char a[N] = "ABC";
    int zxc = CountStrInStr(aaa, a);
    cout << zxc << endl;
    
    ///// 2.3
    char z[N] = "AqAwAeArAt AqAwAeArAt";//"quit hello world rdrp";
    
    Transliterationen(z, "qwert", "zxcvb");

    cout << z << endl;

    //////// 2.4
    char s222[N] = "Hello my password12345678is zxc password888 88801";
    HidePassword(s222);
    cout << s222 << endl;

    /////// 2.5
    char str25[N] = "FzxczxcFzxcFzxcFFFzxcFFFzxczxczxcFFFzxcFzxFxcFzcF";
    TakeInBr(str25, "zxc");
    cout << str25 << endl;



    //cout << strSum("5+26-72+35gh32+45") << endl;
    
    return 0;
}