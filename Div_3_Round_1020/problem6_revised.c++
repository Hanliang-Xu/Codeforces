#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class Transition { ZeroToOne, ZeroToZero, OneToZero, OneToOne };

constexpr inline Transition classify(int prev, int curr) noexcept {
    if (prev == 0 && curr == 1)  return Transition::ZeroToOne;
    if (prev == 0 && curr == 0)  return Transition::ZeroToZero;
    else if (prev == 1 && curr == 0)  return Transition::OneToZero;
    else  return Transition::OneToOne;
}

struct ScoreTracker {
    long long zeroTop;
    long long zeroBottom;
    long long oneFlip;
    long long best;
    size_t n;

    ScoreTracker(int firstBit, size_t total)
        :   zeroTop(0),
            zeroBottom(firstBit == 0 ? total - 1 : 0),
            oneFlip(firstBit == 1 ? 1 : 0),
            best(max(zeroBottom, oneFlip)),
            n(total)
    {}

    void process(Transition t, size_t i) {
        switch (t) {
            case Transition::ZeroToOne:
                handleZeroToOne(i);  break;
            case Transition::ZeroToZero:
                handleZeroToZero(i);  break;
            case Transition::OneToZero:
                handleOneToZero(i);  break;
            case Transition::OneToOne:
                handleOneToOne(i);  break;
        }
    }

    void updateBest(long long candidate) {
        best = max(best, candidate);
    }

    void handleZeroToOne(size_t i) {
        oneFlip = zeroBottom + 1;
        updateBest(oneFlip);
        zeroTop = zeroBottom = 0;
    }

    void handleZeroToZero(size_t i) {
        zeroTop += i;
        zeroBottom += (n - 1 - i);
        updateBest(max(zeroTop, zeroBottom));
    }

    void handleOneToZero(size_t i) {
        zeroTop = oneFlip + i;
        zeroBottom = (n - 1 - i);
        updateBest(max(zeroTop, zeroBottom));
        oneFlip = 0;
    }

    void handleOneToOne(size_t i) {
        zeroTop = zeroBottom = 0;
        oneFlip = 1;
    }

    long long getBest() const { return best; }
};

int main(){
    size_t T;
    cin >> T;
    vector<long long> results(T);
    for (size_t i = 0; i < T; ++i) {
        size_t n;
        cin >> n;

        string s;
        cin >> s;
        
        vector<int> bits;
        bits.reserve(n);
        for (char c : s) {
            bits.push_back(c - '0');
        }

        ScoreTracker tracker(bits[0], n);
        for (size_t j = 1; j < n; ++j) {
            tracker.process(classify(bits[j - 1], bits[j]), j);
        }

        results[i] = tracker.getBest();
    }

    for (int i = 0; i < T; ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}