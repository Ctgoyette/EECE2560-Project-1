#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Response{
    public:
        /**
         * @brief Construct a new Resonse object. Initializes the number of correct and incorrect digits to 0
         * 
         */
        Response() : numCorrect(0), numIncorrect(0) {}

        /**
         * @brief Sets the number of digits correctly guessed by the user
         * 
         * @param correct Number of correctly guessed digits
         */
        void setNumCorrect(int correct) {numCorrect = correct;}

        /**
         * @brief Sets the number of digits guessed by the user that are in the code, but in the wrong location
         * 
         * @param incorrect Number of incorrectly guessed digits
         */
        void setNumIncorrect(int incorrect) {numIncorrect = incorrect;}

        /**
         * @brief Gets the number of digits correctly guessed by the user
         * 
         * @return int
         */
        int getNumCorrect() const {return numCorrect;}

        /**
         * @brief Gets the number of digits incorrectly guessed by the user
         * 
         * @return int
         */
        int getNumIncorrect() const;

        /**
         * @brief Overloads the '==' operator to allow for direct comaprison of Response objects
         * 
         * @return bool
         */
        friend bool operator== (const Response& actualResponse, const Response& comparisonResponse);

        /**
         * @brief Overloads the '<<' operator to allow for direct printing of Response objects
         * 
         * @return ostream&
         */
        friend ostream& operator<< (ostream& out, const Response& outputResponse);

    private:
        int numCorrect;
        int numIncorrect;
};
