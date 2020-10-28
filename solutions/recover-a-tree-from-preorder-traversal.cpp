//Recover a Tree From Preorder Traversal -> 06/06/2020 17:43

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        TreeNode* root;
        int i = 0;
        int num = 0;
        // while(S[i] != '-')
        // {
        //    num = num *10 + ((int)S[i] - 48);
        //     i++;
        // }
            
        // root = new TreeNode(num);
        
        int len = S.size();
        // map<int, vector<int> > freq;
        stack<pair<TreeNode*, int> > stk;
        // stk.push(make_pair(root, 0));
        int count = 0;
        num = 0;
        S[len] = '-';
        for(i = 0; i <= len; i++)
        {
            if(S[i] != '-')
            {
                num = num*10 + ((int)S[i] - 48);
            }
            else if(S[i - 1] == '-' && S[i] == '-')
                count++;
            else if(S[i - 1] != '-' && S[i] == '-')
            {
                // if(i == 1)
                // {
                //     count = 1;
                // }
                // else
                // {
                    TreeNode* temp;
                    temp = new TreeNode(num);
                    if(stk.empty())
                    {
                        stk.push(make_pair(temp, count));
                        root = temp;
                    }
                    else 
                    {
                        if(count < stk.top().second)
                        {
                            while(count <= stk.top().second)
                                stk.pop();
                            if(!stk.empty())
                            {
                               if(stk.top().first->left)
                                    stk.top().first->right = temp;
                                else
                                    stk.top().first->left = temp; 
                            }

                            stk.push(make_pair(temp, count));
                        }

                        else if(count > stk.top().second)
                        {
                            if(!stk.empty())
                            {
                                if(stk.top().first->left)
                                    stk.top().first->right = temp;
                                else
                                    stk.top().first->left = temp;
                            }

                            stk.push(make_pair(temp, count));
                        }
                        else if(count == stk.top().second)
                        {
                            TreeNode* var = stk.top().first;
                            stk.pop();
                            if(!stk.empty())
                            {
                                if(stk.top().first->left)
                                    stk.top().first->right = temp;
                                else
                                    stk.top().first->left = temp;
                            }

                            stk.push(make_pair(var, count));
                            stk.push(make_pair(temp, count));
                        }
                    }
                    
                        count = 1;
                        num = 0;
                }
                    
            // }
            
        }
        // TreeNode* temp;
        // temp = new TreeNode(num);
        // if(stk.top().first->left)
        //     stk.top().first->right = temp;
        // else
        //     stk.top().first->left = temp;
        
        return root;
    }
};