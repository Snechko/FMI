#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x;
    double y;

    cin >> x;
    cin >> y;

    x = round(x * 1000) / 1000;
    y = round(y * 1000) / 1000;

    double diag = round(((2.646*x)/3) * 1000) / 1000;
    double circle = round((x*x + y*y)*1000) / 1000;

    if(circle == 16 || (y == diag && y <= 2.646) || (x < 0 && -y == diag && y <= 2.646) || (abs(x) == 3 && abs(y) <= 2.646) || (x == 0 && y <=6 && y >= -6) || (abs(x) <= 1 && y == 5) || (abs(x) <= 2 && (y == -6 || y == -7)) || (abs(x) == 2 && y <=-6 && y >=-7)){
        cout << "On the edge";
        return 0;
    }

    // if(y == diag && y <= 2.646){
    //     cout << "On the edge";
    //     return 0;
    // }

    // if(x < 0 && -y == diag && y <= 2.646){
    //     cout << "On the edge";
    //     return 0;
    // }

    // if(abs(x) == 3 && abs(y) <= 2.646){
    //     cout << "On the edge";
    //     return 0;
    // }

    // if(x == 0 && y <=6 && y >= -6){
    //     cout << "On the edge";
    //     return 0;
    // }

    // if(abs(x) <= 1 && y == 5){
    //     cout << "On the edge";
    //     return 0;
    // }

    // if(abs(x) <= 2 && (y == -6 || y == -7)){
    //     cout << "On the edge";
    //     return 0;
    // }

    // if(abs(x) == 2 && y <=-6 && y >=-7){
    //     cout << "On the edge";
    //     return 0;
    // }

    if(x > 0 && x < 3 && circle < 16 && y < diag ){
        cout << "Yellow";
        return 0;
    }

    if(x > 0 && x < 3 && circle < 16 && y > diag ){
        cout << "Green";
        return 0;
    }

    if(x > 3 && x < 4 && circle < 16){
        cout << "Purple";
        return 0;
    }

    if(x < 0 && x > -3 && abs(y) < diag ){
        cout << "Pink";
        return 0;
    }

    if(x < 0 && x > -3 && circle < 16 && abs(y) > diag ){  
        if(y < 0){
            cout << "Blue";
            return 0;
        }
        else{
            cout << "Red";
            return 0; 
        }
    }

    if(x > -2 && x < 2 && y > -7 && y < -6){
        cout << "Grey";
        return 0;
    }

    cout << "Outside";
    return 0;
}