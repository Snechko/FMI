#include <iostream>
using namespace std;

int main(){
    int len1;
    cout << "Enter 1st array length: ";
    cin >> len1;

    int arr1[len1];

    cout << "\nEnter array elements: \n";
    for(int i = 0; i < len1; i++){
        cin >> arr1[i];
    }

    int len2;
    cout << "\n\nEnter 2nd array length: ";
    cin >> len2;

    if(len1 < len2){
        cout << "false\n";
    }


    int arr2[len2];

    cout << "\nEnter array elements: \n";
    for(int i = 0; i < len2; i++){
        cin >> arr2[i];
    }

    bool result = false;
    int j = 0;

    for(int i = 0; i < len2; i++){
        while(j < len1){
            if(arr1[j] == arr2[i]){
                result = true;
                j++;
                break;
            }
            j++;
        }
        if(!result){
            cout << "false" << "\n";
            return 0;
        }
        else{
            result = false;
        }
    }

    cout << "true" << "\n";
    return 0;
}