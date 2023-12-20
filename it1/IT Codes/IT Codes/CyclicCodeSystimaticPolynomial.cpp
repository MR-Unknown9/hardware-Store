#include <iostream>
#include <vector>
#include <cmath>

#include "Utils.h"

using namespace std;

int n, k;

int main()
{
    cout << "Enter k: ";
    cin >> k;
    vector<int> U(k), g(k);
    cout << "Enter In Binary Form U: ";
    for (int i = 0; i < k; i++)
        cin >> U[i];
    cout << "Enter In Binary Form g(x): ";
    for (int i = 0; i < k; i++)
        cin >> g[i];

    vector<int> Dleta(2 * k);
    int largestPowerInG = 0;
    for (int i = 0; i < k; i++)
        if (g[i] == 1)
            largestPowerInG = i;

    for (int i = 0; i < k; i++)
        Dleta[i + largestPowerInG] = U[i];
    while (size(Dleta) > size(g))
    {
        g.push_back(0);
    }

    struct DivPoly res = divide_polynomial(Dleta, g);

    vector<int> b = res.reminder;

    cout << "U(x) = ", print_poly(U);
    cout << "g(x) = ", print_poly(g);
    cout << "Delta(x) = ", print_poly(Dleta);
    cout << "b(x) = ", print_poly(b);

    vector<int> V = Dleta;
    for (int i = 0; i < b.size(); i++)
        V[i] = (V[i] + b[i]) % 2;

    cout << "V(x) = ", print_poly(V);

    cout << "V: ";
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}