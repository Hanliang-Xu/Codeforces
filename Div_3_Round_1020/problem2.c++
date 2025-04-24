#include <iostream>
#include <vector>

using namespace std;


int main() {
    int num_test_cases;
    cin >> num_test_cases;

    vector<vector<int>> results;;
    for (int i = 0; i < num_test_cases; ++i) {
        int n, x;
        cin >> n >> x;

        vector<int> result;

        for (int j = 0; j < x; ++j) {
            result.push_back(j);
        }
        for (int k = (x + 1); k < n; ++k) {
            result.push_back(k);
        }
        
        if (x < n)  result.push_back(x);

        results.push_back(result);
    }

    for (int i = 0; i < results.size(); ++i) {
        vector<int> result = results[i];
        for (int j = 0; j < (result.size() - 1); ++j) {
            cout << result[j] << " ";
        }
        cout << result[result.size() - 1] << endl;
    }

    return 0;
}