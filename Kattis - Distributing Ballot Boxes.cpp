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

typedef pair<double, long> pr;
bool customCompare(pr one, pr two);

int main(){
    priority_queue <pr, vector<pr> > testt;
    long a, b;double c; pr temp_pair;cin >> a >> b;
    while(a != -1){
        for(long i = 0; i < a; ++i){
            cin >> c;
            testt.push(make_pair(c, 1));
        }
        for(long i = 0; i < (b-a); ++i){
            temp_pair = testt.top();
            testt.pop();
            temp_pair.first = (temp_pair.first * temp_pair.second) /  (temp_pair.second + 1);
            temp_pair.second += 1;
            testt.push(make_pair(temp_pair.first , temp_pair.second));
        }
        vector<double> haha;
        for(long i = 0; i < a; ++i){
            haha.push_back(testt.top().first);
            testt.pop();
        }
        sort(haha.begin(), haha.end());
        cout << ceil(haha[a-1]) << '\n';
        testt = priority_queue <pr, vector<pr> >();
        cin >> a >> b;
    }
    return 0;
}
