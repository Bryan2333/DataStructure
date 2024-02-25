#include <iostream>

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) {
        val   = _val;
        left  = nullptr;
        right = nullptr;
    }
};

TreeNode* CreateTree();
void DeleteTree(TreeNode*);

int LeafNodeCount(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return LeafNodeCount(root->left) + LeafNodeCount(root->right);
    }
}

int main() {
    TreeNode* root = CreateTree();

    int ret = LeafNodeCount(root);

    std::cout << ret << std::endl;

    DeleteTree(root);

    return 0;
}

TreeNode* CreateTree() {
    char ch;
    std::cout << "请输入节点数据(#表示空节点): ";
    std::cin >> ch;

    if (ch == '#') {
        return nullptr;
    }

    TreeNode* root = new TreeNode(ch);

    std::cout << "请输入节点" << ch << "的左子树: " << std::endl;
    root->left = CreateTree();

    std::cout << "请输入节点" << ch << "的右子树: " << std::endl;
    root->right = CreateTree();

    return root;
}

void DeleteTree(TreeNode* node) {
    if (node != nullptr) {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}
