#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

map<char, int> order = {
    {'B', 0},
    {'G', 1},
    {'C', 2}
};

int movesWithThisDistribution(string dist, const vector<int>& v) {
    int ans = 0;
    for(int i = 0; i < 3; ++i)
        for(int j = order[dist[i]]; j < 9; j+=3)
            if(j/3!=i) ans += v[j];
    return ans;
}

int main() {
    string line;
    int x;
    while(getline(cin, line)) {
        map<int, set<string> > moves_with_distribution;
        string distribution = "BCG";
        istringstream iss(line);
        vector<int> bins;
        for(int i = 0; i < 9; ++i) {
            iss >> x;
            bins.push_back(x);
        }
        do {
            moves_with_distribution[movesWithThisDistribution(distribution, bins)].insert(distribution);
        } while(next_permutation(distribution.begin(), distribution.end()));
        
        map<int,set<string> >::iterator it = moves_with_distribution.begin();
        set<string>::iterator dists = it->second.begin();
        cout << (*dists) << " " << it->first << endl;
    }
}