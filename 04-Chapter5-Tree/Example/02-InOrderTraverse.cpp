// 中序遍历二叉树的非递归算法
#include <iostream>
#include <stack>

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

void InOrderTraverse(TreeNode* root) {
    TreeNode* node    = root;
    TreeNode* newNode = nullptr;

    std::stack<TreeNode*> s;

    while (node || !s.empty()) {
        if (node) {
            s.push(node);
            node = node->left;
        } else {
            newNode = s.top();
            s.pop();
            std::cout << newNode->val << std::endl;
            node = newNode->right;
        }
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* root = CreateTree();

    InOrderTraverse(root);

    DeleteTree(root);

    return 0;
}

TreeNode* CreateTree() {
    char ch;
    printf("请输入节点数据(#表示空节点): ");
    scanf(" %c", &ch);

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
