#include <iostream>
#include <set>
#include <climits>
#include <cassert>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

int calculate_distance_two_points(const Point& point1, const Point& point2) {
    return abs(point1.x - point2.x + point1.y - point2.y);
}

int find_min_distance(const set<Point>& pointSet, const Point& first, const Point& start) {
    if (pointSet.size() <= 1) {
        const Point other = *pointSet.begin();
        return calculate_distance_two_points(start, other) + calculate_distance_two_points(other, first);
    }
    
    int min_dist = INT_MAX;

    for (Point point : pointSet) {
        set<Point> pointSet_with_point_removed = pointSet;
        pointSet_with_point_removed.erase(point);
        
        int dist = find_min_distance(pointSet_with_point_removed, first, point) + calculate_distance_two_points(start, point);
        
        if (dist < min_dist) {
            min_dist = dist;
        }
    }

    return min_dist;
}

int main() {
    int num_tc;
    cin >> num_tc;

    int results[num_tc];
    
    for (int i = 0; i < num_tc; ++i) {
        int num_cities;
        cin >> num_cities;

        set<Point> pointSet;

        int x;
        cin >> x;
        int y;
        cin >> y;
        Point first_city = {x, y};

        for (int j = 1; j < num_cities; ++j) {
            cin >> x;
            cin >> y;

            pointSet.insert({x, y});
        }

        int min_dist = find_min_distance(pointSet, first_city, first_city);

        results[i] = min_dist;
    }

    for (int result : results)  cout << result << endl;

    return 0;
}

