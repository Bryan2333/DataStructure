#include <iostream>

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val   = 0;
        left  = nullptr;
        right = nullptr;
    }

    TreeNode(char _val) {
        val   = _val;
        left  = nullptr;
        right = nullptr;
    }
};

TreeNode* CreateBiTree();
void DeleteTree(TreeNode*);
void PreOrderTraverse(TreeNode*);

// 交换节点的左右孩子
void ExchangeChild(TreeNode* root) {
    if (root != nullptr) {
        std::swap(root->left, root->right);
        ExchangeChild(root->left);
        ExchangeChild(root->right);
    }
}

int main(void) {
    for (;;) {
        TreeNode* root = CreateBiTree();

        if (root == nullptr) {
            break;
        }

        ExchangeChild(root);
        PreOrderTraverse(root);
        std::cout << std::endl;

        DeleteTree(root);
    }

    return 0;
}

TreeNode* CreateBiTree() {
    char ch;
    std::cin >> ch;

    if (ch == '0') {
        return nullptr;
    }

    TreeNode* root = new TreeNode(ch);

    root->left  = CreateBiTree();
    root->right = CreateBiTree();
    return root;
}

void DeleteTree(TreeNode* root) {
    if (root != nullptr) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}

void PreOrderTraverse(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val;
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}
