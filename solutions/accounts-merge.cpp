//Accounts Merge -> 07/17/2020 18:43
class Solution {
 int accountsMerge_findParent(int idx, vector<int>& p) {
    if (p[idx] == idx) return idx;
    p[idx] = accountsMerge_findParent(p[idx], p);
    return p[idx];
}
public:
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> res;

    vector<int> p(accounts.size());
    for (int i = 0; i < p.size(); ++i) p[i] = i;

    map<string, int> m;

    for (int i = 0; i < accounts.size(); ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            if (m.count(accounts[i][j])) {
                int tmp = m[accounts[i][j]];

                int p1 = accountsMerge_findParent(tmp, p);
                int p2 = accountsMerge_findParent(i, p);
                p[p2] = p1;
                continue;
            }
            m[accounts[i][j]] = i;
        }
    }

    for (int i = 0; i < p.size(); ++i) p[i] = accountsMerge_findParent(i, p);

    unordered_map<int, int> myIdx;

    for (auto& it : m) {
        if (!myIdx.count(p[it.second])) {
            myIdx[p[it.second]] = (int)res.size();
            res.push_back(vector<string>{});
            res.back().push_back(accounts[it.second][0]);
        }
        res[myIdx[p[it.second]]].push_back(it.first);
    }

    return res;
}
};
