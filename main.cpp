#include <iostream>
#include <vector>


#define __PROFILE__

#ifdef __PROFILE__

#include <cstdio>
#include <fstream>

#endif

using namespace std;


void print_euler_path(vector<vector<int>> &edges, vector<int> &result){
    int root = 1;
    int next = root;

    while (true) {
        result.push_back(next);

        if (edges[next].empty()) {
            break;
        } else {
            int prev = next;
            next = edges[next].back();
            edges[prev].pop_back();
        }
    }
}

int main() {
#ifdef __PROFILE__
    ifstream in("input");
    cin.rdbuf(in.rdbuf());
#endif

    int n = 0;
    cin >> n;

    vector<vector<int>> edges(n + 1);
    vector<int> result;
    result.reserve(2*n-1);

    for (int i = 0; i < n - 1; ++i) {
        int vertex1 = 0;
        int vertex2 = 0;
        cin >> vertex1 >> vertex2;
        edges[vertex1].push_back(vertex2);
        edges[vertex2].push_back(vertex1);
    }

    print_euler_path(edges, result);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

#ifdef __PROFILE__

#endif

    cout << endl;

    return 0;
}
