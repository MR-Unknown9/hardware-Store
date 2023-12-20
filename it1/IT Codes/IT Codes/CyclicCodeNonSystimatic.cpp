#include <iostream>
#include <vector>
#include <cmath>

#include "Utils.h"

using namespace std;

int n, k;

int main()
{
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    vector<int> M(k), G(k);

    cout << "Enter M: ";
    for (int i = 0; i < k; i++)
        cin >> M[i];

    cout << "Enter G(): ";
    for (int i = 0; i < k; i++)
        cin >> G[i];

    vector<int> V(n + n);
    // G = [x^0 , x^1 , x^2 , ...... x^(k-1)]
    // M = [x^0 , x^1 , x^2 , ...... x^(k-1)]

    // V = [x^0 , x^1 , x^2 , ...... x^(n-1)]

    // Mutliply G and M

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            V[i + j] += M[i] * G[j];
            V[i + j] %= 2;
        }
    // print V in form of polynomial
    cout << "____________________________________________________" << endl;
    cout << endl;

    cout << "M(x): ";
    print_poly(M);
    cout << "G(x): ";
    print_poly(G);
    cout << "V(x): ";
    print_poly(V);

    cout << "____________________________________________________" << endl;
    cout << endl;

    cout << "V: ";

    for (int i = 0; i < n; i++)
        cout << V[i] << " ";
    cout << endl;
}