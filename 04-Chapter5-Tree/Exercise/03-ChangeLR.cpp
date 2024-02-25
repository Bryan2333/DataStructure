// 反转二叉树
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
void PreOrderTraverse(TreeNode*);

void Traverse(TreeNode* root) {
    if (root != nullptr) {
        std::swap(root->left, root->right);
        Traverse(root->left);
        Traverse(root->right);
    }
}

void InvertTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    Traverse(root);
}

int main(void) {
    TreeNode* root = CreateTree();

    PreOrderTraverse(root);

    InvertTree(root);

    PreOrderTraverse(root);

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

    std::cout << "请输入节点" << ch << "的左子树" << std::endl;
    root->left = CreateTree();

    std::cout << "请输入节点" << ch << "的右子树" << std::endl;
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

void PreOrderTraverse(TreeNode* root) {
    if (root != nullptr) {
        std::cout << "节点" << root->val << std::endl;
        if (root->left == nullptr) {
            std::cout << "节点" << root->val << "的左子树为空" << std::endl;
        } else {
            std::cout << "下面输出节点" << root->val << "的左子树" << std::endl;
            PreOrderTraverse(root->left);
        }

        if (root->right == nullptr) {
            std::cout << "节点" << root->val << "的右子树为空" << std::endl;
        } else {
            std::cout << "下面输出节点" << root->val << "的右子树" << std::endl;
            PreOrderTraverse(root->right);
        }
    }
}
