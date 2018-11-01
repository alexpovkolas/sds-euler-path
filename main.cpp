#include <iostream>
#include <vector>
#import <stack>


#define __PROFILE__

#ifdef __PROFILE__

#include <cstdio>
#include <fstream>

#endif

using namespace std;


void print_euler_path(vector<vector<int>> &edges, vector<int> &result){
    int root = 1;
    stack<int> st;
    st.push(root);

    while (!st.empty()) {

        int top = st.top();
        result.push_back(top);

        if (edges[top].empty()) {
            st.pop();
        } else {
            st.push(edges[top].back());
            edges[top].pop_back();
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
        //edges[vertex2].push_back(vertex1);
    }

    print_euler_path(edges, result);

//    if (result.size() != 2*n - 1) {
//        return 1;
//    }

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
