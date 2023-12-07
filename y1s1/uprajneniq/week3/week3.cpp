#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main(){
    double far;

    cin >> far;

    cout << "Celsius: " << (far-32)*5/9 << endl;

    return 0;
}