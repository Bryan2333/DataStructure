// 二叉排序树
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) {
        val   = _val;
        left  = nullptr;
        right = nullptr;
    }
};

// 二叉排序树的查找算法
TreeNode* SearchBST(TreeNode* root, int key) {
    if (root == nullptr || root->val == key) {
        return root;
    } else if (key < root->val) {
        return SearchBST(root->left, key);
    } else if (key > root->val) {
        return SearchBST(root->right, key);
    }
    return nullptr;
}

// 二叉排序树的插入节点算法
void InsertNode(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
    } else if (val < root->val) {
        InsertNode(root->left, val);
    } else if (val > root->val) {
        InsertNode(root->right, val);
    }
}

// 二叉排序树的创建算法
TreeNode* CreateTree() {
    TreeNode* root = nullptr;
    int val;

    for (;;) {
        std::cin >> val;

        if (val == -1) {
            break;
        }

        InsertNode(root, val);
    }

    return root;
}

// 二叉排序树的删除节点算法
void DeleteNode(TreeNode* root, int key) {
    TreeNode* p = root;
    TreeNode* f = nullptr;

    while (p) {
        if (p->val == key) {
            break;
        }
        f = p;
        if (p->val > key) {
            p = p->left;
        } else if (p->val < key) {
            p = p->right;
        }
    }

    if (!p) {
        return;
    }

    // 如果p的左右子树均不为空
    if (p->left && p->right) {
        TreeNode* s = p->left;
        TreeNode* q = p;
        while (s->right != nullptr) {
            q = s;
            s = s->right;
        }

        p->val = s->val;
        if (q == p) {
            q->left = s->left;
        } else {
            q->right = s->left;
        }
        delete s;
        return;
    }

    TreeNode* child = nullptr;
    if (p->left) { // p无右子树
        child = p->left;
    } else if (p->right) { // p无左子树
        child = p->right;
    }

    if (!f) {
        root = child;
    } else if (p == f->left) {
        f->left = child;
    } else {
        f->right = child;
    }
    delete p;
}

// 中序遍历二叉排序树
void InOrderTraverse(TreeNode* root) {
    if (root != nullptr) {
        InOrderTraverse(root->left);
        std::cout << root->val << std::endl;
        InOrderTraverse(root->right);
    }
}

// 判断二叉树是否为二叉排序树
int isBinarySortTree(TreeNode* root) {
    if (root) {
        if (root->left && root->left->val > root->val) {
            return 0;
        }

        if (root->right && root->right->val < root->val) {
            return 0;
        }
        return isBinarySortTree(root->left) && isBinarySortTree(root->right);
    }
    return 1;
}

void DeleteTree(TreeNode* root) {
    if (root != nullptr) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}

int main() {
    TreeNode* root = CreateTree();

    int ret = isBinarySortTree(root);

    std::cout << ret << std::endl;

    DeleteTree(root);

    return 0;
}
