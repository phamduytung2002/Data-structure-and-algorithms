#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<ll, int> csdl;

bool find(ll k) {
    if(csdl.find(k)==csdl.end()) return false;
    else return true;
}

void insert(ll k){
    csdl.insert({k, 2710});
}

int main() {
    char next = cin.peek();
    while(next!='*'){
        int k;
        cin>>k;
        insert(k);
        next = cin.peek();
    }
    cin>>next;
    next = ' ';
    while(next!='*'){
        string q;
        int k;
        cin>>q>>k;
        if(q=="find") find(k);
        else insert(k);
        next = cin.peek();
    }
}