#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

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

string Ones_complement(string data)
{
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == '0')
            data[i] = '1';
        else
            data[i] = '0';
    }
    return data;
}

string checkSum(string data, int block_size)
{
    int n = data.length();
    if (n % block_size != 0)
    {
        int pad_size = block_size - (n % block_size);
        for (int i = 0; i < pad_size; i++)
        {
            data = '0' + data;
        }
    }

    string result = "";

    for (int i = 0; i < block_size; i++)
    {
        result += data[i];
    }

    for (int i = block_size; i < n; i += block_size)
    {

        string next_block = "";

        for (int j = i; j < i + block_size; j++)
        {
            next_block += data[j];
        }

        string additions = "";
        int sum = 0, carry = 0;

        for (int k = block_size - 1; k >= 0; k--)
        {
            sum += (next_block[k] - '0') + (result[k] - '0');
            carry = sum / 2;
            if (sum == 0)
            {
                additions = '0' + additions;
                sum = carry;
            }
            else if (sum == 1)
            {
                additions = '1' + additions;
                sum = carry;
            }
            else if (sum == 2)
            {
                additions = '0' + additions;
                sum = carry;
            }
            else
            {
                additions = '1' + additions;
                sum = carry;
            }
        }

        string final = "";

        if (carry == 1)
        {
            for (int l = additions.length() - 1; l >= 0; l--)
            {
                if (carry == 0)
                {
                    final = additions[l] + final;
                }
                else if (((additions[l] - '0') + carry) % 2 == 0)
                {
                    final = "0" + final;
                    carry = 1;
                }
                else
                {
                    final = "1" + final;
                    carry = 0;
                }
            }
            result = final;
        }
        else
        {
            result = additions;
        }
    }

    return Ones_complement(result);
}

bool checker(string sent_message, string rec_message, int block_size)
{
    string sender_checksum = checkSum(sent_message, block_size);
    string receiver_checksum = checkSum(rec_message + sender_checksum, block_size);

    if (count(receiver_checksum.begin(), receiver_checksum.end(), '0') == block_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CyclicCodeNonSystematic()
{
    int n, k;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    vector<int> M(k), G(k);

    cout << "Enter M: "; // co of message poly degree of k-1
    for (int i = 0; i < k; i++)
        cin >> M[i];

    cout << "Enter G(): "; // co of generator poly of degree k-1
    for (int i = 0; i < k; i++)
        cin >> G[i];

    vector<int> V(n + n);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            V[i + j] += M[i] * G[j];
            V[i + j] %= 2;
        }

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

void CyclicCodeSystimaticPolynomial()
{
    int n, k;

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
    while (Dleta.size() > g.size())
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

void CyclicCodeSystimaticDecodeingErrorCorrection()
{
    int n;

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
}

void LinearBlock()
{
    int n, k;

    cout << "For A Generator Matrix Enter :" << endl;
    cout << "1. The No Of Message Bits(n)    : ";
    cin >> n;
    cout << "2. The No Of Parity Bits(k)     : ";
    cin >> k;

    cout << "Enter The Elements Of Generator Matrix:" << endl;
    vector<vector<int>> generatorMatrix;

    for (int i = 0; i < k; ++i)
    {
        vector<int> row;
        cout << "Enter row " << i + 1 << " (" << n << " elements separated by spaces): ";
        for (int j = 0; j < n; ++j)
        {
            int element;
            cin >> element;
            row.push_back(element);
        }
        generatorMatrix.push_back(row);
    }

    // build G = P I
    vector<vector<int>> P(k, vector<int>(n - k));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n - k; j++)
            P[i][j] = generatorMatrix[i][j];

    vector<vector<int>> H(n - k, vector<int>(n));
    vector<vector<int>> HT(n, vector<int>(n - k));
    vector<vector<int>> PT(n - k, vector<int>(k));

    for (int i = 0; i < n - k; i++)
        for (int j = 0; j < k; j++)
            PT[i][j] = P[j][i];

    for (int i = 0; i < n - k; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                H[i][j] = 1;
            else
                H[i][j] = 0;

    for (int i = 0; i < n - k; i++)
        for (int j = n - k; j < n; j++)
            H[i][j] = PT[i][j - n + k];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - k; j++)
            HT[i][j] = H[j][i];

    string sent_message, recv_message;
    int block_size;

    cout << "Enter the message to be sent: ";
    cin.ignore(); // Ignore newline from previous input
    getline(cin, sent_message);

    cout << "Enter the message received: ";
    getline(cin, recv_message);

    cout << "Enter the block size: ";
    cin >> block_size;

    cout << "\n";

    if (checker(sent_message, recv_message, block_size))
    {
        cout << "No Error\n";
    }
    else
    {
        cout << "Error\n";
    }
}

int main()
{
    char userChoice;

    do
    {
        cout << "\nInformation Theory Menu:\n";
        cout << "1. Cyclic Code Non-Systematic Encoding\n";
        cout << "2. Cyclic Code Systematic Polynomial\n";
        cout << "3. Cyclic Code Systematic Decoding & Error Correction\n";
        cout << "4. Linear Block\n";
        cout << "5. Checksum\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice)
        {
        case '1':
            CyclicCodeNonSystematic();
            break;

        case '2':
            CyclicCodeSystimaticPolynomial();
            break;

        case '3':
            CyclicCodeSystimaticDecodeingErrorCorrection();
            break;

        case '4':
            LinearBlock();
            break;

        case '5':
        {
            int block_size;
            string sent_message, recv_message;

            cout << "Enter the message to be sent: ";
            cin >> sent_message;
            cout << "Enter the message received: ";
            cin >> recv_message;
            cout << "Enter the block size: ";
            cin >> block_size;

            cout << "\n";

            if (checker(sent_message, recv_message, block_size))
                cout << "No Error\n";
                
            else
                cout << "Error\n";

            break;
        }
        case '6':
            cout << "Exiting...\n";
            break;
            
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (userChoice != '6');

    return 0;
}
