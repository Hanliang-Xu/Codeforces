#include <iostream>
#include <vector>
#include <utility>
#include <limits>

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


vector<int> create_matching_vector(const vector<int>& A, const vector<int>& B, bool start_from_left) {
    int n = A.size(), m = B.size();
    int default_v = start_from_left ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
    vector<int> results(m, default_v);

    if (start_from_left) {
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (A[i] >= B[j])  results[j++] = i;
        }
    } else {
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
            if (A[i] >= B[j])  results[j--] = i;
        }
    }

    return results;
}


int main() {
    int num_test_cases;
    cin >> num_test_cases;

    vector<int> results(num_test_cases);

    for (int i = 0; i < num_test_cases; ++i) {
        int n, m;
        cin >> n >> m;

        vector<int> vectorA = read_vector(n);
        vector<int> vectorB = read_vector(m);

        vector<int> start_from_left(m);
        vector<int> start_from_right(m);

        start_from_left = create_matching_vector(vectorA, vectorB, true);
        start_from_right = create_matching_vector(vectorA, vectorB, false);
        
        if (start_from_left[m - 1] < n) {
            results[i] = 0;
            continue;
        }

        int result = -1;

        for (int j = 0; j < m; ++j) {
            int l_n = (j > 0) ? start_from_left[j - 1] : -1;
            int r_n = (j < (m - 1)) ? start_from_right[j + 1] : n;

            if (l_n < r_n)  result = (result == -1) ? vectorB[j] : min(result, vectorB[j]);
        }

        results[i] = result;
    }

    for (int result : results) {
        cout << result << endl;
    }
}