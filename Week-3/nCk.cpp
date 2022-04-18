#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string path = "Week-3/results.txt";
const int maxn = 55;
    ll D[maxn][maxn] = {0};

ll recursion_C(int n, int k) {
    if (k == 0 || n == k)
        return 1;
    else {
        return recursion_C(n - 1, k) + recursion_C(n - 1, k - 1);
    }
}

ll recursion_with_memory_C(int n, int k) {
    for( int i=0; i<=n ;++i ){
        D[i][0] = 1;
        D[i][i] = 1;
    }
    if (D[n][k] == 0) {
        D[n][k] = recursion_with_memory_C(n - 1, k - 1) + recursion_with_memory_C(n - 1, k);
    }
    return D[n][k];
}

double runningTime(function<ll(int, int)> func, int n, int k) {
    for( int i=0; i<n; ++i ){
        for( int j=0; j<n; ++j ){
            D[i][j] = 0;
        }
    }
    clock_t startTime = clock();
    ll ans = func(n, k);
    // cout<<ans<<endl;
    clock_t endTime = clock();
    return (double(endTime) - double(startTime)) / CLOCKS_PER_SEC;
}

void runCase(int n, int k) {
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