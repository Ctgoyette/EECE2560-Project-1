#include <iostream>
#include <random>
#include <vector>


using namespace std;

class Response{
    public:

        Response() : numCorrect(0), numIncorrect(0) {}
        void setNumCorrect(int correct) {numCorrect = correct;}
        void setNumIncorrect(int incorrect) {numIncorrect = incorrect;}
        int getNumCorrect() const {return numCorrect;}
        int getNumIncorrect() const;
        friend bool operator== (const Response& actualResponse, const Response& comparisonResponse);
        friend ostream& operator<< (ostream& out, const Response& outputResponse);

    private:
        int numCorrect;
        int numIncorrect;
};
