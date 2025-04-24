#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    vector<int> results;

    for (int i = 0; i <num_test_cases; ++i) {
        int string_length;
        cin >> string_length;

        string code;
        cin >> code;

        int num_of_one = 0;
        int num_of_zero = 0;

        for (int j = 0; j < string_length; ++j) {
            if (code[j] == '1') {
                num_of_one++;
            } else {
                num_of_zero++;
            }
        }

        int result = num_of_one * (num_of_one - 1) + num_of_zero * (num_of_one + 1);

        results.push_back(result);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}