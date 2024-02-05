#include "code.hpp"
#include <time.h>

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