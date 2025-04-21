#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> break_into_M(const string& word) {
    string accum = "";
    vector<string> results;

    int length = word.size();

    for (int i = 0; i < length; ++i) {
        if (word[i] == 'M') {
            if (! accum.empty()) {
                results.push_back(accum);
            }
            accum = "M";
        } else {
            accum += word[i];
        }
    }

    if (! accum.empty()) {
        results.push_back(accum);
    }

    return results;
}

bool verify_individual_word(const string& input) {
    if (input.size() % 2 != 1) {
        return false;
    }
    if (input[0] != 'M') {
        return false;
    }
    if (input.size() < 3) {
        return false;
    }

    for (int i = 0; i < ((input.size() - 1) / 2); ++i) {
        if (input[1 + 2 * i] != 'I' | input[2 + 2 * i] != 'T') {
            return false;
        }
    }

    return true;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    vector<string> words;

    for (int i = 0; i < num_test_cases; ++i) {
        int length;
        cin >> length;

        string word;
        cin >> word;

        words.push_back(word);
    }

    for (int i = 0; i < num_test_cases; ++i) {
        bool MIT_word = true;

        vector<string> words_start_with_M = break_into_M(words[i]);

        for (int i = 0; i < words_start_with_M.size(); ++i) {
            if (! verify_individual_word(words_start_with_M[i])) {
                cout << "NO" << endl;
                MIT_word = false;
                break;
            }
        }

        if (MIT_word) {
            cout << "YES" << endl;
        }
        
    }
    
}