/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode Node;

class Solution {
public:
	unordered_map<int, Node*> old_id2node, new_id2node;
	unordered_map<int, int> vis;
	
	Node* dfs(Node *node) {
		int lab = node->label;
		vis[lab] = 1;
		old_id2node[lab] = node;
		new_id2node[lab] = new Node(lab);
		Node* cur = new_id2node[lab];
		int sz = node->neighbors.size();
		for (int i = 0; i < sz; i ++) {
			Node* nei = node->neighbors[i];
			if (vis[nei->label] == 0) {
				dfs(nei);
			}
			cur->neighbors.push_back(new_id2node[nei->label]);
		}
		return cur;
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;

		Node *res = dfs(node);
		return res;
    }
};