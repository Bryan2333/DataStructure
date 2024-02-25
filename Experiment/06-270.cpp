// 统计二叉树中度数分别为0, 1, 2的节点
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

void CountDu(TreeNode* root, int& duZero, int& duOne, int& duTwo) {
    if (root == nullptr) {
        return;
    } else if (root->left == nullptr && root->right == nullptr) {
        ++duZero;
    } else if (root->left != nullptr && root->right != nullptr) {
        ++duTwo;
    } else if ((root->left != nullptr && root->right == nullptr) ||
               (root->right == nullptr && root->left != nullptr)) {
        ++duOne;
    }

    CountDu(root->left, duZero, duOne, duTwo);
    CountDu(root->right, duZero, duOne, duTwo);
}

int main(void) {
    for (;;) {

        TreeNode* root = CreateTree();

        if (root == nullptr) {
            break;
        }

        int duZero = 0;
        int duOne  = 0;
        int duTwo  = 0;

        CountDu(root, duZero, duOne, duTwo);

        std::cout << duZero << " " << duOne << " " << duTwo << std::endl;

        DeleteTree(root);

        duZero = 0;
        duOne  = 0;
        duTwo  = 0;

        std::cin.ignore();
    }

    return 0;
}

TreeNode* CreateTree() {
    char ch;

    std::cin >> ch;

    if (ch == '0') {
        return nullptr;
    }

    TreeNode* root = new TreeNode(ch);

    root->left  = CreateTree();
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
