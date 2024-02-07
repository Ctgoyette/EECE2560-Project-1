#include "code.hpp"
#include <time.h>

void Code::initCode(){
    // Sets the seed based on current time
    srand(time(NULL));
    // Randomly generates one digit at a time and places it in the code vector
    for (int i = 0; i < codeLength; i++){
        int codeDigit = rand() % codeRange;
        thisCode.push_back(codeDigit);
    }
}


int Code::checkCorrect(Code guessCode){
    int numCorrect = 0;
    vector<int> guessVec;
    guessVec = guessCode.getCode();
    
    // Compares the user guess to the code one digit at a time
    for (int i = 0; i < codeLength; i++){

        // Increments numCorrect when they are equal
        if (thisCode[i] == guessVec[i]){
            numCorrect++;
        }
    }
    return numCorrect; 
}


int Code::checkIncorrect(Code guessCode){
    int numIncorrect = 0;
    vector<int> codeNoDuplicates;
    vector<int> guessVec = guessCode.getCode();

    // Iterates over length of the secret code
    for (int i = 0; i < codeLength; i++){
        
        // Checks to see if the current guess digit matches the current game code digit
        if (thisCode[i] != guessVec[i]){
            bool duplicateDetected = 0;

            // Iterates until a duplicate value is found or the for loop ends
            for (int j = 0; j < codeNoDuplicates.size(); j++){
                if (thisCode[i] == codeNoDuplicates[j]){
                    duplicateDetected = 1;
                    break;
                }

            }

            // If no duplicates are detected, adds the current guess digit to the temporary code vector and checks if the current secret code digit is in the user guess
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

void Code::printCode(string codeType){
    cout << codeType << thisCode[0];
    for (int i = 1; i < codeLength; i++){
        cout << "," << thisCode[i];
    }
    cout << endl;
}


void Code::setCode(const vector<int> newCode){
    thisCode = newCode;
}


vector<int> Code::getCode(){
    return thisCode;
}