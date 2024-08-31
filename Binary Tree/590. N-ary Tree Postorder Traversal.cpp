// 2024/08/26
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if(!root) return ans;

        // Recursive too trivial
        // for(Node* child: root->children){
        //     postorder(child);
        // }
        // ans.push_back(root->val);
        // return ans;

        // Iteratively
        stack<Node*> stk;
        stk.push(root);

        while(!stk.empty()){
            Node* now = stk.top();
            stk.pop();

            ans.push_back(now->val);

            for(Node* child: now->children){
                stk.push(child);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};