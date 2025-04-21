#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> determine_MIT_time(const vector<int>& inputs, int bound) {
    vector<string> outputs = vector<string>(bound);

    for (int i = 0; i < bound; ++i) {
        int power = 1;
        while (inputs[i] > pow(5, power)) {
            power++;
        }

        if (power <= 1){
            outputs[i] = "MIT time";
        } else {
            outputs[i] = "MIT^" + to_string(power) + " time";
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