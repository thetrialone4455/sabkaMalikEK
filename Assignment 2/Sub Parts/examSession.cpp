#include <iostream>
#include <string>
using namespace std;

class ExamSession {
    public:
        string* answers;
        int numAnswers;
        ExamSession(int n = 3) {
            numAnswers = n;
            answers = new string[numAnswers];

            cout << "Enter " << numAnswers << " answers: ";
            for (int i = 0; i < numAnswers; i++) {
                getline(cin, answers[i]);
            }
        }

        ~ExamSession() {
            cout << "Destr invoked"<<endl;
            delete[] answers;   
        }

        void showAnswers() {
            cout << "answers:";
            for (int i = 0; i < numAnswers; i++) {
                cout << answers[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    ExamSession* sessions[2];   

    sessions[0] = new ExamSession(2);
    sessions[1] = new ExamSession(3);

    sessions[0]->showAnswers();
    sessions[1]->showAnswers();

    delete sessions[0];
    delete sessions[1];

    return 0;
}
