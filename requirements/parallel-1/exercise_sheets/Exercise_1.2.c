#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

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
                }
            }
        }
    }
}

int find_recursive(Node *current, int target_key)
{
    if (current == NULL)
    {
        return 0;
    }
    if (current->key == target_key)
    {
        return 1;
    }
    if (target_key < current->key)
    {
        return find_recursive(current->smaller_keys, target_key);
    }
    else if (target_key > current->key)
    {
        return find_recursive(current->larger_keys, target_key);
    }
}

int tree_find_key_recursive(Tree *t, int target_key)
{
    return find_recursive(t->root, target_key);
}

int tree_find_key_iterative(Tree *t, int target_key)
{
    Node *current = t->root;
    while (current != NULL)
    {
        if (current->key == target_key)
        {
            return 1;
        }
        if (target_key < current->key)
        {
            current = current->smaller_keys;
        }
        else if (target_key > current->key)
        {
            current = current->larger_keys;
        }
    }
    return 0;
}

int is_valid_recursive(Node *current, int min_value, int max_value)
{
    if (current == NULL)
    {
        return 1;
    }
    if (current->key <= min_value || current->key >= max_value)
    {
        return 0;
    }

    int left, right;

    left = is_valid_recursive(current->smaller_keys, min_value, current->key);
    right = is_valid_recursive(current->larger_keys, current->key, max_value);

    return left * right;
}

int tree_is_valid(Tree *t)
{
    Node *current = t->root;
    return is_valid_recursive(current, INT_MIN, INT_MAX);
}

Node *copy_recursive(Node *current)
{
    if (current == NULL)
    {
        return NULL;
    }
    else
    {
        Node *new_node = create_node(current->key);

        new_node->smaller_keys = copy_recursive(current->smaller_keys);
        new_node->larger_keys = copy_recursive(current->larger_keys);

        return new_node;
    }
}

Tree tree_deep_copy(Tree *t)
{
    Tree new_tree;

    new_tree.root = copy_recursive(t->root);

    return new_tree;
}

void delete_recursive(Node *current)
{
    if (current == NULL)
    {
        return;
    }
    else
    {
        delete_recursive(current->smaller_keys);
        delete_recursive(current->larger_keys);
        free(current);
    }
}

void tree_delete(Tree *t)
{
    delete_recursive(t->root);
    t->root = NULL;
}

void print_in_order(Node *current)
{
    if (current == NULL)
    {
        return;
    }
    print_in_order(current->smaller_keys);
    printf("%d ", current->key);
    print_in_order(current->larger_keys);
}

int main()
{
    srand(time(NULL));

    Tree t = tree_create();
    int i = 0;
    for (i; i < 15; i++)
    {
        tree_insert_key(&t, rand() % 30);
    }

    printf("Tree cotnents: ");
    print_in_order(t.root);
    printf("\n");

    printf("Find 0 iterative: %i \n", tree_find_key_iterative(&t, 0));
    printf("Find 50 iterative: %i \n", tree_find_key_iterative(&t, 50));

    printf("Find 0 recursive: %i \n", tree_find_key_recursive(&t, 0));
    printf("Find 50 recursive: %i \n", tree_find_key_recursive(&t, 50));

    printf("Tree is valid: %i \n", tree_is_valid(&t));

    Tree copy = tree_deep_copy(&t);

    tree_delete(&t);
    printf("Copy contents: ");
    print_in_order(copy.root);
    printf("\n");
    tree_delete(&copy);
}