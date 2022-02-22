#include <bits/stdc++.h>
#include "score.cpp"
using namespace std;

int n = 50;

void solve() {
    int si, sj;
    cin >> si >> sj;
    
    int mat[50][50];
    for(int i = 0 ;i < n ; i++) {
        for(int j = 0 ; j < n ; j++) cin >> mat[i][j];
    }
    
    int sc[50][50];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++) cin >> sc[i][j];
    
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    solve();    
}