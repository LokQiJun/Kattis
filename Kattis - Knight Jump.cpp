#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef vector<string> vs;
typedef pair <long, long> pll;
typedef vector<pll> vll;

void check_path_bfs(vs& matrix, long k_row, long k_column, long size) {
    queue<pll> paths, dumpster; pll temp = make_pair(k_row, k_column);
    long row, column, length = 0; bool flag = 0;
    matrix[k_row][k_column] = '1';
    paths.push(temp);
    vll movements = { {2,1}, {-2,1}, {2,-1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} };
    while (++length) {
        //cout << '\n' << length << '\n';
        while (!dumpster.empty()) {
            paths.push(dumpster.front()); dumpster.pop(); // throw dumpster into process
        }
        if (paths.empty()) {
            flag = 1; break;
        }
        while (!paths.empty()) {
            temp = paths.front(); paths.pop();
            //cout << "current pos: " << temp.first << ' ' << temp.second << "\npossible moves: \n";
            for (int i = 0; i < 8; ++i) {
                row = temp.first + movements[i].first;
                column = temp.second + movements[i].second;
                if (row == 0 && column == 0) break;
                if (row >= 0 && row < size && column >= 0 && column < size && matrix[row][column] != '1' && matrix[row][column] != '#') {
                    //cout << row << ' ' << column << '\n';
                    dumpster.push(make_pair(row, column));
                    matrix[row][column] = '1';
                }
            }
            if (row == 0 && column == 0) break;
        }
        if (row == 0 && column == 0) break;
    }
    flag ? cout << -1 : cout << length;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long size, inputs, row, column; string name; bool flag = 0;
    vs matrix;
    cin >> size;
    for (long i = 0; i < size; ++i) {
        cin >> name; matrix.push_back(name);
        if (flag == 0) {
            for (long j = 0; j < size; ++j) {
                if (name[j] == 'K') {
                    row = i; column = j; break;
                }
            }
        }
    }
    if (matrix[0][0] == 'K') cout << 0;
    else check_path_bfs(matrix, row, column, size);
}
