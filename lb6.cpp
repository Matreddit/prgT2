#include<iostream>
#include<cmath>


using namespace std;

/* v29 - 24 = 5
An Armstrong number is a number that equals the sum of its digits, each raised to a power.
*/


float stepin (float x, int n){
    if (n == 0) return 1;
    else return x * stepin(x, n-1);
}


int fact(int x){
    if (x < 0) return 0;
    if (x == 0) return 1;
    else return x*fact(x-1);
}




bool isArmstrong (int n){

    int sum = 0;

    int digts = 0;
    int n1 = n;
    while (n1 != 0){
        n1 /= 10;
        digts++;
    }

    n1 = n;
    while(n1 != 0){
        int d = n1 % 10;
        sum += pow(d, digts);
        n1 /= 10;
    }
    bool res = (n == sum);
    return res;
}

void findArmsts(int n = 1, int k = 9999){
    bool isFound = false;
    for(int i = n; i < k; i++){
        if (isArmstrong(i)) {
            cout << i << " is armstr\n";
            if(!isFound) isFound = true;
        }
    }
    if (!isFound) cout << "there is no armstrong numbers in range [" << n << ", " << k << "]\n";

}


int main(){

    findArmsts(1, 99999999);


    return 0;
}