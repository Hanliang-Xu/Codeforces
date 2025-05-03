#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search_manual(const vector<int>& arr, int l, int r, int k) {
    if (l > r)  return -1;
    int m = (l + r) / 2;
    int mid_val = arr.at(m);

    if (mid_val == k)  return m;
    else if (mid_val < k)  return binary_search_manual(arr, m + 1, r, k);
    else return binary_search_manual(arr, l, m - 1, k);
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    vector<vector<int>> results(num_test_cases);

    for (int i = 0; i < num_test_cases; ++i) {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int j = 0; j < n; ++j)  cin >> arr[j];

        vector<int> result(q);
        for (int j = 0; j < q; ++j) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            if (binary_search(arr.begin() + l, arr.begin() + r + 1, k))  result[j] = 0;
            else result[j] = -1;
        }

        results[i] = result;
    }

    for (int i = 0; i < num_test_cases; ++i) {
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << " ";
        }

        cout << endl;
    }
}