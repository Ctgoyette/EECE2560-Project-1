#ifndef CODE_HPP
#define CODE_HPP

#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Code{
    public:
        Code(int n, int m) : codeLength(n), codeRange(m) {}
        int checkCorrect(const Code& guessCode);
        int checkIncorrect(const Code& guessCode);
        void printCode();
        void setCode(const vector<int> newCode);
        void initCode();
    private:
        int codeLength;
        int codeRange;
        vector<int> thisCode;
};

#endif