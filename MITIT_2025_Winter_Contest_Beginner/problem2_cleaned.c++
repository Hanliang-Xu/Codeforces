#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split_into_M_blocks(const string& word) {
    string accum = "";
    vector<string> results;

    for (char ch : word) {
        if (ch == 'M') {
            if (! accum.empty())  results.push_back(accum);
            accum = "M";
        } else {
            accum += ch;
        }
    }

    if (! accum.empty()) results.push_back(accum);
    return results;
}

bool is_valid_MIT_segment(const string& input) {
    if (input.size() < 3 || input.size() % 2 == 0 || input[0] != 'M')  return false;

    for (int i = 1; i < input.size(); i += 2) {
        if (input[i] != 'I' || input[i+1] != 'T')  return false;
    }

    return true;
}

bool is_MIT_word(const string& word) {
    for (const string& segment : split_into_M_blocks(word)) {
        if (! is_valid_MIT_segment(segment))  return false;
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

    for (const string& word : words) {
        cout << (is_MIT_word(word) ? "Yes" : "No") << endl;
    }
}