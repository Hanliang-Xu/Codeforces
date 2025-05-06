#include <iostream>
#include <vector>

using namespace std;

int bfs_on_grid(const vector<int>& binary_string) {
    
}

int main(){
    int num_of_test_cases;
    cin >> num_of_test_cases;
    vector<int> results(num_of_test_cases);
    for (int i = 0; i < num_of_test_cases; ++i) {
        int length;
        cin >> length;
        vector<int> binary_string(length);
        for (int j = 0; j < length; ++j) {
            cin >> binary_string[j];
        }
        results[i] = bfs_on_grid(binary_string);
    }

    for (int i = 0; i < num_of_test_cases; ++i) {
        cout << results[i] << endl;
    }
}