#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> // printf, scanf, puts, NULL
#include <stdlib.h> // strand, rand
#include <time.h> // time
using namespace std;

void mainMenu(vector<string> phrases);
void playGame(vector<string> phrases);
string answerLine(vector<string> phrases);
// displays hangman ASCII art for each incorrect guess
void hangMan(int numIncorrect, string answerLine);

int main() {
    vector<string> phrases = {"the best is yet to come", "courtesy is contagious", "practice makes perfect"};

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
    // used for the player to return back to the menu after veiwing rules
    char back = 0;
    // checks if the player added a word or a phrase
    bool isPhrase = false;
    string word = "";

    system("clear");
    cout << "MAIN MENU" << endl;
    cout << "1. play game" << endl;
    cout << "2. add word or phrase" << endl;
    cout << "3. rules" << endl;
    cout << "4. exit" << endl;
    cout << endl;
    cout << "Please select an option by entering a number:";
    cin >> choice;

    switch (choice) {
        case 1:
            playGame(phrases);
        break;
        
        case 2:
            cout << "Enter the word or phrase you would like to add: ";
            cin >> word;
            phrases.push_back(word);
            if (word.length() < 5) {
                cout << "Please enter a word or phrase that is at least 5 characters long." << endl;
                cout << "Enter a word or phrase: ";
                cin >> word;
                phrases.push_back(word);
            }

            for (int i = 0; i < word.length(); i++) {
                if (word[i] == ' ') {
                    isPhrase = true;
                }
            }

            if (isPhrase == true) {
                cout << "The phrase you entered has been successfully added." << endl;
            } else {
                cout << "The word you entered has been successfully added.";
            }
            
        break;

        case 3:
            system("clear");
            cout << endl;
            cout << "RULES OF HANGMAN" << endl;
            cout << "1. A random word or phrase will be displayed" << endl
            << "2. You must guess the word or phrase by inputting a letter" << endl
            << "3. If you guess incorrectly, a body part will be added to the man" << endl
            << "4. When the man is fully formed, the game is over. YOU LOSE" << endl
            << "5. If you guess the word or phrase before the man is fully formed, YOU WIN" << endl
            << endl << "Press 'b' to go back to the menu" << endl;
            cin >> back;
            if (back == 'b') {
                mainMenu(phrases);
            }
        break;

        default:
            cout << "That isn't an option." << endl;
    }
}

void playGame(vector<string> phrases) {
    srand(time(NULL)); // generate seed for rand()
    int randomElement = rand() % phrases.size();

    const string answer = phrases[randomElement];
    string answerLine = "";
    string lettersGuessed = "";
    bool correct = false;
    bool letterFound = false;
    char guess = 0;
    int numIncorrect = 0;

    cout << R"(            
            ___________________
            |                  |
            |                  |
            |
            |
            |
            |
            |____________________________________)"
    << endl;

    // create '_' for each letter in phrase
    for (int i = 0; i < int(answer.length()); i++) {
        if ((answer[i]) == ' ') {
            answerLine += ' ';
        }
        else
        {
            answerLine += '_';
        }
    }

    cout << answerLine << endl;

    while (correct == false) {
        letterFound = false;
        cout << "Please enter a letter: ";
        cin >> guess;
        // checks if letter has already been guessed
        for (int i = 0; i < lettersGuessed.length(); i++) {
            if (lettersGuessed[i] == guess) {
                cout << "You already guessed the letter '" << guess << "'! Please enter a different letter: ";
                cin >> guess;
            }
        }
        
        // replaces '_' with letter guessed if its correct
        for (int i = 0; i < int(answer.length()); i++) {
            for (int k = 0; k < int(answer.length()); k++) {
                if (answer[k] == guess) {
                    letterFound = true;
                    answerLine[k] = guess;
                }
            }
        }
        
        if (letterFound == false) {
            numIncorrect += 1;
        }

        if (answerLine == answer) {
            cout << "Congratulations! You win!" << endl;
            correct = true; 
            exit;
        }

        hangMan(numIncorrect, answerLine);
        // cout << answerLine << endl;
        lettersGuessed += guess;
    }

}

// depending on the amount of incorrect guesses display a diffent hangman
void hangMan(int numIncorrect, string answerLine) {
    if (numIncorrect == 0) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |
                |
                |
                |
                |____________________________________)"
        << endl;

        cout << answerLine << endl;
        return;
    }

    else if (numIncorrect == 1) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |
                |
                |
                |____________________________________)"
        << endl;
        cout << answerLine << endl;
        return;
    }

    else if (numIncorrect == 2) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |                  |
                |
                |
                |____________________________________)"
        << endl;
        cout << answerLine << endl;

        return;
    }

    else if (numIncorrect == 3) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |                 /|
                |
                |
                |____________________________________)"
        << endl;
        cout << answerLine << endl;

        return;
    }

    else if (numIncorrect == 4) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |                 /|\
                |
                |
                |____________________________________)"
        << endl;
        cout << answerLine << endl;

        return;
    }

    else if (numIncorrect == 5) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |                 /|\
                |                  |
                |
                |____________________________________)"
        << endl;
        cout << answerLine << endl;

        return;
    }

    else if (numIncorrect == 6) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |                 /|\
                |                  |
                |                 /
                |____________________________________)"
        << endl;
        cout << answerLine << endl;

        return;
    }

    else if (numIncorrect == 7) {
        system("clear");
        cout << R"(            
                ___________________
                |                  |
                |                  |
                |                  @
                |                 /|\
                |                  |
                |                 / \
                |____________________________________)"
        << endl;
        cout << answerLine << endl;

        cout << "GAME OVER!" << endl;
        exit;
    }

    else return;

}