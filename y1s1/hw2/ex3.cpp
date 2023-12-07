#include <iostream>
#include <cmath>
using namespace std;

// This exersice is not complete, I just submitted it for bonus points

int main(){
    int gamesNum;

    cout << "How many games would you like to play? \n";
    cin >> gamesNum;
    while(gamesNum < 0){
        cout << "Invalid amount of games. please pick a number greater than 0;\n";
        cin >> gamesNum;
    }

    cout << "What is your number? \n";

    int input;

    cin >> input;

    while(input < 1000 || input > 9999){
        cout << "Number is not a 4 digit number, please pick another one.\n";
        cin >> input;
    }

    int usrNum[4];
    int botNum[4];

    for(int i = 0; i < 4; i++){
        // generate bot number
        botNum[i] = round(rand() % 9);

        if(i == 0){
            while(botNum[i] < 1){
                botNum[i] = round(rand() % 9);
            }
        }

            // cout << "input: " << input << "\n";
        // user number to array
        usrNum[3-i] = input % 10;
        input = input / 10;
            // cout << "usrGu: " << usrNum[i] << "\n";
    }

    int gamesPlayed = 0;
    int usrBulls = 0;
    int usrCows = 0;
    int botBulls = 0;
    int botCows = 0;
    int usrGuess[4];
    int botGuess[4];
    int botMem[4];
    int score[2] = {0, 0};

    while(gamesPlayed < gamesNum){
        cout << "Try to guess my number: \n";
        cin >> input;

        for(int i = 0; i < 4; i++){
            // generate bot guess
            botGuess[i] = round(rand() % 9);

            if(i == 0){
                while(botGuess[i] < 1){
                    botGuess[i] = round(rand() % 9);
                }
            }

            // user guess to array
            cout << "input: " << input << "\n";
            
            // user number to array
            usrGuess[3-i] = input % 10;
            input = input / 10;
            
            cout << "usrGu: " << usrGuess[i] << "\n";
        }

        // user guess results
        cout << "Bulls: ";
        for(int i = 0; i < 4; i++){
            if(usrGuess[i] == botNum[i]){
                cout << usrGuess[i] << ", ";
                usrGuess[i] = -1;
                usrBulls++;
            }
        }

        cout << ";\n";
        if(usrBulls == 4){
            score[1]++;
            gamesPlayed++;
            cout << "You guessed the whole number correctly! You get a point!\n";
            cout << "Game: " << gamesPlayed << "/" << gamesNum << "\n Bot: " << score[0] << "\nPlayer: " << score[1];
            continue;
        }

        cout << "Cows: ";
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(usrGuess[j] == botNum[i]){
                    cout << usrGuess[j] << ", ";
                    usrGuess[j] = -2;
                }
            }
        }

        cout << ";\n";

        // bot guess
        if(botBulls != 0 && botCows != 0){
            
        }
        else{
            cout << "My guess for your number is: " << botGuess[0] << botGuess[1] << botGuess[2] << botGuess[3] << "\n";
        }

        cout << "Rate my guess(write the digits I guessed correctly separated by space):\n Bulls: ";

    }
    

    return 0;
}