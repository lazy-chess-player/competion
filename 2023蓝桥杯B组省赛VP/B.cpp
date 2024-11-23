#include <cmath>
#include <iostream>

using namespace std;

const int len = 23333333;

const double eps = 1.0001;
int main()
{
    int n = len / 2;
    for (int i = 1; i <= n; i++)
    {
        double p0 = double(i) / double(len);
        double p1 = 1 - p0;
        double h = (-1.0) * i * p0 * log2(p0) + (-1.0) * (len - i) * p1 * log2(p1);
        if (fabs(h - 11625907.5798) < eps)
        {
            cout << i << endl;
            break;
        }
    }
}
