#include <iostream>
#include <vector>
#include <string>
#define INF 100000000
#define pi 3.14159265359
#define loop(x) for(int i = 0; i < x; ++i)
#define innerloop(x) for(int j = 0; j < x; ++j)
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    unsigned long long num, holder, temp, counter = 0; string input;
    cin >> num;
    loop(num) {
        cin >> holder;
        innerloop(holder) {
            cin >> temp;
            counter += temp%holder;
        }
        if (counter % holder == 0) cout << "YES \n";
        else cout << "NO \n";
        counter = 0;
    }
    return 0;
}
