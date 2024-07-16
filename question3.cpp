#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int globalMax = INT_MIN;
        maxPathSumHelper(root, globalMax);
        return globalMax;
    }

private:
    int maxPathSumHelper(TreeNode *node, int &globalMax)
    {
        if (!node)
            return 0;

        int leftMax = max(0, maxPathSumHelper(node->left, globalMax));
        int rightMax = max(0, maxPathSumHelper(node->right, globalMax));

        int localMax = node->val + leftMax + rightMax;
        globalMax = max(globalMax, localMax);

        return node->val + max(leftMax, rightMax);
    }
};

TreeNode *createNode(int value)
{
    TreeNode *node = new TreeNode(value);
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int main()
{
    Solution solution;
    TreeNode *a = new TreeNode(12);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(9);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    cout << "Maximum Path Sum: " << solution.maxPathSum(a) << endl;

    return 0;
}
