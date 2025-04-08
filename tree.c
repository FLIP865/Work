#include <endian.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct node {
    struct node *parent;
    struct node *left;
    struct node *right;
    void *data;
};

struct stacknode {
    struct stacknode *next;
    struct node *data;
};

void push(struct stacknode **stack, struct node *data);
void iterative_preorder(struct node *root);
void free_tree(struct node *root);
int empty(const struct stacknode *stk);
struct node *pop(struct stacknode **top);
struct node *create_node(int value);

int main() {
    struct node *root = create_node(1);
    root->left = create_node(2);
    root->left->left = create_node(4);
    root->left->left->left = create_node(5);
    root->left->left->left->left = create_node(6);
    root->left->left->left->left->left = create_node(7);
    root->left->left->left->left->left->left = create_node(3);

    root->left->parent = root;
    root->left->left->parent = root->left;
    root->left->left->left->parent = root->left->left;
    root->left->left->left->left->parent = root->left->left->left;
    root->left->left->left->left->left->parent = root->left->left->left->left;
    root->left->left->left->left->left->left->parent = root->left->left->left->left->left;

    printf("Preorder traversal: ");
    iterative_preorder(root);
    printf("\n");

    free_tree(root);
    
#if 0
    free(root->left->left->right->right->left->data);
    free(root->left->left->right->right->left);
    free(root->left->left->left->right->right->data);
    free(root->left->left->right->right);
    free(root->left->left->right->data);
    free(root->left->left->right);
    free(root->left->left->left->data);
    free(root->left->left->left);
#endif 
    return 0;
}

void free_tree(struct node *root)
{
    if (root == NULL) return;
    struct stacknode *stack = NULL;
    struct node *current = root;
    struct node *last_visited = NULL;

    while (current != NULL || stack != NULL)
    {
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }

        struct node *peek = stack->data;

        if (peek->right != NULL && last_visited != peek->right) {
            current = peek->right;
        } else {
            struct node *to_free = pop(&stack);
            last_visited = to_free;
            free(to_free->data);
            free(to_free);
        }
    }
}

int empty(const struct stacknode *stk)
{
    if (stk == NULL)
        return 1;
    return 0;
}

void iterative_preorder(struct node *root)
{
    if (root == NULL) return;

    struct stacknode *top = NULL;
    push(&top, root);

    while (!empty(top))
    {
        struct node *current = pop(&top);
        printf("%d ", *(int *)(current->data));

        if (current->right != NULL)
        {
            push(&top, current->right);
        }
        else if (current->left != NULL)
        {
            push(&top, current->left);
        }
    }
}

struct node *create_node(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = malloc(sizeof(int));
    *(int*)(new_node->data) = value;
    return new_node;
}

void push(struct stacknode **stack, struct node *data)
{
    struct stacknode *tmp = calloc(1, sizeof(struct stacknode));
    tmp->data = data; tmp->next = *stack;
    *stack = tmp;
}

struct node *pop(struct stacknode **top)
{
    struct node *data = (*top)->data;
    struct stacknode *next = (*top)->next;
    free(*top);
    (*top) = next;
    return data;
}
