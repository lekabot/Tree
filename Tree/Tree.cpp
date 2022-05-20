#include <iostream>
using namespace std;

//СТРУКТУРА
struct Node
{
    Node* l, * r;
    int x;
};

int HeightOfTree(Node* node)
{
    if (node == 0)
        return 0;
    int left = 0, right = 0;
    if (node->l != NULL) {
        left = HeightOfTree(node->l);
    }
    else
        left = -1;
    if (node->r != NULL) {
        right = HeightOfTree(node->r);
    }
    else
        right = -1;
    int max = left > right ? left : right;
    cout << max + 1;
    return 0;
}
//Filling the tree
void add(int x, Node*& MyTree)
{
    if (MyTree == NULL)
    {
        MyTree = new Node;
        MyTree->x = x;
        MyTree->l = MyTree->r = NULL; 
    }

    if (x < MyTree->x)
    {
        if (MyTree->l != NULL) add(x, MyTree->l);
        else
        {
            MyTree->l = new Node;
            MyTree->l->l = MyTree->l->r = NULL;
            MyTree->l->x = x;
        }
    }

    if (x > MyTree->x)
    {
        if (MyTree->r != NULL) add(x, MyTree->r);
        else
        {
            MyTree->r = new Node;
            MyTree->r->l = MyTree->r->r = NULL;
            MyTree->r->x = x;
        }
    }
}
//Reverse array traversal
void Show(Node*& tree)
{
    if (NULL == tree)    return;

    Show(tree->l);
    Show(tree->r);  
    cout << tree->x << ' '; 
}
//Tree output
void inOrder(Node* root)
{
    if (root != NULL)
    {
        cout << root->x << " ";
        inOrder(root->l);
        inOrder(root->r);
    }
}
//tree height
int heigh(Node* root)
{
    if (root == NULL) {
        return 0;
    }
    else if (root->l == NULL && root->r == NULL) {
        return 0;
    }
    else if (heigh(root->l) > heigh(root->r))
        return heigh(root->r) + 1;
    else
        return heigh(root->l) + 1;
}

int main()
{
    int x, b;
    Node* MyTree = NULL;
    cout << "Haw many brunch of tree?" << endl;
    cin >> b;
    cout << "Specify an array" << endl;
    for (int i = 0; i < b; i++)
    {
        cin >> x;
        add(x, MyTree);
    }
    cout << "Tree output"<<endl;
    inOrder(MyTree);
    cout << endl;
    cout << "Reverse array traversal" << endl;
    Show(MyTree);
    cout << endl;
    int height = 0;
    height = heigh(MyTree);
    cout << "Tree height" << endl;
    cout << height;
    return 0;
}