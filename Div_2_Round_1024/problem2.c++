#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint32_t num_test_cases;
    cin >> num_test_cases;

    vector<bool> results(num_test_cases);

    for (uint32_t i = 0; i < num_test_cases; ++i) {
        uint32_t len;
        cin >> len;

        vector<int> arr(len);
        for (uint32_t j = 0; j < len; ++j) {
            cin >> arr[j];
        }

        int first_number_pos = abs(arr[0]);

        uint32_t count_above_pos(0);

        for (uint32_t j = 1; j < len; ++j) {
            if (abs(arr[j]) > first_number_pos)  count_above_pos++;
        }

        uint32_t threshold = (len - 1) / 2;
        results[i] = (count_above_pos >= threshold) ? true : false;
    }

    for (uint32_t i = 0; i < num_test_cases; ++i) {
        cout << ((results[i] == true) ? "YES" : "NO") << endl;
    }
}