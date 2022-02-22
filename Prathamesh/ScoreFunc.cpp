#include <bits/stdc++.h>

using namespace std;

int score(pair<int, int> current, vector<vector<pair<int, int>>> &matrix, string s)
{

    int finalScore = 0;
    pair<int, int> xy = current;

    // vector<int>scores;
    // vector<int>positions;

    vector<vector<bool>> Istrue(50, vector<bool>(50, true));

    for (int i = 0; i <= s.size(); i++){

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
