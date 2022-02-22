#include <bits/stdc++.h>
#include "score.cpp"
using namespace std;

int n = 50;

void out(pair<int, int> a) {
    cerr << "{" << a.first << "," << a.second << "}" <<endl;
}

// class maze
// {
// public:
//     // int n;
//     vector<vector<int>> pos;
//     vector<vector<int>> val;

//     maze(){
//         n =  50;
//     }

//     void readpos()
//     {
//         for (int i = 0; i < n; i++)
//         {
//             vector<int> temp(50);
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> temp[j];
//             }
//             pos.push_back(temp);
//         }
//     }
//     void readval()
//     {
//         for (int i = 0; i < n; i++)
//         {
//             vector<int> temp(50);
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> temp[j];
//             }
//             val.push_back(temp);
//         }
//     }
// };
// maze m;

int mat[50][50];
int val[50][50];
bool vis[50][50];

struct neigh {
    pair<pair<int, int>, int> left = {{-1, -1}, INT_MIN}, 
                              right= {{-1, -1}, INT_MIN}, 
                              up= {{-1, -1},INT_MIN}, 
                              down= {{-1, -1}, INT_MIN};
    pair<int, int> cur;
    char where = '?';
    neigh(int i, int j) {
        cur.first = i;
        cur.second = j;
        if(is_left()) {
            left.first.first = i;
            left.first.second = j-1;
            left.second = val[i][j-1];
        }
        if(is_right()) {
            right.first.first = i;
            right.first.second = j+1;
            right.second = val[i][j+1];
        }
        if(is_down()) {
            down.first.first=i+1;
            down.first.second=j;
            down.second=val[i+1][j];
        }
        if(is_up()) {
            up.first.first=i-1;
            up.first.second=j;
            up.second=val[i-1][j];
        }
    }
    bool is_left() {
        if(cur.second-1 < 0) return false;
        return !vis[cur.first][cur.second-1] 
        && (mat[cur.first][cur.second] != mat[cur.first][cur.second-1]);
    }
    bool is_right() {
        if(cur.second+1 >= n) return false;
        return !vis[cur.first][cur.second+1] 
        && (mat[cur.first][cur.second] != mat[cur.first][cur.second+1]);
    }
    bool is_down() {
        if(cur.first+1 >= n) return false;
        return !vis[cur.first+1][cur.second] 
        && (mat[cur.first][cur.second] != mat[cur.first+1][cur.second]);
    }
    bool is_up() {
        if(cur.first-1 < 0) return false;
        return !vis[cur.first-1][cur.second]
        && (mat[cur.first][cur.second] != mat[cur.first-1][cur.second]);
    }
    pair<int, int> opt() {
        pair<int, int> ans = {-1, -1};
        int cur_score = -1;
        if(cur_score <= left.second) {
            ans = left.first;
            cur_score = left.second;
            where = 'L';
        }
        if(cur_score <= right.second) {
            ans = right.first;
            cur_score = right.second;
            where = 'R';
        }
        if(cur_score <= up.second) {
            ans = up.first;
            cur_score = up.second;
            where = 'U';
        }
        if(cur_score <= down.second) {
            ans = down.first;
            cur_score = down.second;
            where = 'D';
        }
        return ans;
    }
};

void solve() {
    int si, sj;
    cin >> si >> sj;
    for(int i = 0 ; i < 50 ; i++) {
        for(int j = 0 ; j < 50 ; j++) {
            cin >> mat[i][j];
        }
    }
    for(int i = 0 ; i < 50 ; i++) {
        for(int j = 0 ; j < 50 ; j++) {
            cin >> val[i][j];
        }
    }
    string ans = "";
    while(true) {
        cout << si << " " << sj << endl;
        int cur_id = mat[si][sj];
        neigh pp(si, sj);

        pair<int, int> temp = pp.opt();
        if(pp.where == '?') {
            break;
        }
        out(temp);
        si = temp.first;
        sj = temp.second;
        vis[si][sj] = true;
        if(si+1<n) {
            if(mat[si][sj] == mat[si+1][sj])
                vis[si+1][sj]=true;    
        }
        if(si-1 >= 0) {
            if(mat[si][sj]==mat[si+1][sj])
            vis[si-1][sj]=true;
        }
        if(sj+1 < n) {
            if(mat[si][sj] == mat[si][sj+1])
            vis[si][sj+1]=true;
        }
        if(sj-1 >= 0) {
            if(mat[si][sj]==mat[si][sj-1])
            vis[si][sj-1]=true;;
        }
        ans += pp.where;
    }
    cerr << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    solve();    
}