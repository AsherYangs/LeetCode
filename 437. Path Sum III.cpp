class Solution {
    int target = 0;
    int ans=0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int,int> m;
        m[0]=1;
        target = targetSum;
        dfs(root,m,0);
        return ans;
    }
    void dfs(TreeNode* root,unordered_map<long long int,int> m, long long int curSum){
        if(!root)
            return;
        curSum += root->val;
        if(m.find(curSum-target)!=m.end())
            ans+=m[curSum-target];
        m[curSum]++;
        dfs(root->left, m, curSum);
        dfs(root->right, m, curSum);
    }
};
