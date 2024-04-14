#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "202003313027689565614010094809128502533";
    int n = s.length();
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    set<int> st;
    for (int s1 = 0; s1 < n; s1++)
    {
        if (s[s1] != '2')
            continue;
        for (int s2 = s1 + 1; s2 < n; s2++)
        {
            if (s[s2] != '0')
                continue;
            for (int s3 = s2 + 1; s3 < n; s3++)
            {
                if (s[s3] != '2')
                    continue;
                for (int s4 = s3 + 1; s4 < n; s4++)
                {
                    if (s[s4] != '3')
                        continue;
                    for (int s5 = s4 + 1; s5 < n; s5++)
                    {
                        if (s[s5] != '1' && s[s5] != '0')
                            continue;
                        for (int s6 = s5 + 1; s6 < n; s6++)
                        {
                            int mon = (s[s5] - '0') * 10 + (s[s6] - '0');
                            if (mon < 1 || mon > 12)
                                continue;
                            for (int s7 = s6 + 1; s7 < n; s7++)
                            {
                                if (s[s7] != '0' && s[s7] != '1' && s[s7] != '2' && s[s7] != '3')
                                    continue;
                                for (int s8 = s7 + 1; s8 < n; s8++)
                                {
                                    int d = (s[s7] - '0') * 10 + (s[s8] - '0');
                                    if (d < 1 || d > day[mon])
                                        continue;
                                    else
                                        st.insert(mon * 100 + d);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << st.size() << endl;
}