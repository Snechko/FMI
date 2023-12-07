#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string result = "1    ";

    for(int i = 0; i < n; i++){
        for(int j = i - 1; j < i*n; j++){
            if(j < 1){
                j = 2;
            }
            result += i*j + "    ";
        }
        result += "\n";
        for(int b = 0; b < i - 1; b++){
            result += "    ";
        }
    }

    cout << result;
    return 0;
}