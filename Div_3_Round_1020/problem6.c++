#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool is_valid(const vector<int>& binary_vector, int first, int second, int n) {
    return (first >= 0 && second >= 0 && first < n && second < n);
}

bool is_zero(const vector<int>& binary_vector, int first, int second) {
    return (first == second) ? !(binary_vector[second] == 0) : (binary_vector[second] == 0);
}


void insert_point_to_queue(queue<pair<int, int>>& queue_for_explore, vector<vector<int>>& grid, const vector<int>& binary_vector, int first, int second, int n) {
    if (is_valid(binary_vector, first, second, n) && grid[first][second] == 0 && is_zero(binary_vector, first, second)) {
        grid[first][second] = 1;
        queue_for_explore.push({first, second});
    }
}

void update_queue_and_grid(queue<pair<int, int>>& queue_for_explore, vector<vector<int>>& grid, const vector<int>& binary_vector, int first, int second, int n) {
    queue_for_explore.pop();
    insert_point_to_queue(queue_for_explore, grid, binary_vector, first-1, second, n);
    insert_point_to_queue(queue_for_explore, grid, binary_vector, first+1, second, n);
    insert_point_to_queue(queue_for_explore, grid, binary_vector, first, second-1, n);
    insert_point_to_queue(queue_for_explore, grid, binary_vector, first, second+1, n);
}

int bfs_grid(const vector<int>& binary_vector, int n) {
    vector<vector<int>> grid(n, vector<int>(n));

    int cum_max = 0;
    int cum_so_far = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is_zero(binary_vector, i, j) && grid[i][j] == 0) {
                queue<pair<int, int>> queue_for_explore;
                queue_for_explore.push({i, j});
                grid[i][j] = 1;
                while (!queue_for_explore.empty()) {
                    pair<int, int> point = queue_for_explore.front();
                    int first = point.first;
                    int second = point.second;
                    update_queue_and_grid(queue_for_explore, grid, binary_vector, first, second, n);
                    cum_so_far++;
                }
                cum_max = max(cum_so_far, cum_max);
                cum_so_far = 0;
            }
        }
    }

    return cum_max;
}

int main(){
    int num_of_test_cases;
    cin >> num_of_test_cases;
    vector<int> results(num_of_test_cases);
    for (int i = 0; i < num_of_test_cases; ++i) {
        int length;
        cin >> length;
        string binary_string;
        cin >> binary_string;
        vector<int> binary_vector(length);
        for (int j = 0; j < length; ++j) {
            binary_vector[j] = binary_string[j] - '0';
        }
        results[i] = bfs_grid(binary_vector, length);
    }

    for (int i = 0; i < num_of_test_cases; ++i) {
        cout << results[i] << endl;
    }
}