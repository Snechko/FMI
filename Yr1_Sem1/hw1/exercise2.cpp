#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string invalid_data = "Invalid data\n";
    int n;

    cin >> n;

    if(n > 524287 || n < 0){
        cout << invalid_data;
        return 0;
    }

    int sec = ((n%2)) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8) + (((n/16)%2)*16) + (((n/32)%2)*32);
    n = n/64;

    int min = ((n%2)) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8) + (((n/16)%2)*16) + (((n/32)%2)*32);
    n = n/64;

    int hr2 = ((n%2)) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8);
    n = n/16;

    int hr1 = ((n%2)) + (((n/2)%2)*2);
    n = n/4;

    int format = n%2;

    // check for invalid data
    if(min > 59 || sec > 59 || hr1 > 2 || hr2 >9){
        cout << invalid_data;
        return 0;
    }

    if(format == 0){
        if(hr1 > 1 && hr2 >2){
            cout << invalid_data;
            return 0;
        }
    }
    
    if((hr1 > 2 && hr2 > 3) || hr2 > 9){
        cout << invalid_data;
        return 0;
    }

    cout << hr1 << hr2 << ":" << ((min < 10) ? "0" : "") << min << ":" << ((sec < 10) ? "0" : "") <<  sec;

    return 0;
}
