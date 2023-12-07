#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a = n;

    // today is 45264 days after the year 1900
    int today = 45264;

    int days = (n%2) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8) + (((n/16)%2)*16);
    n = n/32;
    int months = (n%2) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8);
    n = n/16;
    int years = (n%2) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8) + (((n/16)%2)*16) + (((n/32)%2)*32) + (((n/64)%2)*64) + (((n/128)%2)*128) + (((n/256)%2)*256);
    n = n/512;
    int due = (n%2) + (((n/2)%2)*2) + (((n/4)%2)*4) + (((n/8)%2)*8) + (((n/16)%2)*16) + (((n/32)%2)*32) + (((n/64)%2)*64) + (((n/128)%2)*128) + (((n/256)%2)*256) + (((n/512)%2)*512) + (((n/1024)%2)*1024) + (((n/2048)%2)*2048) + (((n/4096)%2)*4096);
    n = n/8192;
    int control = n%2;
    
    if(days > 31 || months > 12){
        cout << "Invalid";
        return 0;
    }
    if((years%4==0 && months == 2 && days > 29) || ( months == 2 && days > 28)){
        cout << "Invalid";
        return 0;
    }
    if((months == 4 || months == 6 || months == 9 || months == 1) && days > 30){
        cout << "Invalid";
        return 0;
    }

    due += (years*365 + (years%4));

    switch(months){
        case 1:
            due += 31;
            break;
        case 2:
            due += 59;
            break;
        case 3:
            due += 90;
            break;
        case 4:
            due += 120;
            break;
        case 5:
            due += 151;
            break;
        case 6:
            due += 181;
            break;
        case 7:
            due += 212;
            break;
        case 8:
            due += 243;
            break;
        case 9:
            due += 273;
            break;
        case 10:
            due += 304;
            break;
        case 11:
            due += 334;
            break;
        case 12:
            due += 365;
            break;
    }

    if(months >= 2 && years%4 ==0){
        due += 1;
    }

    due += days;

    if(due < today){
        cout << "Too old";
        return 0;
    }

    int ones;

    ones = ones + (a%2) + (((a/2)%2)*2) + (((a/4)%2)*4) + (((a/8)%2)*8) + (((a/16)%2)*16);
    a = a/32;
    ones = ones + (a%2) + (((a/2)%2)*2) + (((a/4)%2)*4) + (((a/8)%2)*8);
    a = a/16;
    ones = ones + (a%2) + (((a/2)%2)*2) + (((a/4)%2)*4) + (((a/8)%2)*8) + (((a/16)%2)*16) + (((a/32)%2)*32) + (((a/64)%2)*64) + (((a/128)%2)*128) + (((a/256)%2)*256);
    a = a/512;
    ones = ones + (a%2) + (((a/2)%2)*2) + (((a/4)%2)*4) + (((a/8)%2)*8) + (((a/16)%2)*16) + (((a/32)%2)*32) + (((a/64)%2)*64) + (((a/128)%2)*128) + (((a/256)%2)*256) + (((a/512)%2)*512) + (((a/1024)%2)*1024) + (((a/2048)%2)*2048) + (((a/4096)%2)*4096);

    if(control == 1 && ones%2 == 0){
        cout << "Invalid";
        return 0;
    }

    if(control == 0 && ones%2 == 1){
        cout << "Invalid";
        return 0;
    }

    cout << "Good";
    return 0;
}
