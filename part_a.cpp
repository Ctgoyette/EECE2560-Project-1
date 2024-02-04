#include "part_a.hpp"

void Code::initCode(){
    srand(time(NULL));
    for (int i = 0; i < codeLength; i++){
        int codeDigit = rand() % codeRange;
        thisCode.push_back(codeDigit);
    }
}

int Code::checkCorrect(const Code& guessCode){
    int numCorrect = 0;
    for (int i = 0; i < codeLength; i++){
        if (thisCode[i] == guessCode.thisCode[i]){
            numCorrect++;
        }
    }
    return numCorrect; 
}

int Code::checkIncorrect(const Code& guessCode){
    int numIncorrect = 0;
    vector<int> codeNoDuplicates;
    for (int i = 0; i < codeLength; i++){
        if (thisCode[i] != guessCode.thisCode[i]){
            bool duplicateDetected = 0;
            for (int j = 0; j < codeNoDuplicates.size(); j++){
                if (thisCode[i] == codeNoDuplicates[j]){
                    duplicateDetected = 1;
                    break;
                }

            }
            if (!duplicateDetected){
                codeNoDuplicates.push_back(thisCode[i]);
                for (int k = 0; k < codeLength; k++){
                    if (codeNoDuplicates.back() == guessCode.thisCode[k]){
                        numIncorrect++;
                        break;
                    }
                }
            }
        }
    }

    return numIncorrect; 
}

void Code::printCode(){
    cout << "Secret Code: " << thisCode[0];
    for (int i = 1; i < codeLength; i++){
        cout << "," << thisCode[i];
    }
    cout << endl;
}

void Code::setCode(const vector<int> newCode){
    thisCode = newCode;
}

int main(){
    Code myCode(5, 7);
    myCode.initCode();
    myCode.printCode();
    Code guess1(5, 7); guess1.setCode({5, 0, 3, 2, 6});
    Code guess2(5, 7); guess2.setCode({2, 1, 2, 2, 2});
    Code guess3(5, 7); guess3.setCode({1, 3, 3, 4, 5});
    cout << "Guess: (5, 0, 3, 2, 6) | Number Correct: " << myCode.checkCorrect(guess1) << " Number Incorrect: " << myCode.checkIncorrect(guess1) << endl;
    cout << "Guess: (2, 1, 2, 2, 2) | Number Correct: " << myCode.checkCorrect(guess2) << " Number Incorrect: " << myCode.checkIncorrect(guess2) << endl;
    cout << "Guess: (1, 3, 3, 4, 5) | Number Correct: " << myCode.checkCorrect(guess3) << " Number Incorrect: " << myCode.checkIncorrect(guess3) << endl;
}