#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct DivPoly
{
    vector<int> result, reminder;
};
void print_poly(vector<int> &poly)
{
    bool flg = 0;
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i] == 0)
            continue;
        else
        {
            if (i == 0)
            {
                flg = 1;
                cout << "1";
            }
            else
            {
                if (flg)
                    cout << " + x^" << i;
                else
                {
                    flg = 1;
                    cout << "x^" << i;
                }
            }
        }
    }
    cout << endl;
}

DivPoly divide_polynomial(vector<int> D, vector<int> g)
{
    if (D.size() != g.size())
    {
        cout << "Error: D and g must have the same size\n";
        exit(1);
    }
    vector<int> cur = D;
    int lstDiff = 0;
    struct DivPoly divPoly;
    divPoly.reminder = divPoly.result = vector<int>(g.size());
    while (true)
    {
        // divide cur by g
        vector<int> nxt(D.size());

        int largestPowerInG = -1;
        for (int i = 0; i < g.size(); i++)
            if (g[i] == 1)
                largestPowerInG = i;

        int largestPowerInCur = -1;
        for (int i = 0; i < cur.size(); i++)
            if (cur[i] == 1)
                largestPowerInCur = i;
        if (largestPowerInCur == -1 or largestPowerInG == -1)
        {
            divPoly.reminder = cur;
            break;
        }
        int diff = largestPowerInCur - largestPowerInG;
        if (diff < 0)
        {
            divPoly.reminder = cur;
            break;
        }

        for (int i = 0; i < g.size(); i++)
            nxt[i + diff] = g[i];

        for (int i = 0; i < nxt.size(); i++)
            cur[i] = (cur[i] + nxt[i]) % 2;

        lstDiff = diff;
        divPoly.result[diff] ^= 1;
    }
    return divPoly;
}