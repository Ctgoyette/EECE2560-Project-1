#ifndef CODE_HPP
#define CODE_HPP

#include <iostream>
#include <random>
#include <vector>

using namespace std;


class Code{
    public:

        /**
         * @brief Construct a new Code object
         * 
         * @param n The length of the code vector 
         * @param m The maximum range of any one digit within the code vector
         */
        Code(int n, int m) : codeLength(n), codeRange(m) {}

        /**
         * @brief Checks the number of digits of guessCode that are the same value 
         * and in the same location comapared to the code object calling the function
         * 
         * @param guessCode The code object to compare to the code object calling the function
         * @return int The number of digits that the correct value and in the correct spot
         */
        int checkCorrect(Code guessCode);

        /**
         * @brief Checks the number of digits of guessCode that are the correct value
         * but in the incorrect location comapared to the code object calling the function
         * 
         * @param guessCode 
         * @return int 
         */
        int checkIncorrect(Code guessCode);

        /**
         * @brief Prints out the code vector
         * 
         */
        void printCode();

        /**
         * @brief Get the Code private data member 
         * 
         * @return vector<int> 
         */
        vector<int> getCode();

        /**
         * @brief Set the Code private data member to newCode
         * 
         * @param newCode 
         */
        void setCode(const vector<int> newCode);

        /**
         * @brief Initializes the Code private data member using a random number generator
         * seeded with the current time based on the codeLength and codeRange data members
         * 
         */
        void initCode();

    private:
        int codeLength;
        int codeRange;
        vector<int> thisCode;
};

#endif