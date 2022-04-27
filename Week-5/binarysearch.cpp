/*
    binary search
    given a non-decrease array a[0..n-1]
    find the first element which have value >= key
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10, key = 5;
    int k=0;
    for( int b=n/2; b>=1; b/=2){
        while(k+b<n&&a[k+b]<key) k += b;
    }
    cout<<k+1<<endl;
    cout<<lower_bound(a, a+n, key)-a;
}