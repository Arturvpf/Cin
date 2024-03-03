#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Graph {
public:
    vector<pair<string, int>> ranking;
    vector<pair<string, vector<string>>> edges;
    set<string> added_names;

    void addEdge(string a, string b, string c) {
        if (!added_names.count(a)) {
            ranking.push_back({a, -1});
            added_names.insert(a);
        }
        if (!added_names.count(b)) {
            ranking.push_back({b, -1});
            added_names.insert(b);
        }
        if (!added_names.count(c)) {
            ranking.push_back({c, -1});
            added_names.insert(c);
        }

        edges.push_back({a, {b, c}});
        edges.push_back({b, {a, c}});
        edges.push_back({c, {a, b}});
    }

    void bfs() {
        queue<string> q;
        q.push("Ahmad");
        for (auto &it : ranking) {
            if (it.first == "Ahmad") {
                it.second = 0;
                break;
            }
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            for (auto &it : edges) {
                if (it.first == current) {
                    for (string &neighbor : it.second) {
                        for (auto &it2 : ranking) {
                            if (it2.first == neighbor && it2.second == -1) {
                                for (auto &it3 : ranking) {
                                    if (it3.first == current) {
                                        it2.second = it3.second + 1;
                                        break;
                                    }
                                }
                                q.push(neighbor);
                            }
                        }
                    }
                }
            }
        }
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        Graph graph;

        while (N--) {
            string a, b, c;
            cin >> a >> b >> c;
            graph.addEdge(a, b, c);
        }

        graph.bfs();

        vector<pair<int, string>> contestants;
        vector<string> undefined_rank;
        for (auto& it : graph.ranking) {
            if (it.second == -1) {
                undefined_rank.push_back(it.first);
            } else {
                contestants.push_back({it.second, it.first});
            }
        }

        sort(contestants.begin(), contestants.end());

        cout << contestants.size() + undefined_rank.size() << endl;
        for (auto& contestant : contestants) {
            cout << contestant.second << " " << contestant.first << "\n";
        }
        sort(undefined_rank.begin(), undefined_rank.end()); // Ordena os nomes undefined
        for (auto& name : undefined_rank) {
            cout << name << " undefined\n";
        }
    }

    return 0;
}