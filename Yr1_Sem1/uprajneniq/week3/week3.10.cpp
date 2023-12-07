#include <cmath>
#include <iostream>
using namespace std;


int main(){
    double a;

    cin >> a;

    if(a > 0){
        double x = sqrt(abs(a-1))*(-1) / (5*cbrt(a));

        cout << x << endl;
    }

    if(a <= 0){
        const double eulerA = std::exp(a);
        const double eulerConst = std::exp(1.0);

        double exp = (pow(a, 2) + 5) / eulerA;

        cout << log(exp) / log(eulerA) << endl;
    }

    return 0;
}