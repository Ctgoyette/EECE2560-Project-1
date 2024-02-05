#include <iostream>
#include "mastermind.hpp"

using namespace std;

int main(){
    cout << "Please enter the code length (n) and the range of digits (m) separated by a space" << endl;

    // Checks that input for n and m are positive integers and alerts user if not
    int n, m;
    bool valid = false;
    while (not valid){
        cin >> n >> m;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n' );
            cout << "Invalid input, values must be positive integers" << endl; 
        }
        else if(n <= 0 || m <= 0){
            cout << "Invalid input, values must be positive integers" << endl; 
        }
        else{
            valid = true;
        }
    }

    // Initializes the Mastermind object and 
    Mastermind newGame(n, m);
    newGame.playGame();
}