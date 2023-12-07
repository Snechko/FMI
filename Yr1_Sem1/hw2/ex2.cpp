#include <iostream>
#include <cmath>
using namespace std;

const double field[4] = {5, -5, 2, -2};

double calcDistance(double x1, double y1, double x2, double y2){
    double dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    dist = (((3.14*dist)/2)+dist)/2;
    return dist;
}

// calculate distance from point (x1,y1) {lays inside the field} to point of intersect with field
double calcWithIntersect(double x1, double y1, double x2, double y2){
    // if line is vertical(undefined by y=m*x+c)
    if((x2 - x1) == 0){
        if(y2 > 2){
            return calcDistance(x2, 2, x1, y1);
        }
        else{
            return calcDistance(x2, -2, x1, y1);
        }
    }
    
    double m = (y2 - y1)/(x2 - x1);
    double c = y1 - m*x1;
    double intersectY;
    double intersectX;

    // if line is defined by y=m*x+c
    for(int j = 0; j < 4; j++){
        
        intersectY = m*field[j] + c;
        intersectX = (field[j]-c)/m;

        if(j < 2){
            if(abs(intersectY) <= 2){
                return calcDistance(field[j], intersectY, x1, y1);
            }
            // else if (abs(intersectY) == 2){
            //     return calcDistance(field[j],);
            // }
            
        }
        else{
            if(abs(intersectX) <= 5){
                return calcDistance(intersectX, field[j], x1, y1);
            }
        }

        if(abs(intersectX) == 5 && abs(intersectY) == 2){
            return calcDistance(intersectX, intersectY, x1, y1);
        }
    }
}

int main(){
    int len;
    cin >> len;

    if(len > 2000000000 || len < 1){
        cout << "Array length exceeds max/min size!\n";
        return 0;
    }

    double arr[len][2];

    for(int i = 0; i < len; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    double result;
    bool isLastOutside = false;

    for(int i = 0; i < len; i++){
        // check if point is outside field
        if(abs(arr[i][0]) > (double)5 || abs(arr[i][1] > (double)2)){
            if(i == 0){
                isLastOutside = true;
                continue;
            }

            // if current point is outside, but last was inside
            if(!isLastOutside){
                isLastOutside = true;

                result += calcWithIntersect(arr[i-1][0], arr[i-1][1], arr[i][0], arr[i][1]);
            }
            continue;
        }
        
        // if last point was outside field, but current is inside
        if(isLastOutside){
            isLastOutside = false;
                result += calcWithIntersect(arr[i][0], arr[i][1], arr[i-1][0], arr[i-1][1]);
            continue;
        }

        // if both points are inside field
        if(i != 0){
            isLastOutside = false;
            result += calcDistance(arr[i][0], arr[i][1], arr[i-1][0], arr[i-1][1]);
        }
    }

    result = round(result*1000)/1000;
    cout << result << "\n";
    return 0;
}