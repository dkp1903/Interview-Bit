// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/


vector<vector<int> >Solution:: zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > output;
        //Solution Vector of Vectors
        //output[i] is a vector containings nodes 
        //at the ith level, in the expected order
        if (root == NULL) 
            return output;
            
            
        stack<TreeNode*> cur_layer;
        stack<TreeNode*> next_layer;
        
        vector<int> layer_output;
        
        cur_layer.push(root);
        int d = 0;
        //We start with l2r
        // 0: left to right; 1: right to left.

        while (!cur_layer.empty()) 
        {
            TreeNode* node = cur_layer.top();
            cur_layer.pop();
            layer_output.push_back(node->val);
            //We have to print left to right
            //So we push left before right in the output vector
            if (d == 0)
            {
                if (node->left != NULL) 
                    next_layer.push(node->left);
                if (node->right != NULL)
                    next_layer.push(node->right);
            } 
            //We have to print right to left
            //Therefore we push right before left
            else 
            {
                if (node->right != NULL)
                    next_layer.push(node->right);
                if (node->left != NULL)
                    next_layer.push(node->left);
            }

            //Now, we have to go to the next level
            if (cur_layer.empty())
            {
                //Adding present layer output to final answer vector
                output.push_back(layer_output);
                //Emptying level output vector for next level
                layer_output.clear();
                //Changing to next level
                cur_layer.swap(next_layer);
                //Switching directions
                if (d == 1) 
                    d = 0;
                else
                    d = 1;
            }
        }
        return output;
        
    }
///////////////////////////////////////////////////////////////////////////
/*
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void zig(TreeNode* A, vector<vector<int> >& sol, bool left, int level){
    if(A == NULL){
        return;
    }
    
    if(sol.size() < level){
        vector<int> temp;
        sol.push_back(temp);
    }
    
    if(left){
        sol[level-1].push_back(A->val);
    }
    else{
        sol[level-1].insert(sol[level-1].begin(), A->val);
    }
    
    zig(A->left, sol, !left, level+1);
    zig(A->right, sol, !left, level+1);
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > sol;
    
    zig(A, sol, true, 1);
    
    return sol;
}

*/
