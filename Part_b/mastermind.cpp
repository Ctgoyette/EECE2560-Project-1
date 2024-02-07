#include "mastermind.hpp"
#include "code.hpp"


void Mastermind::playGame(){

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

        // if the user is out of guesses
        else{
            if (i == 9){
                cout << "Sorry, you lost! Better luck next time!" << endl;
            }
        }
    }
    
}


Code Mastermind::humanGuess(){
    // Initializes a container for user input
    vector<int> guessVector;
    int guessDigit;

    // Gets each digit one at a time and adds it to the vector
    for (int i = 0; i < codeLength; i++){
        cout << "Please enter digit " << i+1 << endl;
        cin >> guessDigit;

        // Checks if the previous cin operation failed, indicating that the input was not an integer
        if (cin.fail()){
            cout << "Sorry, that's not an integer! Please enter an integer digit" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--;
        }
        // Checks if the number input is within the range of digits specified at the beginning of the game
        else if (guessDigit < 0 || guessDigit > codeRange-1){
            cout << "Sorry, that number is not in the range of digits. Please enter a number from 0 to " << codeRange << ", not including " << codeRange << "." << endl;
            i--;
        }

        // If no errors are found, only takes in the first input and adds the guess to the guess code
        else{
            cin.ignore(codeRange-1, '\n');
            guessVector.push_back(guessDigit);
        }
    }

    // Creates a code object for the user guess
    Code guessCode(codeLength, codeRange);
    guessCode.setCode(guessVector);
    guessCode.printCode("\n*** Your Guess: ");
    return guessCode;
}


Response Mastermind::getResponse(Code guessCode){
    // Initializes a response to the user guess
    Response guessResponse;
    guessResponse.setNumCorrect(code.checkCorrect(guessCode));
    guessResponse.setNumIncorrect(code.checkIncorrect(guessCode));
    return guessResponse; 
}


bool Mastermind::isSolved(Response& guessResponse){
    return correctCodeResponse == guessResponse;
}


void Mastermind::printCode(){
    code.printCode("Secret Code: ");
}


