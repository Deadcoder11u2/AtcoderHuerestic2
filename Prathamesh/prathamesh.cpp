#include<bits/stdc++.h>
#include "ScoreFunc.cpp"

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define size(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define read(arr, n)            \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define write(arr, n)          \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " " ; \
    cout << "\n" ; 
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void debug_code()
{
    #ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    #endif
}


class Maze
{
public:
    int n;
    pair<int,int>xy;
    string str;
    vector<vector<pair<int, int>>> matrix;

    Maze()
    {
        n = 50;
        int sx, sy;
        cin >> sx >> sy;
        xy.first = sx, xy.second = sy;

        matrix.resize(50, vector<pair<int, int>>(50, {0, 0}));
    }

    void Read()
    {
        vector<vector<int>> val;
        vector<vector<int>> pos;

        for (int i = 0; i < n; i++)
        {
            vector<int> temp(50);
            for (int j = 0; j < n; j++)
                cin >> temp[j];
            pos.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> temp(50);
            for (int j = 0; j < n; j++)
                cin >> temp[j];
            val.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j].first = pos[i][j];
                matrix[i][j].second = val[i][j];
            }
        }

    }
};


signed main(int argc, char **argv){
    fastio();
    init_code();
    debug_code();

    // Maze* maze = new Maze();
    Maze maze;

    maze.Read();
    maze.str = "R";
    cout << score(maze.xy, maze.matrix, maze.str);

    return 0;


}

