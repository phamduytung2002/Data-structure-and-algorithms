/*
    determine if exist a subset with given sum
*/

#include <iostream>
using namespace std;

const int maxn = 20;
int S[maxn];

bool isSubsetSum(int S[], int n, int sum) {
    if (n == 0) {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (sum < 0) return false;
    return isSubsetSum(S, n - 1, sum - S[n - 1]) || isSubsetSum(S, n - 1, sum);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> S[i];
    int sum;
    cin >> sum;
    cout << isSubsetSum(S, n, sum);
}