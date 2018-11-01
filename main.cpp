#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>



#define __PROFILE__

#ifdef __PROFILE__

#include <cstdio>
#include <fstream>

#endif

using namespace std;


int main() {
#ifdef __PROFILE__
    ifstream in("input");
    cin.rdbuf(in.rdbuf());
#endif

    int n = 0;
    vector<pair<int, int>> edges(n);

    for (int i = 0; i < n; ++i) {
        cin >> edges[i].first>> edges[i].second;
    }


#ifdef __PROFILE__

#endif

    cout << endl;

    return 0;
}
