#include <iostream>
#include <cmath>
using namespace std;
double get_distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int main()
{
    const int number_of_points = 8;
    double points[number_of_points][2];
    cout << "Enter" << number_of_points << "points: ";
    for (int i = 0; i < number_of_points; i++)
        cin >> points[i][0] >> points[i][1];
    int p1 = 0, p2 = 1;
    double shortest_distance = get_distance(points[p1][0], points[p1][1],
                                            points[p2][0], points[p2][1]);
    for (int i = 0; i < number_of_points; i++)
    {
        for (int j = i + 1; j < number_of_points; j++)
        {
            double distance = get_distance(points[i][0], points[i][1],
                                           points[j][0], points[j][1]);
            if (shortest_distance > distance)
            {
                p1 = i;
                p2 = j;
                shortest_distance = distance;
            }
        }
    }
    cout << "The closest two points are "
         << "(" << points[p1][0] << points[p1][1] << ") and ("
         << points[p2][0] << points[p2][1] << ")" << endl;
    getchar();
    return 0;
}