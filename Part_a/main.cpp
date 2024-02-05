#include "code.hpp"


using namespace std;

int main(){
    Code myCode(5, 7);
    myCode.initCode();
    myCode.printCode();
    Code guess1(5, 7); guess1.setCode({5, 0, 3, 2, 6});
    Code guess2(5, 7); guess2.setCode({2, 1, 2, 2, 2});
    Code guess3(5, 7); guess3.setCode({1, 3, 3, 4, 5});
    cout << "Guess: (5, 0, 3, 2, 6) | Number Correct: " << myCode.checkCorrect(guess1) << " Number Incorrect: " << myCode.checkIncorrect(guess1) << endl;
    cout << "Guess: (2, 1, 2, 2, 2) | Number Correct: " << myCode.checkCorrect(guess2) << " Number Incorrect: " << myCode.checkIncorrect(guess2) << endl;
    cout << "Guess: (1, 3, 3, 4, 5) | Number Correct: " << myCode.checkCorrect(guess3) << " Number Incorrect: " << myCode.checkIncorrect(guess3) << endl;
}