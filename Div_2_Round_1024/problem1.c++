#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint32_t num_test_cases;
    cin >> num_test_cases;

    uint32_t n, m, p, q;
    vector<bool> results(num_test_cases);

    for (uint32_t i = 0; i < num_test_cases; ++i) {
        cin >> n >> m >> p >> q;

        if ((n % p) == 0) {
            results[i] = ((m % q == 0) && (n / p) == (m / q));
        } else {
            results[i] = true;
        }
    }

    for (uint32_t i = 0; i < num_test_cases; ++i) {
        cout << ((results[i]) ? "YES" : "NO") << "\n";
    }
}