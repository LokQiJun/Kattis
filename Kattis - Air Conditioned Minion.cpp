#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define loop(x) for(int i = 0; i < x; ++i)
using namespace std;
typedef pair <long, long> pll;
typedef vector<pll> vll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long num_minion, low, high, counter = 0; vll temp_range;
    cin >> num_minion;
    loop(num_minion) {
        cin >> low >> high;
        temp_range.push_back(make_pair(low, high));
    }
    sort(temp_range.begin(), temp_range.end());
    low = -1; high = -1;
    loop(num_minion) {
        if (temp_range[i].first <= high && temp_range[i].first >= low) {
            high = min(temp_range[i].second, high);
            low = temp_range[i].first;
        }
        else {
            low = temp_range[i].first;
            high = temp_range[i].second;
            ++counter;
        }
    }
    cout << counter;
    return 0;
}
