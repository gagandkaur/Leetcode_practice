
class Solution {
public:
    vector<vector<int>> original, modified;
    vector<int> last, ans;

    void findParents(int node, vector<int>& parent, string& s) {
        int c = s[node] - 'a';
        int previous = last[c];

        if (node != 0 && previous != -1) {
            // Closest matching ancestor
            modified[previous].push_back(node);
        } else if (node != 0) {
            modified[parent[node]].push_back(node);
        }

        last[c] = node;

        for (int child : original[node]) {
            findParents(child, parent, s);
        }

        last[c] = previous;
    }

    int dfsSize(int node) {
        int size = 1;

        for (int child : modified[node]) {
            size += dfsSize(child);
        }

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        original.resize(n);
        modified.resize(n);
        ans.resize(n);
        last.assign(26, -1);

        for (int i = 1; i < n; i++) {
            original[parent[i]].push_back(i);
        }

        findParents(0, parent, s);
        dfsSize(0);

        return ans;
    }
};
