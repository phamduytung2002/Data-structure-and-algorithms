#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string path = "Week-3/results.txt";
ll D[50][50];

ll recursion_C(ll n, ll k) {
    if (k == 0 || n == k)
        return 1;
    else
        return recursion_C(n - 1, k) + recursion_C(n - 1, k - 1);
}

ll recursion_with_memory_C(ll n, ll k) {
    if (D[n][k] > 0)
        return D[n][k];
    else {
        if (k == 0 || n == k)
            D[n][k] = 1;
        else
            D[n][k] = recursion_with_memory_C(n - 1, k - 1) + recursion_with_memory_C(n - 1, k);
        return D[n][k];
    }
}

double runningTime(function<ll(ll, ll)> func, ll n, ll k) {
    clock_t startTime = clock();
    ll ans = func(n, k);
    clock_t endTime = clock();
    return (double(endTime) - double(startTime)) / CLOCKS_PER_SEC;
}

void runCase(ll n, ll k) {
    ofstream resfile;
    resfile.open(path, ios::app);
    resfile << "Case: n = " << n << ", k = " << k << endl;
    resfile << "\tRecursion with memory running time: " << runningTime(recursion_with_memory_C, n, k) << endl;
    resfile << "\tRecursion running time: " << runningTime(recursion_C, n, k) << endl;
    resfile.close();
}

int main() {
    runCase(20, 10);
    runCase(35, 20);
    runCase(40, 20);
    runCase(50, 30);
}