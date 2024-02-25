#include <filesystem>
#include <iostream>
#include <vector>

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

void Traverse(TreeNode* node, std::vector<std::vector<int>>& allPaths,
              std::vector<int>& path) {
    if (node == nullptr) {
        return;
    }

    path.emplace_back(node->val);

    // 遇到叶子节点就将当前路径添加进allPaths中
    if (node->left == nullptr && node->right == nullptr) {
        allPaths.emplace_back(path);
    }

    Traverse(node->left, allPaths, path);
    Traverse(node->right, allPaths, path);

    path.pop_back();
}

std::vector<std::vector<int>> AllPath(TreeNode* root) {
    std::vector<std::vector<int>> allPaths;
    std::vector<int> path;
    Traverse(root, allPaths, path);
    return allPaths;
}

int main() {
    TreeNode* root = CreateTree();

    std::vector<std::vector<int>> paths = AllPath(root);

    for (auto& path : paths) {
        for (auto& val : path) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    DeleteTree(root);

    return 0;
}

TreeNode* CreateTree() {
    int val;
    std::cout << "请输入节点数据(-1表示空节点): ";
    std::cin >> val;

    if (val == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);

    std::cout << "请输入节点" << val << "的左子树: " << std::endl;
    root->left = CreateTree();

    std::cout << "请输入节点" << val << "的右子树: " << std::endl;
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
