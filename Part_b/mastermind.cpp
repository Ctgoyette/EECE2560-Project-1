#include "mastermind.hpp"
#include "code.hpp"


void mastermind::playGame(){

    // Initializes the secret code
    code.initCode();

    // Prints the code for grading
    printCode();
    cout << endl;

    // Sets Response data members for comparison to guessResponse
    correctCodeResponse.setNumCorrect(codeLength); correctCodeResponse.setNumIncorrect(0);
    cout << "You have ten attempts to guess the code. Good luck!" << endl;

    // Loops through each user guess
    for (int i = 0; i < 10; i++){
        cout << 10 - i << " attempts remaining..." << endl;

        // gets a user guess and then gets a response of number correct and number incorrect
        Response userResponse = getResponse(humanGuess());
        cout << userResponse << endl;

        // Checks if the response is the correct response
        if (isSolved(userResponse)){
            cout << "You won!" << endl;
            break;
        }
        else{
            // if the user is out of guesses
            if (i == 9){
                cout << "Sorry, you lost! Better luck next time!" << endl;
            }
        }
    }
    
}


Code mastermind::humanGuess(){
    // Initializes a container for user input
    vector<int> guessVector;
    int guessDigit;

    // Gets each digit one at a time and adds it to the vector
    for (int i = 0; i < codeLength; i++){
        cout << "Please enter digit " << i+1 << endl;
        cin >> guessDigit;
        guessVector.push_back(guessDigit);
    }

    // Creates a code object for the user guess
    Code guessCode(codeLength, codeRange);
    guessCode.setCode(guessVector);
    guessCode.printCode();
    return guessCode;
}


Response mastermind::getResponse(Code guessCode){
    // Initializes a response to the user guess
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


