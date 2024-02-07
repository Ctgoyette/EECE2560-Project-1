#ifndef MASTERMIND_HPP
#define MASTERMIND_HPP

#include <iostream>
#include <random>
#include <vector>
#include "response.hpp"
#include "code.hpp"

using namespace std;

class Mastermind{
    public:
        /**
         * @brief Construct a new Mastermind object. Defaults codeLength to be 5 and codeRange to be 10
         * 
         */
        Mastermind() {codeLength = 5; codeRange = 10;}

        /**
         * @brief Construct a new Mastermind object. User input determines codeLength and codeRange.
         * 
         * @param n Determines codeLength
         * @param m Determines codeRange
         */
        Mastermind(int n, int m) : codeLength(n), codeRange(m) {}

        /**
         * @brief Prints the secret code
         * 
         */
        void printCode();

        /**
         * @brief Contains the main logic of the Mastermind game. Initializes a code, prints it out, and initializes
         * correctCodeResponse for comparison to human guesses. Allows user 10 attempts to guess the code and responds
         * with the numberCorrect and numberIncorrect as a response.
         * 
         */
        void playGame();

        Response correctCodeResponse;
    
    private:
        int codeLength;
        int codeRange;
        Code code = Code(codeLength, codeRange);

        /**
         * @brief Takes in user input one digit at a time, prints out the resulting code object
         * and then returns it
         * 
         * @return Code 
         */
        Code humanGuess();

        /**
         * @brief Creates a response object, then compares the correct code to the guess.
         * Returns the response object
         * 
         * @param guessCode 
         * @return Response 
         */
        Response getResponse(Code guessCode);

        /**
         * @brief Compares guessResponse object to the correct guessResponse
         * 
         * @param guessResponse 
         * @return true If numberCorrect and numIncorrect are equal to one another
         * @return false Otherwise
         */
        bool isSolved(Response& guessResponse);
};

#endif