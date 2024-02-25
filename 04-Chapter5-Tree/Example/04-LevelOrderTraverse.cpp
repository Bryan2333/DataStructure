#include <iomanip>
#include <iostream>
#include <queue>

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

TreeNode* CreateTree();
void DeleteTree(TreeNode*);

// 层序遍历二叉树
void LevelOrderTraverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;

    // 根节点入队
    q.push(root);

    TreeNode* front = nullptr;
    while (!q.empty()) {
        // 获取队列元素个数
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            // 节点出队，其左右子树入队
            front = q.front();
            q.pop();
            if (front->left != nullptr) {
                q.push(front->left);
            }

            if (front->right != nullptr) {
                q.push(front->right);
            }
            std::cout << front->val;
        }
        std::cout << std::endl;
    }
}

int main() {
    TreeNode* root = CreateTree();
    LevelOrderTraverse(root);

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
