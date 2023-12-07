#include <iostream>
using namespace std;

void inArray(int* arr){
    int temp = sizeof(arr) / sizeof(int);
    for(size_t i = 0; i < *(&arr + 1) - arr; i++){
        cout << "Enter element " << i + 1 << ":";
        cin >> arr[i];
        cout << arr[i];
    }
}

void outArray(int* arr){
    for(size_t i = 0; i < sizeof(arr) / sizeof(int); i++){
        cout << arr[i];
    }
}

int main(){
    cout << "Enter array length: ";
    int len;
    cin >> len;

    int arr[len];

    inArray(arr);
    outArray(arr);    
}