#include <iostream>
#include <sstream>

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

    string serialize(TreeNode *root)
    {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    // Helper function for serialization
    void serializeHelper(TreeNode *node, ostringstream &out)
    {
        if (node)
        {
            out << node->val << " ";
            serializeHelper(node->left, out);
            serializeHelper(node->right, out);
        }
        else
        {
            out << "# "; // Use "#" to represent null nodes
        }
    }

    // Helper function for deserialization
    TreeNode *deserializeHelper(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    // Serialize the tree
    string serialized = a->serialize(a);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the serialized string
    TreeNode *deserialized = a->deserialize(serialized);

    return 0;
}
