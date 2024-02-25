// 判断两个二叉树是否具有相同的结构和数据
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

int isSameTree(TreeNode* firstRoot, TreeNode* secondRoot) {
    // 节点都为空有相同的结构
    if (firstRoot == nullptr && secondRoot == nullptr) {
        return 1;
    }

    // 其中有一个节点为空，结构不同
    if (firstRoot == nullptr || secondRoot == nullptr) {
        return 0;
    }

    // 两节点数值不相等
    if (firstRoot->val != secondRoot->val) {
        return 0;
    }

    // 递归判断两树的左子树和右子树
    return isSameTree(firstRoot->left, secondRoot->left) &&
           isSameTree(firstRoot->right, secondRoot->right);
}

int main(void) {
    TreeNode* oneRoot = CreateTree();
    TreeNode* twoRoot = CreateTree();

    int isSame = isSameTree(oneRoot, twoRoot);

    std::cout << isSame << std::endl;

    DeleteTree(oneRoot);
    DeleteTree(twoRoot);
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
