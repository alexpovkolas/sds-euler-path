#include <iostream>
#include <vector>


//#define __PROFILE__

#ifdef __PROFILE__

#include <cstdio>
#include <fstream>

#endif

using namespace std;


void print_euler_path(vector<vector<int>> &edges){
    int root = 1;
    int next = root;

    while (true) {
        cout << next << " ";

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

    for (int i = 0; i < n - 1; ++i) {
        int vertex1 = 0;
        int vertex2 = 0;
        cin >> vertex1 >> vertex2;
        edges[vertex1].push_back(vertex2);
        edges[vertex2].push_back(vertex1);
    }

    print_euler_path(edges);

#ifdef __PROFILE__

#endif

    cout << endl;

    return 0;
}
