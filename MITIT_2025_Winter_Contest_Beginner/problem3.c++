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
        cout << "We iterate to Point: x = " << point.x << ", y = " << point.y << endl;

        set<Point> pointSet_with_point_removed = pointSet;
        pointSet_with_point_removed.erase(point);

        int dist = find_min_distance(pointSet_with_point_removed, first, point) + calculate_distance_two_points(first, point);
        
        if (start == Point{1, 2}) {
            cout << "DEBUG: Next we iterate to x = " << point.x << ", y = " << point.y << ", with distance = " << dist << endl;
        }

        if (dist < min_dist) {
            if (start == first) {
                cout << "We found the min dist of " << dist << ", it starts at the point: x = " << point.x << ", y = " << point.y << endl;

            }
            //if (start == Point{-1, 3})  cout << "The third stop is: x = " << point.x << ", y = " << point.y << ", with distance: " << dist << endl;
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

        cout << "min dist is " << min_dist << endl;

        results[i] = min_dist;
    }

    for (int result : results)  cout << result << endl;

    return 0;
}

