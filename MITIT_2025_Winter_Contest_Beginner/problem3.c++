#include <iostream>
#include <vector>
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

int count_num_of_not_visited_points(const vector<Point>& pointArray, const vector<bool>& visitedArray) {
    int count = 0;

    for (int i = 0; i < pointArray.size(); ++i) {
        if (! visitedArray[i]) {
            count++;
        }
    }

    return count;
}

int find_min_distance(const vector<Point>& pointArray, vector<bool>& visitedArray, const Point& first, const Point& prev) {
    int num_of_not_visited_point = count_num_of_not_visited_points(pointArray, visitedArray);

    if (num_of_not_visited_point == 1) {
        Point other;
        for (int i = 0; i < pointArray.size(); ++i) {
            if (! visitedArray[i]) {
                other = pointArray[i];
                break;
            }
        }

        return calculate_distance_two_points(prev, other) + calculate_distance_two_points(other, first);
    }
    
    int min_dist = INT_MAX;

    for (int i = 0; i < pointArray.size(); ++i) {
        if (visitedArray[i]) {
            continue;
        }

        visitedArray[i] = true;

        const Point cur_point = pointArray[i];
        
        int dist = find_min_distance(pointArray, visitedArray, first, cur_point) + calculate_distance_two_points(prev, cur_point);

        visitedArray[i] = false;
        
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

        vector<Point> pointArray;

        int x;
        cin >> x;
        int y;
        cin >> y;
        Point first_city = {x, y};

        for (int j = 1; j < num_cities; ++j) {
            cin >> x;
            cin >> y;

            pointArray.push_back({x, y});
        }

        vector<bool> visitedArray(pointArray.size(), false);

        int min_dist = find_min_distance(pointArray, visitedArray, first_city, first_city);

        results[i] = min_dist;
    }

    for (int result : results)  cout << result << endl;

    return 0;
}

