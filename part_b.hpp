#ifndef PART_B_HPP
#define PART_B_HPP

#include <iostream>
#include <random>
#include <vector>

#include "part_a.hpp"

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
        void printCode();
        void playGame();
    
    private:
        int codeLength;
        int codeRange;
        Code code = Code(codeLength, codeRange);
        Code& humanGuess();
        Response getResponse(const Code& guessCode);
        bool isSolved(Response& guessResponse);
};


#endif