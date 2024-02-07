#include "response.hpp"

ostream& operator<< (ostream& out, const Response& outputResponse){
    out << "*** Mastermind Guess Response: " << outputResponse.numCorrect << "," << outputResponse.numIncorrect << endl;
    return out;
}

bool operator== (const Response& actualResponse, const Response& comparisonResponse) {
    bool cond1 = actualResponse.numCorrect == comparisonResponse.numCorrect;
    bool cond2 = actualResponse.numIncorrect == comparisonResponse.numIncorrect;
    return cond1 && cond2;
}