#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Utils.h"

using namespace std;

int n, k;

int main()
{
    cout << "Enter n: ";
    cin >> n;

    vector<int> g(n), r(n), S;

    cout << "Enter The Binary Form Of r(x): ";
    for (int i = 0; i < n; i++)
        cin >> r[i];

    cout << "Enter The Binary Form Of g(x): ";
    for (int i = 0; i < n; i++)
        cin >> g[i];

    DivPoly sDiv = divide_polynomial(r, g);

    int hasRem = 0;
    for (int i = 0; i < sDiv.reminder.size(); i++)
        hasRem |= sDiv.reminder[i];

    /*
1 0 1 0 0 1 0
1 0 1 1 0 0 0

 */
    S = r;
    if (!hasRem)
    {
        cout << "No Error Detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (sDiv.reminder[i])
                S[i] = !S[i];
        }
    }

    cout << "S(x) = ", print_poly(S);
    cout << "S: ";
    for (int i = 0; i < S.size(); i++)
        cout << S[i] << " ";
    cout << endl;
    return 0;
}