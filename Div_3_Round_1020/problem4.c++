#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const vector<int> read_vector(int length) {
    vector<int> results;

    for (int i = 0; i < length; ++i) {
        int result;
        cin >> result;
        results.push_back(result);
    }

    return results;
}

pair<const vector<int>, int> find_default_matching(const vector<int>& vectorA, const vector<int>& vectorB, int n, int m) {
    vector<int> results(m, -1);

    int pos = 0;

    for (int i = 0; i < n && pos < m; ++i) {
        if (vectorA[i] >= vectorB[pos]) {
            results[pos] = i;
            pos++;
        }
    }

    return {results, pos};
}

bool check_succeed_with_k(const vector<int>& vectorA, const vector<int>& vectorB, int n, int m, int vectorA_start, int vectorB_start) {
    int pos = vectorB_start;
    if (pos == m)  return true;

    for (int i = vectorA_start; i < n; ++i) {
        // if (vectorA_start == 2 && vectorB_start == 2) {
        //     cout << "DEBUG (2,2): We have vectorA[i] = " << vectorA[i] << ", and vectorB[pos] = " << vectorB[pos] << endl;
        // }
        if (vectorA[i] >= vectorB[pos]) {
            pos++;
            if (pos == m)  return true;
        }
    }

    return (pos == m);
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    vector<int> results;

    for (int i = 0; i < num_test_cases; ++i) {
        int n, m;
        cin >> n >> m;

        vector<int> vectorA = read_vector(n);
        vector<int> vectorB = read_vector(m);

        // brute force: try to satisfy b_i with k one by one with saving the places.

        auto [default_matching, last_pos] = find_default_matching(vectorA, vectorB, n, m);

        if (last_pos == m)  {
            results.push_back(0);
            continue;
        }

        int min_k = -1;

        //cout << "DEBUG: We tried check succeed with parameters: 0, 1;" << endl;
        if (check_succeed_with_k(vectorA, vectorB, n, m, 0, 1)) {
            min_k = vectorB[0];
        }

        for (int j = 1; j < (last_pos + 1); ++j) {
            //cout << "DEBUG: We tried check succeed with parameters: " << default_matching[j - 1] + 1 << ", " << j+1 << ";" << endl;

            if ((min_k == -1 || vectorB[j] < min_k) && check_succeed_with_k(vectorA, vectorB, n, m, default_matching[j - 1] + 1, j + 1)) {
                if ((min_k == -1) || (vectorB[j] < min_k))  min_k = vectorB[j];
            }
        }

        results.push_back(min_k);
    }

    for (int result : results) {
        cout << result << endl;
    }
}