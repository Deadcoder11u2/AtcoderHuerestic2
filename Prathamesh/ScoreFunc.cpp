#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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
#define write(arr, n)           \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << "\n";
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

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


int score(pair<int, int> current, vector<vector<pair<int, int>>> &matrix, string s)
{

    int finalScore = 0;
    pair<int, int> xy = current;

    // vector<int>scores;
    // vector<int>positions;

    vector<vector<bool>> Istrue(50, vector<bool>(50, true));

    for (int i = 0; i <= size(s); i++){

        if (Istrue[xy.first][xy.second] == false)
            return -1;
        else{
            Istrue[xy.first][xy.second] = false;

            if(xy.first - 1 >= 0 && matrix[xy.first - 1][xy.second].first == matrix[xy.first][xy.second].first)
                Istrue[xy.first - 1][xy.second] = false;

            else if(xy.second - 1 >= 0 && matrix[xy.first][xy.second - 1].first == matrix[xy.first][xy.second ].first)
                Istrue[xy.first][xy.second - 1] = false;

            else if(xy.first + 1 <= 49 && matrix[xy.first + 1][xy.second].first == matrix[xy.first][xy.second].first)
                Istrue[xy.first + 1][xy.second] = false;

            else if(xy.second + 1 <=  49 && matrix[xy.first][xy.second + 1].first == matrix[xy.first][xy.second].first)
                Istrue[xy.first][xy.second + 1] = false;
        }



        finalScore += matrix[xy.first][xy.second].second;
        // scores.push_back(matrix[xy.first][xy.second].second);
        // positions.push_back(matrix[xy.first][xy.second].first);

        if(s[i] == 'U'){
            if(xy.first - 1 >= 0 && Istrue[xy.first - 1][xy.second] == true) xy.first = xy.first - 1;
            else return -1;
        }
        else if(s[i] == 'D'){
            if(xy.first + 1 <= 49 && Istrue[xy.first + 1][xy.second] == true) xy.first = xy.first + 1;
            else return -1;
        }
        else if(s[i] == 'R'){
            if(xy.second + 1 <= 49 && Istrue[xy.first][xy.second + 1] == true) xy.second = xy.second + 1;
            else return -1;
        }
        else{
            if(xy.second - 1 >= 0 && Istrue[xy.first][xy.second - 1] == true) xy.second = xy.second - 1;
            else return -1;
        }
    }
    // debug(scores);
    // debug(positions);
    return finalScore;
}

// signed main(int argc, char **argv)
// {
//     fastio();
//     init_code();
//     debug_code();

//     Maze *maze = new Maze();
//     maze->Read();

//     // maze->s = "LDDDDDLLULLLUUULLLDDRDDLDDLDDDDDLLLDDLDDRDRDDRRRUURRURUUULULDDDRRRRRRRR";
//     // maze->s = "R";
//     // maze->s = "LU";

//     cout << score(maze->xy, maze->matrix, maze->s) << nline;


//     return 0;
// }
