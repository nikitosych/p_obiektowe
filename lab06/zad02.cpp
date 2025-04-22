#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class BST_node
{
public:
    int key;
    class BST_node *left, *right;
};
class BST_node *newNode(int item)
{
    class BST_node *temp = new BST_node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
bool search(class BST_node *root, int key) 
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    search(root->left, key);
    search(root->right, key);
    return false; // postorder traversal
}

int powtorki(class BST_node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1 + powtorki(root->left, key) + powtorki(root->right, key);
    return powtorki(root->left, key) + powtorki(root->right, key);
}

void inorder(class BST_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " < ";
        inorder(root->right);
    }
}

void preorder(class BST_node *root) 
{
    if (root != NULL)
    {
        cout << root->key << " < ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(class BST_node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " < ";
    }
}
class BST_node *insert(class BST_node *BST_node, int key)
{
    if (BST_node == NULL)
        return newNode(key);
    if (key < BST_node->key)
        BST_node->left = insert(BST_node->left, key);
    else
        BST_node->right = insert(BST_node->right, key);
    return BST_node;
}
class BST_node *minValueNode(class BST_node *BST_node)
{
    class BST_node *current = BST_node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
class BST_node *deleteNode(class BST_node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            class BST_node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            class BST_node *temp = root->left;
            delete (root);
            return temp;
        }
        class BST_node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main()
{
    srand(time(NULL));
    class BST_node *root = NULL;
    int tab[8] = {0};
    for (int i = 0; i <= 7; ++i)
    {
        tab[i] = rand() % 20;
        root = insert(root, tab[i]);
    }
    cout << "Wylosowano: ";
    for (int i = 0; i <= 7; ++i)
        cout << tab[i] << " ";
    cout << endl;
    cout << "Elementy drzewa: ";
    inorder(root);
    cout << "\nUsuwamy tab[4]\n";
    root = deleteNode(root, tab[4]);
    cout << "Elementy drzewa: ";
    inorder(root);

    cout << "\nWyszukiwanie 3: " << (search(root, 17) ? "Znaleziono" : "Nie znaleziono") << endl;
    cout << "Ile razy wystepuje 15: " << powtorki(root, 15) << endl;
}