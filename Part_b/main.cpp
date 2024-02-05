#include <iostream>
#include "mastermind.hpp"

using namespace std;

int main(){
    cout << "Please enter the code length (n) and the range of digits (m) separated by a space" << endl;
    int n, m;
    cin >> n >> m;
    mastermind newGame(n, m);
    newGame.playGame();
}