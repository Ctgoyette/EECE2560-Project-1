#include "part_b.hpp"

void mastermind::playGame(){
    code.initCode();
    printCode();
    cout << endl;
    correctCodeResponse.setNumCorrect(codeLength); correctCodeResponse.setNumIncorrect(0);
    cout << "You have ten attempts to guess the code. Good luck!" << endl;
    for (int i = 0; i < 10; i++){
        Response& userResponse = getResponse(humanGuess());
        cout << userResponse;
        if (isSolved(userResponse)){
            cout << "You won!" << endl;
            break;
        }
        else{
            if (i == 9){
                cout << "Sorry, you lost! Better luck next time!" << endl;
            }
        }
    }
    
}

Code& mastermind::humanGuess(){
    vector<int> guessVector;
    int guessDigit;
    for (int i = 0; i < codeLength; i++){
        cout << "Please enter digit " << i+1 << endl;
        cin >>guessDigit;
        guessVector.push_back(guessDigit);
    }
    Code guessCode(codeLength, codeRange);
    guessCode.setCode(guessVector);
    return guessCode;

}

Response mastermind::getResponse(const Code& guessCode){
    Response guessResponse;
    guessResponse.setNumCorrect(code.checkCorrect(guessCode));
    guessResponse.setNumIncorrect(code.checkIncorrect(guessCode));
    return guessResponse; 
}

bool mastermind::isSolved(Response& guessResponse){
    return correctCodeResponse == guessResponse;
}

void mastermind::printCode(){
    code.printCode();
}

ostream& operator<< (ostream& out, const Response& outputResponse){
    out << "Mastermind Guess Response: " << outputResponse.numCorrect << "," << outputResponse.numIncorrect << endl;
    return out;
}

int main(){
    cout << "Please enter the code length (n) and the range of digits (m) separated by a space" << endl;
    int n, m;
    cin >> n >> m;
    mastermind newGame(n, m);
    newGame.playGame();
}