#include <iostream>
#include <queue>

#define MAXSIZE 255

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

int Width(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    std::queue<TreeNode*> q;

    q.push(root);
    int maxWidth = 0;

    TreeNode* tmp = nullptr;
    while (!q.empty()) {
        int currWidth = q.size();
        maxWidth      = currWidth > maxWidth ? currWidth : maxWidth;
        for (int i = 0; i < currWidth; i++) {
            tmp = q.front();
            q.pop();

            if (tmp->left) {
                q.push(tmp->left);
            }

            if (tmp->right) {
                q.push(tmp->right);
            }
        }
    }

    return maxWidth;
}

int main() {
    TreeNode* root = CreateTree();

    int ret = Width(root);

    std::cout << ret << std::endl;

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
