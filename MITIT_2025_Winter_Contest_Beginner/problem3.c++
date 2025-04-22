#include <iostream>
#include <set>
#include <climist>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int find_min_distance(const set<Point>& pointSet) {
    if (pointSet.size() <= 1)  return 0;
    else if (pointSet.size() == 2)  return 

    int min_dist = INT_MAX;

    for (Point point : pointSet) {
        set<Point> pointSet_copy = pointSet;
        pointSet_copy.erase(point);
        int dist = find_min_distance(pointSet_copy)
        if (dist < min_dist)  min_dist = dist;
    }

    return min_dist
}

int main() {
    int num_tc;
    cin >> num_tc;

    int results[num_tc];
    
    for (int i = 0; i < num_tc; ++i) {
        int num_cities;
        cin >> num_cities;

        set<Point> pointSet;

        for (int j = 0; j < num_cities; ++j) {
            int x;
            cin >> x;
            int y;
            cin >> y;

            pointSet.insert({x, y});
        }

        results[i] = find_min_distance(pointSet);
    }

    for (int result : results)  cout << result << endl;

    return 0;
}

