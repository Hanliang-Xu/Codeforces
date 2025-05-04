#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_swaps_for_success(const vector<int>& arr, int l, int r, int k, int pos_of_k,
                        int accum_small, int accum_large,
                        int allowance_smaller_than_k, int allowance_larger_than_k) {
    if (l > r) {
        return -1;
    }
    int m = (l + r) / 2;

    if (m == pos_of_k) {
        int min_val = min(accum_small, accum_large);
        int max_val = max(accum_small, accum_large);
        if (accum_small > accum_large && allowance_larger_than_k < 0) {
            return -1;
        }
        if (accum_small < accum_large && allowance_smaller_than_k < 0) {
            return -1;
        }
        return 2 * max(accum_small, accum_large);
    }
    else if (m < pos_of_k) {
        int bad_index = ((arr[m] - 1) < k) ? 0 : 1;
        return min_swaps_for_success(arr, m + 1, r, k, pos_of_k, accum_small, accum_large + bad_index, allowance_smaller_than_k - 1, allowance_larger_than_k);
    }
    else {
        int bad_index = (arr[m] > k) ? 0 : 1;
        return min_swaps_for_success(arr, l, m - 1, k, pos_of_k, accum_small + bad_index, accum_large, allowance_smaller_than_k, allowance_larger_than_k - 1);
    }
}

const vector<int> fill_pos(const vector<int>& arr, int length) {
    vector<int> results(length);
    for (int i = 0; i < length; ++i) {
        results[arr[i] - 1] = i;
    }
    return results;
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
        vector<int> pos = fill_pos(arr, n);

        
        for (int j = 0; j < q; ++j) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            k--;

            int pos_of_k = pos[k];
            int total_smaller = k;
            int total_larger = n - 1 - k;

            if (pos_of_k < l || pos_of_k > r)  result[j] = -1;
            else  result[j] = min_swaps_for_success(arr, l, r, k, pos_of_k, 0, 0, total_smaller, total_larger);
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