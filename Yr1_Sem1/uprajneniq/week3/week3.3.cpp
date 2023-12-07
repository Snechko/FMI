#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cstring>
#include <string>
using namespace std;

bool check(string);

int main(){
    // double a;

    // cin >> a;

    // if(a > 0){
    //     double right = sqrt(a-1);
        
    //     // module part
    //     if(right < 0){
    //         right = right*(-1);
    //     }


    // }

    string str;

    cin >> str;

    cout << check(str) << endl;

    return 0;
}

bool check(string paleindrome){
    bool result = true;

    for(int i = 0; i < paleindrome.length() - 1; i++){
        if(paleindrome[i] != paleindrome[paleindrome.length() - 1 -i]){
            result = false;
        }
    }

    return result;
}