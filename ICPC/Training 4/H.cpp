#include <iostream>
#include <algorithm>
#include <cmath>
#define PI 3.14159265358979323846L

using namespace std;

struct Point {
    double x, y;
} P[2], center;

double R, C;

void Solve() {
    double a = P[0].y - P[1].y;
    double b = P[1].x - P[0].x;
    double c = -P[0].x * a - P[0].y * b;

    double Dist = abs(a * center.x + b * center.y + c) / sqrt(a * a + b * b);

    if (Dist >= R) {
        cout << "NO";
        return;
    }

    if (Dist == 0) {
        if (50.0 - C <= 5.0) cout << "YES";
        else cout << "NO";
        return;
    }

    double ang = 2 * acos(Dist / R);

    double S = R * R * PI;
    double T = S / (2 * PI) * ang;

    T -= (R * R * sin(ang)) / 2.0;
    if (abs(C * S / 100.0 - T) <= S / 20.0) {
        cout << "YES";
        return;
    } else {
        cout << "NO";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> P[0].x >> P[0].y >> P[1].x >> P[1].y;
    cin >> center.x >> center.y >> R >> C;

    Solve();

    return 0;
}
