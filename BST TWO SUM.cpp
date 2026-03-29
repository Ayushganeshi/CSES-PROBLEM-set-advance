
class Solution {
public:
    void traverse(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)return;
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        traverse(root,ans);
        map<int,int>mp;
        
        for(int i=0;i<ans.size();i++)
        {
            auto it=mp.find(k-ans[i]);
            if(it!=mp.end())
            {
                return true;
            }
            mp[ans[i]]++;
        }
        return false;

    }
};
