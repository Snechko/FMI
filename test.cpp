#include <iostream>

using namespace std;

const int INVALID_DATE = 1, INVALID_NUMBER = 2;

int main()
{
    int present_days = 45225; // 1.11.2023 in days from 1900

    long long int number = 0; //In the task is said that the product number is an integer not a natural number. That's why I use long long int instead of unsigned long int.
    cout << "Enter the number of the product: ";
    cin >> number;
    int number_to_day = (number & 1) + ((number >> 1) & 1) * 2 + ((number >> 2) & 1) * 4 + ((number >> 3) & 1) * 8 + ((number >> 4) & 1) * 16;
    int number_to_month = ((number >> 5) & 1) + ((number >> 6) & 1) * 2 + ((number >> 7) & 1) * 4 + ((number >> 8) & 1) * 8;
    int number_to_year = ((number >> 9) & 1) + ((number >> 10) & 1) * 2 + ((number >> 11) & 1) * 4 + ((number >> 12) & 1) * 8 + ((number >> 13) & 1) * 16 + ((number >> 14) & 1) * 32 + ((number >> 15) & 1) * 64 + ((number >> 16) & 1) * 128 + ((number >> 17) & 1) * 256;
    int expiry_days = ((number >> 18) & 1) + ((number >> 19) & 1) * 2 + ((number >> 20) & 1) * 4 + ((number >> 21) & 1) * 8 + ((number >> 22) & 1) * 16 + ((number >> 23) & 1) * 32 + ((number >> 24) & 1) * 64 + ((number >> 25) & 1) * 128 + ((number >> 26) & 1) * 256 + ((number >> 27) & 1) * 512 + ((number >> 28) & 1) * 1024 + ((number >> 29) & 1) * 2048 + ((number >> 30) & 1) * 4096;
    short int one_bits_in_number = (number & 1) + ((number >> 1) & 1) + ((number >> 2) & 1) + ((number >> 3) & 1) + ((number >> 4) & 1) + ((number >> 5) & 1) + ((number >> 6) & 1) + ((number >> 7) & 1) + ((number >> 8) & 1) + ((number >> 9) & 1) + ((number >> 10) & 1) + ((number >> 11) & 1) + ((number >> 12) & 1) + ((number >> 13) & 1) + ((number >> 14) & 1) + ((number >> 15) & 1) + ((number >> 16) & 1) + ((number >> 17) & 1) + ((number >> 18) & 1) + ((number >> 19) & 1) + ((number >> 20) & 1) + ((number >> 21) & 1) + ((number >> 22) & 1) + ((number >> 23) & 1) + ((number >> 24) & 1) + ((number >> 25) & 1) + ((number >> 26) & 1) + ((number >> 27) & 1) + ((number >> 28) & 1) + ((number >> 29) & 1) + ((number >> 30) & 1);
    bool control_bit = ((number >> 31) & 1);
    bool leap_year_check = (number_to_year % 4 == 0 && number_to_year % 100 != 0) || (number_to_year % 400 == 0); //Shown during practice exercises at FMI.

    cout << control_bit << "\n";
    cout << one_bits_in_number << "\n";
    cout << expiry_days << "\n";
    cout << number_to_year << "\n";
    cout << number_to_month << "\n";
    cout << number_to_day << "\n";

    switch (number_to_month) {
        case 2:
            if (leap_year_check == 1 && (number_to_day > 29 || number_to_day < 1)) {
                cout << "Invalid";
                return INVALID_DATE;
            }
            else if (number_to_day > 28 || number_to_day < 1){
                cout << "Invalid";
                return INVALID_DATE;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (number_to_day > 30 || number_to_day < 1) {
                cout << "Invalid";
                return INVALID_DATE;
            }
            break;
        default:
            if (number_to_day > 31 || number_to_day < 1) {
                cout << "Invalid";
                return INVALID_DATE;
            }
            break;
    }

    if (number_to_month > 12 || number_to_month < 1) {
        cout << "Invalid";
        return INVALID_DATE;
    }

    switch (number_to_month) {
        case 1:
            number_to_month = 31;
            break;
        case 2:
            number_to_month = 59;
            break;
        case 3:
            number_to_month = 90;
            break;
        case 4:
            number_to_month = 120;
            break;
        case 5:
            number_to_month = 151;
            break;
        case 6:
            number_to_month = 181;
            break;
        case 7:
            number_to_month = 212;
            break;
        case 8:
            number_to_month = 243;
            break;
        case 9:
            number_to_month = 273;
            break;
        case 10:
            number_to_month = 304;
            break;
        case 11:
            number_to_month = 334;
            break;
        case 12:
            number_to_month = 365;
            break;
        default:
            cout << "Invalid";
            return INVALID_DATE;
    }

    if ((control_bit == 0 && one_bits_in_number % 2 == 1) || (control_bit == 1 && one_bits_in_number % 2 == 0)) {
        cout << "Invalid";
        return INVALID_NUMBER;
    }

    number_to_year = number_to_year*365 + number_to_year%4;

    long int total_days = number_to_day + number_to_month + number_to_year + expiry_days;

    if (leap_year_check) {
        total_days += 1;
    }

    cout << "\n" << control_bit << "\n";
    cout << one_bits_in_number << "\n";
    cout << expiry_days << "\n";
    cout << number_to_year << "\n";
    cout << number_to_month << "\n";
    cout << number_to_day << "\n";


    if (total_days >= present_days) {
        cout << "Good";
        return 0;
    }
    else {
        cout << "Too old";
        return 0;
    }

    return 0;
}