#include <bits/stdc++.h>
using namespace std;

int n = 50;
string out(pair<int, int> a) {
    return "{" + to_string(a.first) + "," + to_string(a.second) + "}";
}

vector<vector<int>> mat(50, vector<int>(50));
vector<vector<bool>> vis(50, vector<bool>(50));
vector<vector<int>> val(50, vector<int>(50));

bool validcoord(int x , int y)
{
    if (x >= 0 && x <= 49 && y >= 0 && y <= 49)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

void changedir(int &x , int &y , char c)
{
    if (c == 'U')
    {
        x-- ;
    }
    else if (c == 'D')
    {
        x++ ;
    }
    else if (c == 'L')
    {
        y-- ;
    }
    else if (c == 'R')
    {
        y++ ;
    }
}

void visit(vector<vector<bool>> &visited , vector<vector<int>> tiles , int x , int y)
{
    visited[x][y] = true ;
    int xU = x , yU = y ;
    int xD = x , yD = y ;
    int xL = x , yL = y ;
    int xR = x , yR = y ;
    changedir(xU , yU , 'U') ;
    changedir(xD , yD , 'D') ;
    changedir(xL , yL , 'L') ;
    changedir(xR , yR , 'R') ;

    if (validcoord(xU , yU) && tiles[x][y] == tiles[xU][yU])
    {
        visited[xU][yU] = true ;
        return ;
    }
    else if (validcoord(xD , yD) && tiles[x][y] == tiles[xD][yD])
    {
        visited[xD][yD] = true ;
        return ;
    }
    else if (validcoord(xL , yL) && tiles[x][y] == tiles[xL][yL])
    {
        visited[xL][yL] = true ;
        return ;
    }
    else if (validcoord(xR , yR) && tiles[x][y] == tiles[xR][yR])
    {
        visited[xR][yR] = true ;
        return ;
    }
}

bool isvalid(int x , int y , vector<vector<int>> tiles , vector<vector<int>> points , string path)
{
    vector<vector<bool>> visited(50 , vector<bool>(50 , false)) ;
    visit(visited , tiles , x , y) ;
    for (int i = 0 ; i < path.length() ; i++)
    {
        changedir(x , y , path[i]) ;
        if (!validcoord(x , y) || visited[x][y])
        {
            return false ;
        }
        visit(visited , tiles , x , y) ;
    }
    return true ;
}

int score(int x , int y , vector<vector<int>> tiles , vector<vector<int>> points , string path)
{
    if (!isvalid(x , y , tiles , points , path))
    {
        return -1 ;
    }
    int score = 0 ;
    score += points[x][y] ;
    for (int i = 0 ; i < path.length() ; i++)
    {
        changedir(x , y , path[i]) ;
        score += points[x][y] ;
    }
    return score ;
}



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
        if(!validcoord(cur.first, cur.second-1)){
            return false;
        }
        return !vis[cur.first][cur.second-1];
    }
    bool is_right() {
        if(!validcoord(cur.first, cur.second+1)){
            return false;
        }
        return !vis[cur.first][cur.second+1];
    }
    bool is_up() {
        if(!validcoord(cur.first-1, cur.second)){
            return false;
        }
        return !vis[cur.first-1][cur.second];
    }
    bool is_down() {
        if(!validcoord(cur.first+1, cur.second)){
            return false;
        }
        return !vis[cur.first+1][cur.second];
    }
    pair<int, int> opt() {
        mt19937 rng(9);
        pair<int, int> ans = {-1, -1};
        int cur_score = -1; 
        vector<pair<pair<int, int>, char>> v; 
        if(cur_score <= left.second) {
            ans = left.first;
            cur_score = left.second;
            where = 'L';
            v.push_back({left.first, 'L'});
        }
        if(cur_score <= right.second) {
            ans = right.first;
            cur_score = right.second;
            where = 'R';
            v.push_back({right.first, 'R'});
        }
        if(cur_score <= up.second) {
            ans = up.first;
            cur_score = up.second;
            where = 'U';
            v.push_back({up.first, 'U'});
        }
        if(cur_score <= down.second) {
            ans = down.first;
            cur_score = down.second;
            where = 'D';
            v.push_back({down.first, 'D'});
        }
        random_shuffle(v.begin(), v.end());
        if(v.size() > 0) {
            int tmp = rng();
            tmp = abs(tmp);
            ans = v[tmp%v.size()].first;
            where = v[tmp%v.size()].second;
        }
        return ans;
    }
};

string ans = "";
int cur_score = -1;

void solve(int si, int sj) {
    int si, sj;
    int x, y;
    // cin >> si >> sj;
    
    vis[si][sj] = true;
    if(si+1<n) {
    if(mat[si][sj] == mat[si+1][sj])
        vis[si+1][sj]=true;    
    }
    if(si-1 >= 0) {
        if(mat[si][sj]==mat[si-1][sj])
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
    string oo = "";
    while(true) {
        int cur_id = mat[si][sj];
        neigh boof(si, sj);
        pair<int, int> temp = boof.opt();
        if(boof.where == '?') {
            break;
        }
        si = temp.first;
        sj = temp.second;
        vis[si][sj] = true;
        if(si+1<n) {
            if(mat[si][sj] == mat[si+1][sj])
                vis[si+1][sj]=true;    
        }
        if(si-1 >= 0) {
            if(mat[si][sj]==mat[si-1][sj])
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
        oo += boof.where;
    }
    int new_score = score(x, y, mat, val, ans);
    if(new_score > cur_score) {
        ans = oo;
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    int x, y;
    int si, sj;
    cin >> x >> y;
    si = x;
    sj = y;
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

    for(int round = 0 ; round < 100 ; round++) {
        vector<vector<bool>> tmp(50, vector<bool>(50));
        vis = tmp;
        solve(si, sj);
    }
    cout << ans << endl;
}