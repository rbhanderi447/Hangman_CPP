#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main(){

    cout << "Welcome To Hangman!" << endl;

    random_device rd;
    mt19937 gen(rd());

    vector<string> words = {
    "apple", "banana", "orange", "grape",
    "tiger", "lion", "elephant", "monkey",
    "computer", "keyboard", "mouse", "screen",
    "school", "college", "teacher", "student",
    "rocket", "planet", "galaxy", "meteor",
    "guitar", "piano", "drums", "violin",
    "football", "cricket", "tennis", "basketball",
    "mountain", "river", "forest", "desert"
    };

    uniform_int_distribution<int> dist(0, words.size() - 1);
    
    string word = words[dist(gen)];
    cout << "Word: ";
    string toGuess;
    for(int i = 0;i<word.size();i++){toGuess += "_";}
    cout << toGuess << endl;

    int lives = 5;

    while(true){
        cout << "Lives: " << lives;
        for(int i = 0;i<lives;i++){
            cout << "❤️";
        }
        cout << endl;
        cout << "Guess a letter: ";
        char guess;
        cin >> guess;
  
    
        for(int i = 0;i<word.size();i++){
            if((word[i] == guess) && (toGuess[i] != guess)){
                toGuess[i] = guess;
                break;
            }
            if((word[i] != guess) && (i == word.size() - 1)){lives--;}
        }
        cout << "Word: " << toGuess << endl;

        if(lives == 0){
            cout << "You Lost!" << endl;
            cout << "The word was: " << word << endl;
            cout << "Wanna play again? (y/n)" << endl;
            char again;
            cin >> again;
            if(again == 'y'){
                lives = 5;
                word = words[dist(gen)];
                toGuess.clear();
                for(int i = 0;i<word.size();i++){toGuess += "_";}
                cout << "Word: " << toGuess << endl;
                continue;
            }
            else{
                break;
            }
        }
        if(toGuess == word){
            cout << "You Won!" << endl;
            break;
        }
    }


    return 0; 
}
