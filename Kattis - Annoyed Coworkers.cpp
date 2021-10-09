//https://nus.kattis.com/problems/annoyedcoworkers

#include <iostream>
#include <stdlib.h>
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
using namespace std;

typedef pair<long, long> pr;
bool customCompare(pr one, pr two);

int main(){
    long h, c, temp1, temp2; cin >> h >> c;
    priority_queue<pr, vector<pr>, decltype(&customCompare) > testt(customCompare);
    for(long i = 0; i < c; ++i){
        cin >> temp1 >> temp2;
        testt.push( make_pair(temp1, temp2));
    }
    pr temp_pair;
    for(long i = 0; i < h; ++i){
        temp_pair = testt.top();
        testt.pop();
        temp_pair.first += temp_pair.second;
        testt.push(make_pair(temp_pair.first , temp_pair.second));
    }
    vector<long> haha;
    for(long i = 0; i < c; ++i){
        haha.push_back(testt.top().first);
        testt.pop();
    }
    sort(haha.begin(), haha.end());
    cout << haha[c-1];
    return 0;
}

bool customCompare(pr one, pr two){
    if ((one.first + one.second) < (two.first + two.second)) return false;
    return true;
}

