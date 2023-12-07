#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int result;
    for(int i = 3; i < n; i++){
        if(i%3 == 0 || i%5 ==0){
            result += i;
        }
    }
    cout << result << "\n";
    return 0;
}