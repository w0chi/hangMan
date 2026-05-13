#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> // printf, scanf, puts, NULL
#include <stdlib.h> // strand, rand
#include <time.h> // time
using namespace std;

void mainMenu(vector<string> phrases);
void playGame(vector<string> phrases);

int main() {
    vector<string> phrases = {"THE BEST IS YET TO COME", "COURTESY IS CONTAGIOUS", "PRACTICE MAKES PERFECT"};

    cout << R"(
             {}    {}      {}      {}    {}    {}{}{}    {}    {}      {}      {}    {}
             {}    {}    {}  {}    {}{}  {}   {}         {}{}{}{}    {}  {}    {}{}  {}
             {}{}{}{}   {}{}{}{}   {} {} {}  {}   {}{}{} {} {} {}   {}{}{}{}   {} {} {}
             {}    {}  {}      {}  {}  {}{}   {}    {}   {}    {}  {}      {}  {}  {}{}
             {}    {} {}        {} {}    {}    {}{}{}    {}    {} {}        {} {}    {}

             ___________________
             |                  |
             |                  |
             |                  @
             |                 /|\
             |                  |
             |                 / \
             |____________________________________
            )" << endl;

    mainMenu(phrases);
    return 0;
}

void mainMenu(vector<string> phrases) {
    int choice = 0;
    string word = "";

    cout << "1. play game" << endl;
    cout << "2. add word or phrase" << endl;
    cout << "3. rules" << endl;
    cout << "4. exit" << endl;
    cout << "Please select an option by entering a number:";
    cin >> choice;

    switch (choice) {
        case 1:
            playGame(phrases);
            //create game function that displays empty hangman with _ underneath
        break;
        
        case 2:
            phrases.push_back(word);
        break;

        case 3:
            return;
        break;

        default:
            cout << "That isn't an option." << endl;
    }
}

void playGame(vector<string> phrases) {
    srand(time(NULL)); // generate seed for rand()

    int randomElement = rand() % phrases.size();
    const string answer = phrases[randomElement];

    for (int i = 0; i < int(answer.length()); i++) {
        if ((answer[i]) == ' ') {
            cout << ' ';
        }
        else {cout << '_';}
    }


}

void hangMan()