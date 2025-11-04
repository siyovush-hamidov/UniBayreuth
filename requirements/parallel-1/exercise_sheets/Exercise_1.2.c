#include <stdio.h>
#include <stdlib.h>

typedef struct NODE Node;
struct NODE
{
    int key;
    Node *smaller_keys;
    Node *larger_keys;
};
typedef struct
{
    Node *root;
} Tree;

Tree tree_create()
{
    Tree t;
    t.root = NULL;
    return t;
}

Node *create_node(int key)
{
    Node *n = (Node *)(malloc(sizeof(Node)));
    if (n == NULL)
    {
        return NULL;
    }
    n->key = key;
    n->larger_keys = NULL;
    n->smaller_keys = NULL;
    return n;
}

void tree_insert_key(Tree *t, int key)
{
    if (t->root == NULL)
    {
        t->root = create_node(key);
    }
    else
    {
        Node *current = t->root;
        while (1)
        {
            if (key == current->key)
            {
                return;
            }
            if (key < current->key)
            {
                if (current->smaller_keys == NULL)
                {
                    current->smaller_keys = create_node(key);
                    return;
                }
                else
                {
                    current = current->smaller_keys;
                }
            }
            if (key > current->key)
            {
                if (current->larger_keys == NULL)
                {
                    current->larger_keys = create_node(key);
                    return;
                }
                else
                {
                    current = current->larger_keys;
                    return;
                }
            }
        }
    }
}