#include <stdio.h>
long double cal(int p, int g, int bd, int m)
{
    int sum = p + g + bd + m;
    long double bse = 1.0 / sum;
    long double ans = (p * bse * 1.0 * 100) + (g * bse * 0.65 * 100);
    return ans;
}

void solve()
{
    int p, g, bd, m;
    scanf("%d%d%d%d", &p, &g, &bd, &m);
    long double ans;
    ans = cal(p, g, bd, m);
    int temp;
    temp = (int)(ans * 1000);
    if (temp % 10 <= 4)
        temp = temp - temp % 10;
    else
    {
        temp = temp + 10;
        temp = temp - temp % 10;
    }
    printf("%.2Lf\n", ans);
}

int main()
{
    // ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}

//