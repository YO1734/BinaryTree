#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функція для пошуку або додавання вершини зі значенням E
void find_or_insert(TreeNode*& root, int E) {
    if (root == nullptr) {
        // Дерево порожнє, створюємо нову вершину
        root = new TreeNode(E);
        std::cout << "A peak with meaning " << E << " added to the tree." << std::endl;
        return;
    }

    if (E == root->data) {
        // Вершина з таким значенням вже існує в дереві
        std::cout << "A peak with meaning " << E << " already exists in the tree." << std::endl;
    }
    else if (E < root->data) {
        // Значення E менше поточної вершини, рекурсивно шукаємо або додаємо в лівому піддереві
        find_or_insert(root->left, E);
    }
    else {
        // Значення E більше поточної вершини, рекурсивно шукаємо або додаємо в правому піддереві
        find_or_insert(root->right, E);
    }
}
// Функція для видалення всього дерева
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);  // Рекурсивно видаляємо ліве піддерево
    deleteTree(root->right); // Рекурсивно видаляємо праве піддерево

    delete root; // Видаляємо поточну вершину
}

int main() {
    TreeNode* root = nullptr; // Початкове порожнє дерево

    // Приклад використання: шукаємо або додаємо вершину зі значенням 10
    find_or_insert(root, 10);

    // Приклад використання: шукаємо або додаємо вершину зі значенням 5
    find_or_insert(root, 5);

    // Приклад використання: шукаємо або додаємо вершину зі значенням 10 (вже існує)
    find_or_insert(root, 10);

    // Звільнення пам'яті після використання дерева
    deleteTree(root);

    return 0;
}