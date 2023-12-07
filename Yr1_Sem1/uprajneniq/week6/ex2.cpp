#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string result;

    for(int i = n%10; i != 0; n/10){
        for(int j = 0; j < i; j++){
            result += "*";
        }
        result += "\n";
    }

    cout << result << "\n";
    return 0;
}