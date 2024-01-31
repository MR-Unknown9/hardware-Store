#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int i, j, n, k;
vector<int> M, C, V;
vector<vector<int>> P, G;

void encode()
{
    cout << "\nEnter The Message Bits\n";
    for (i = 0; i < k; i++)
        cin >> M[i];

    cout << "\t\t\tEncodeing Result\n";
    cout << "____________________________________________________" << endl;

    cout << "\n\n\tThe Parity Bits :";
    for (i = 0; i < n - k; i++)
    {
        C[i] = 0;
        for (j = 0; j < k; j++)
            C[i] = (C[i] + M[j] * P[j][i]) % 2;
        cout << "\n\tC" << i + 1 << " = " << C[i];
    }
    cout << "\n\n\tCode Word For Given Messege Bit:\n\t";
    for (i = 0; i < n - k; i++)
        cout << C[i] << " ";
    for (i = 0; i < k; i++)
        cout << M[i] << " ";
    cout << "\n____________________________________________________" << endl;
}

void decode()
{

    cout << "\n\nEnter The Received Code Word\n";
    for (i = 0; i < n; i++)
        cin >> V[i];

    vector<vector<int>> H(n - k, vector<int>(n));
    vector<vector<int>> HT(n, vector<int>(n - k));
    vector<vector<int>> PT = vector<vector<int>>(n - k, vector<int>(k));
    // build PT

    for (i = 0; i < n - k; i++)
        for (j = 0; j < k; j++)
            PT[i][j] = P[j][i];

    // H = I P^T
    // build H
    for (i = 0; i < n - k; i++)
        for (j = 0; j < n; j++)
            if (i == j)
                H[i][j] = 1;
            else
                H[i][j] = 0;

    // ADD PT
    for (int i = 0; i < n - k; i++)
    {
        for (int j = n - k; j < n; j++)
        {
            H[i][j] = PT[i][j - n + k];
        }
    }

    // build HT
    for (i = 0; i < n; i++)
        for (j = 0; j < n - k; j++)
            HT[i][j] = H[j][i];

    cout << "\n\t\t\tDecodeing Result\n";
    cout << "____________________________________________________" << endl;
    // C = V HT
    cout << "\n\n\tThe Syndrome Bits :";
    for (i = 0; i < n - k; i++)
    {
        C[i] = 0;
        for (j = 0; j < n; j++)
            C[i] = (C[i] + V[j] * HT[j][i]) % 2;
        cout << "\n\tC" << i + 1 << " = " << C[i];
    }
    // find error
    int sum = 0;
    for (auto x : C)
        sum += x;

    int error = sum;

    if (error == 0)
        cout << "\n\n\tNo Error Found\n";
    else
    {
        for (int i = 0; i < size(HT); i++)
        {
            if (HT[i] == C)
            {
                error = i + 1;
                break;
            }
        }

        cout << "\n\n\tError Found At Position " << error << endl;
        cout << "\n\tCorrected Code Word Is\n\t";
        V[error - 1] = (V[error - 1] + 1) % 2;
        for (i = 0; i < n; i++)
            cout << V[i] << " ";
    }
    cout << "\n____________________________________________________" << endl;
    cout << "\n\n\tThe Decoded Message Bits Are\n\t";
    for (i = n - k; i < n; i++)
        cout << V[i] << " ";

    cout << "\n____________________________________________________" << endl;
}

int main()
{

    char userChoise;
    cout << "\n\n\t\t\tMenu\n";
    cout << "____________________________________________________" << endl;
    cout << "\n1. Encode\n2. Decode\n3. Exit\n";
    cout << "\nEnter Your Choise : ";

    cin >> userChoise;

    cout << " For A Generator Matrix Enter :\n";
    cout << "1. The No Of Message Bits(n)\t: ";
    cin >> n;
    cout << "2. The No Of Parity Bits(k)\t: ";
    cin >> k;
    cout << "\nEnter The Elements Of Generator Matrix:\n";

    M.resize(k);
    C.resize(n - k);
    P.resize(k, vector<int>(n - k));
    G.resize(k, vector<int>(n));
    V.resize(n);

    for (i = 0; i < k; i++)
        for (j = 0; j < n; j++)
            cin >> G[i][j];

    // build G = P I
    for (i = 0; i < k; i++)
        for (j = 0; j < n - k; j++)
            P[i][j] = G[i][j];

    switch (userChoise)
    {

    case '1':
        encode();
        break;
    case '2':
        decode();
        break;

    default:
        exit(0);
        break;
    }
    /*
1 1 0 1 0 0 0
0 1 1 0 1 0 0
1 1 1 0 0 1 0
1 0 1 0 0 0 1

1 0 0 1 0 0 1
       */
    return 0;
}