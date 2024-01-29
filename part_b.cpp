#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Response{
    public:
        Response() : numCorrect(0), numIncorrect(0) {}
        void setNumCorrect(int correct) {numCorrect = correct;}
        void setNumIncorrect(int incorrect) {numIncorrect = incorrect;}
        int getNumCorrect() const {return numCorrect;}
        int getNumIncorrect() const;
        friend bool operator== (const Response& actualResponse, const Response& comparisonResponse) {return actualResponse.numCorrect == comparisonResponse.numCorrect && actualResponse.numIncorrect == comparisonResponse.numIncorrect;}
        friend ostream& operator<< (ostream& out, const Response& outputResponse);

    private:
        int numCorrect;
        int numIncorrect;
};

class mastermind{
    public:
        mastermind() {codeLength = 5; codeRange = 10;}
        mastermind(int n, int m) : codeLength(n), codeRange(m) {}
        Response correctCodeResponse;
        void getCode();
        void playGame();
    
    private:
        int codeLength;
        int codeRange;
        vector<int> code;
        vector<int> humanGuess();
        Response getResponse(const vector<int>& guessCode);
        bool isSolved(Response& guessResponse);
};

void mastermind::playGame(){
    srand(time(NULL));
    for (int i = 0; i < codeLength; i++){
        int codeDigit = rand() % codeRange;
        code.push_back(codeDigit);
    }
    this->getCode();
    cout << endl;
    correctCodeResponse.setNumCorrect(codeLength); correctCodeResponse.setNumIncorrect(0);
    cout << "You have ten attempts to guess the code. Good luck!" << endl;
    for (int i = 0; i < 10; i++){
        Response& userResponse = this->getResponse(this->humanGuess());
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

vector<int> mastermind::humanGuess(){
    vector<int> guess;
    int guessDigit;
    for (int i = 0; i < codeLength; i++){
        cout << "Please enter digit " << i+1 << endl;
        cin >>guessDigit;
        guess.push_back(guessDigit);
    }
    return guess;

}

Response mastermind::getResponse(const vector<int>& guessCode){
    int numRight = 0;
    int numWrong = 0;
    vector<int> codeNoDuplicates;
    cout << endl;
    for (int i = 0; i < codeLength; i++){
        if (code[i] == guessCode[i]){
            numRight++;
        }
        else{
            bool duplicateDetected = 0;
            for (int j = 0; j < codeNoDuplicates.size(); j++){
                if (code[i] == codeNoDuplicates[j]){
                    duplicateDetected = 1;
                    break;
                }
            }
            if (!duplicateDetected){
                codeNoDuplicates.push_back(code[i]);
                numWrong++;
            }
        }
    }

    Response guessResponse;
    guessResponse.setNumCorrect(numRight);
    guessResponse.setNumIncorrect(numWrong);
    return guessResponse; 
}

bool mastermind::isSolved(Response& guessResponse){
    return correctCodeResponse == guessResponse;
}

void mastermind::getCode(){
    cout << "Secret Code: ";
    cout << code[0];
    for (int i = 1; i < codeLength; i++){
        cout << ", " << code[i];
    }
    cout << endl;
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