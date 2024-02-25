// 二叉树的创建
#include <iostream>

// 二叉树的节点的定义
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

// 创建二叉树
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

// 先序遍历二叉树
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

// 中序遍历二叉树
void InOrderTraverse(TreeNode* root) {
    if (root != nullptr) {
        InOrderTraverse(root->left);
        std::cout << "节点" << root->val << std::endl;
        InOrderTraverse(root->right);
    }
}

// 后序遍历二叉树
void PostOrderTraverse(TreeNode* root) {
    if (root != nullptr) {
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        std::cout << "节点" << root->val << std::endl;
    }
}

// 复制二叉树
TreeNode* CopyTree(TreeNode* root) {
    if (!root) {
        return root;
    } else {
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left     = CopyTree(root->left);
        newRoot->right    = CopyTree(root->right);
        return newRoot;
    }
}

// 计算二叉树深度
int MaxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth  = MaxDepth(root->left);
    int rightDepht = MaxDepth(root->right);
    int res        = (leftDepth > rightDepht ? leftDepth : rightDepht) + 1;
    return res;
}

// 统计二叉树T中的结点个数
int NodeCount(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return NodeCount(root->left) + NodeCount(root->right) + 1;
}

// 释放二叉树的内存空间
void DeleteTree(TreeNode** root) {
    if (*root != nullptr) {
        DeleteTree(&(*root)->left);
        DeleteTree(&(*root)->right);
        delete *root;
        root = nullptr;
    }
}

int main() {
    TreeNode* root = CreateTree();
    PreOrderTraverse(root);

    // int nodeNum = NodeCount(root);
    // printf("NodeNum = %d\n", nodeNum);

    // printf("复制二叉树\n");
    // TreeNode *copyRoot = (root);

    // PostOrderTraverse(root);
    std::cout << std::endl;

    DeleteTree(&root);

    return 0;
}
