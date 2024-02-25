// 层序遍历二叉树，统计叶子节点个数
#include <iostream>
#include <queue>

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

int Level(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    std::queue<TreeNode*> q;
    int count = 0;

    q.push(root);
    TreeNode* tmp = nullptr;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp->left == nullptr && tmp->right == nullptr) {
            count++;
        }

        if (tmp->left) {
            q.push(tmp->left);
        }

        if (tmp->right) {
            q.push(tmp->right);
        }
    }
    return count;
}

int main() {
    TreeNode* root = CreateTree();

    int ret = Level(root);

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
