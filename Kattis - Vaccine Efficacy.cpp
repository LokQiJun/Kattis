//https://nus.kattis.com/problems/vaccineefficacy

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef vector<vector< string >> vvs;
typedef pair <long, string> ps;
typedef vector<ps> vs;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long a, b, c, n; string temp; double rate1, rate2;
    long av = 0, ac = 0, bv = 0, bc = 0, cc = 0, cv = 0, sum_c = 0, sum_v = 0;
    cin >> n;
    for (long i = 0; i < n; ++i) {
        cin >> temp;
        if (temp[0] == 'Y') {
            ++sum_v;
            if (temp[1] == 'Y') ++av;
            if (temp[2] == 'Y') ++bv;
            if (temp[3] == 'Y') ++cv;
        }
        else {
            ++sum_c;
            if (temp[1] == 'Y') ++ac;
            if (temp[2] == 'Y') ++bc;
            if (temp[3] == 'Y') ++cc;
        }
    }
    cout << setprecision(6) << fixed;
    rate1 = (double)av / sum_v; rate2 = (double)ac / sum_c;
    //cout << rate1 << ' ' << rate2 << '\n';
    if (rate1 >= rate2) cout << "Not Effective \n";
    else cout << 100 * (1 - rate1 / rate2) << '\n';
    rate1 = (double)bv / sum_v; rate2 = (double)bc / sum_c;
    //cout << rate1 << ' ' << rate2 << '\n';
    if (rate1 >= rate2) cout << "Not Effective \n";
    else cout << 100 * (1 - rate1 / rate2) << '\n';
    rate1 = (double)cv / sum_v; rate2 = (double)cc / sum_c;
    //cout << rate1 << ' ' << rate2 << '\n';
    if (rate1 >= rate2) cout << "Not Effective \n";
    else cout << 100 * (1 - rate1 / rate2) << '\n';
    return 0;
}
