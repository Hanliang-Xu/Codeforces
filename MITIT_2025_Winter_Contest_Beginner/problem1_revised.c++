#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

vector<long long> precompute_power_of_5(long long upper_bound) {
    vector<long long> powers;

    long long value = 5;
    while (value < upper_bound) {
        powers.push_back(value);
        value *= 5;
    }

    return powers;
}

// int upper_bound(const vector<long long>& powers, int target) {
//     int low = 0;
//     int high = powers.size();

//     while (low < high) {
//         int mid = low + (high - low) / 2;

//         if (powers[mid] < target) {
//             low = mid + 1;
//         } else {
//             high = mid;
//         }
//     }

//     return low;
// }

vector<string> determine_MIT_time(const vector<int>& inputs, int bound) {
    vector<string> outputs;
    vector<long long> powers_of_5 = precompute_power_of_5(1e9);

    for (int input : inputs) {
        if (input <= 5) {
            outputs.push_back("MIT time");
            continue;
        } else {
            int index = lower_bound(powers_of_5.begin(), powers_of_5.end(), input) - powers_of_5.begin();
            outputs.push_back("MIT^" + to_string(index + 1) + " time");
        }
    }

    return outputs;
}

int main() {
    int num_test_cases;
    
    cin >> num_test_cases;
    
    vector<int> inputs(num_test_cases);
    
    for (int i = 0; i < num_test_cases; ++i) {
        cin >> inputs[i];
    }
    
    vector<string> outputs = determine_MIT_time(inputs, num_test_cases);
    
    for (int i = 0; i < num_test_cases; ++i) {
        cout << outputs[i] << endl;
    }
}