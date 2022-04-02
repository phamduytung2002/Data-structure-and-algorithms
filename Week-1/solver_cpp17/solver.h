#include<bits/stdc++.h>
using namespace std;

const double TIME_LIMIT = 60;
const int maxn = int(1e6+5);
int dp[maxn][2];

double runTime(clock_t startTime){
    clock_t now = clock();
    return double(now - startTime)/CLOCKS_PER_SEC;
}

pair<double,int> bruteForce(int array[], int n){
    cout<<"Running brute force\n";
    int res = INT_MIN;
    clock_t startTime = clock();
    for( int i=0; i<n; ++i ){
        for( int j=i; j<n; ++j ){
            int sum = 0;
            for( int k=i; k<=j; ++k ){
                sum += array[k];
            }
            if( sum > res ) res = sum;
            if( runTime(startTime) > TIME_LIMIT ) return {TIME_LIMIT, res};
        }
    }
    return {runTime(startTime), res};
}

pair<double,int> bruteForceWithImprovement(int array[], int n){
    cout<<"Running brute force with improvement\n";
    int res = INT_MIN;
    clock_t startTime = clock();
    for( int i=0; i<n; ++i ){
        int sum = 0;
        for( int j=i; j<n; ++j ){
            sum += array[j];
            if( sum > res ) 
                res = sum;
        }
        if( runTime(startTime) > TIME_LIMIT ) 
            return {TIME_LIMIT, res};
    }
    return {runTime(startTime), res};
}

pair<double,int> dynamicProgramming(int array[], int n){
    cout<<"Running dynamic programming\n";
    clock_t startTime = clock();
    //int dp[n][2]; // dp[0][i]: largest sum of subsequence of a[0]...a[i-1]
                  // dp[1][i]: largest sum of subsequence of a[0]...a[i]
    dp[0][0] = 0;
    dp[0][1] = array[0];
    for( int i=1; i<n; ++i ){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-1][1], 0) + array[i];
    } 
    return {runTime(startTime), max(dp[n-1][0], dp[n-1][1])};
}