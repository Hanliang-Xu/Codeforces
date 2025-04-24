#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_consensus_sum(const vector<int>& vectorA, const vector<int>& vectorB, int length) {
    int sum = -1;

    for (int i = 0; i < length; ++i) {
        if (vectorB[i] != -1) {
            int vector_sum = vectorA[i] + vectorB[i];
            if (sum == -1) {
                sum = vector_sum;
            } else {
                if (vector_sum != sum) {
                    return -1;
                }
            }
        }
    }

    return sum;
}

bool check_minus_one_entries(const vector<int>& vectorA, const vector<int>& vectorB, int length, int k, int consensus_sum) {
    for (int i = 0; i < length; ++i) {
        if (vectorB[i] == -1) {
            if ((vectorA[i] + k < consensus_sum) || (vectorA[i] > consensus_sum))  return false;
        }
    }

    return true;
}

int main() {
    int num_of_test_cases;
    cin >> num_of_test_cases;

    vector<int> results;

    for (int i = 0; i < num_of_test_cases; ++i) {
        int n, k;
        cin >> n >> k;

        vector<int> vectorA;
        vector<int> vectorB;

        for (int j = 0; j < n; ++j) {
            int elem;
            cin >> elem;
            vectorA.push_back(elem);
        }

        for (int j = 0; j < n; ++j) {
            int elem;
            cin >> elem;
            vectorB.push_back(elem);
        }

        bool all_minue_one = all_of(vectorB.begin(), vectorB.end(), [](int x)  { return x == -1; });
        

        if (all_minue_one) {
            int max_elem = *max_element(vectorA.begin(), vectorA.end());
            int min_elem = *min_element(vectorA.begin(), vectorA.end());
            if ((max_elem - min_elem) > k)  results.push_back(0);
            else  results.push_back(k - (max_elem - min_elem) + 1);
        } else {
            int consensus_sum = calculate_consensus_sum(vectorA, vectorB, n);
            if (consensus_sum == -1)  results.push_back(0);
            else {
                bool minus_one_entries = check_minus_one_entries(vectorA, vectorB, n, k, consensus_sum);
                if (minus_one_entries)  results.push_back(1);
                else  results.push_back(0);
            }
        }
    }
    
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}