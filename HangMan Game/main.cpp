#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cctype>

using namespace std;

//Function to select a word from a pool of words
string listOfWords() {
    vector<string> words = {"Chivalrous", "Breathe", "Terrify", "Please", "Bizarre", "Parsimonious", "Tense", "Please", "Accidental"};
    int n = words.size();
    int word_index = rand() % n;
    return words[word_index];

}

//Function to print the hidden word after each try
void print(const vector<char>& res, int& tries) {
    for(char ch : res) {
        cout << ch << ' ';
    }
    cout << "\t\tTries: " << tries <<endl;
    return;
}

int main() {
    srand(time(0)); //To ensure different words are chosen each time
    string word = listOfWords();
    cout << "\tGame Starts\n";
    //cout << word << endl;
    vector<char> res;
    for(char ch : word) {
        res.push_back('_');
    }
    int tries = 5, correct = 0;
    print(res, tries);
    bool win = false;
    while(tries > 0) {
        char ch;
        cout <<"Guess a Character: ";
        cin >> ch;
        int flag = 0;
        if(!isalpha(ch)) {  // To ensure the input is a valid character
            cout << "Enter a valid Character!" << endl;
            tries--;
            print(res, tries);
            continue;
        }
        ch = tolower(ch);
        for(int i = 0; i < word.size(); i++) {
            if(tolower(word[i]) == ch && res[i] == '_') {
                flag = 1;
                correct++;
                res[i] = word[i];  // Preserve original case of the word
                break;
            }
        }
        if(flag == 0)   tries--;
        print(res, tries);
        if(correct == word.size()) {//Winning Condition
            win = true;
            break;
        }
    }
    if(win) {
        cout << "Congratulations! You have guessed the word correctly.";
    }
    else{
        cout << "Better luck next time.";
    }
    return 0;
}
