#include <iostream>

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char _val) {
        val   = _val;
        left  = nullptr;
        right = nullptr;
    }
};

TreeNode* CreateTree();
void DeleteTree(TreeNode*);

void DoubleTraverse(TreeNode* node) {
    if (node == nullptr) {
        return;
    } else if (node->left == nullptr && node->right == nullptr) {
        std::cout << node->val << std::endl;
    } else {
        std::cout << node->val;
        DoubleTraverse(node->left);
        std::cout << node->val;
        DoubleTraverse(node->right);
    }
}

int main() {
    TreeNode* root = CreateTree();

    DoubleTraverse(root);

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

void DeleteTree(TreeNode* root) {
    if (root != nullptr) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}
