#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree_t {
    struct tree_t *parent;
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

struct stacknode {
    struct stacknode *next;
    struct tree_t *data;
};

void free_tree_iterative(struct tree_t *root);
void push(struct stacknode **stack, struct tree_t *data);
struct tree_t *pop(struct stacknode **top);
struct tree_t *create_node(int value);
int check_is_bst_par(struct tree_t *top, int l_border, int r_border);
int check_is_bst(struct tree_t *top);

int main()
{
    struct tree_t *t1 = create_node(4);
    t1->left = create_node(2);
    t1->right = create_node(9);
    t1->left->left = create_node(1);
    t1->right->left = create_node(6);
    t1->right->right = create_node(10);
    t1->right->left->left = create_node(5);
    t1->right->left->left->left = create_node(8);

    t1->left->parent = t1;
    t1->right->parent = t1;
    t1->left->left->parent = t1->left;
    t1->right->left->parent = t1->right;
    t1->right->right->parent = t1->right;
    t1->right->left->left->parent = t1->right->left;
    t1->right->left->left->left->parent = t1->right->left->left;

    struct tree_t *t2 = create_node(4);
    t2->left = create_node(2);
    t2->right = create_node(9);
    t2->left->left = create_node(1);
    t2->right->left = create_node(6);
    t2->right->right = create_node(10);
    t2->right->left->left = create_node(5);
    t2->right->left->left->left = create_node(8);

    t2->left->parent = t2;
    t2->right->parent = t2;
    t2->left->left->parent = t2->left;
    t2->right->left->parent = t2->right;
    t2->right->right->parent = t2->right;
    t2->right->left->left->parent = t2->right->left;
    t2->right->left->left->left->parent = t2->right->left->left;

    printf("First case = %d\n", check_is_bst(t1));

    free_tree_iterative(t1);
    free_tree_iterative(t2);

    t1 = create_node(4);
    t1->left = create_node(2);
    t1->right = create_node(9);
    t1->left->left = create_node(1);
    t1->right->left = create_node(6);
    t1->right->right = create_node(10);
    t1->right->left->left = create_node(5);
    t1->right->left->left->left = create_node(8);

    t1->left->parent = t1;
    t1->right->parent = t1;
    t1->left->left->parent = t1->left;
    t1->right->left->parent = t1->right;
    t1->right->right->parent = t1->right;
    t1->right->left->left->parent = t1->right->left;
    t1->right->left->left->left->parent = t1->right->left->left;

    t2 = create_node(4);
    t2->left = create_node(2);
    t2->right = create_node(8);
    t2->left->left = create_node(1);
    t2->right->left = create_node(6);
    t2->right->right = create_node(9);
    t2->right->left->left = create_node(5);
    t2->right->right->right = create_node(10);

    t2->left->parent = t2;
    t2->right->parent = t2;
    t2->left->left->parent = t2->left;
    t2->right->left->parent = t2->right;
    t2->right->right->parent = t2->right;
    t2->right->left->left->parent = t2->right->left;
    t2->right->right->right->parent = t2->right->right;

    printf("Second case = %d\n", check_is_bst(t2));

    free_tree_iterative(t1);
    free_tree_iterative(t2);

    return 0;
}

int check_is_bst_par(struct tree_t *top, int l_border, int r_border)
{
    if ((top->data <= l_border) || (top->data >= r_border))
        return 0;

    if (top->left)
        if (!check_is_bst_par(top->left, l_border, top->data))
            return 0;

    if (top->right)
        if (!check_is_bst_par(top->right, top->data, r_border))
            return 0;
    return 1;
}

int check_is_bst(struct tree_t *top)
{
    return check_is_bst_par(top, INT_MIN, INT_MAX);
}

void push(struct stacknode **stack, struct tree_t *data)
{
    struct stacknode *tmp = calloc(1, sizeof(struct stacknode));
    tmp->data = data;
    tmp->next = *stack;
    *stack = tmp;
}

struct tree_t *pop(struct stacknode **top)
{
    struct tree_t *data = (*top)->data;
    struct stacknode *next = (*top)->next;
    free(*top);
    (*top) = next;
    return data;
}

void free_tree_iterative(struct tree_t *root)
{
    if (root == NULL) return;

    struct stacknode *stack = NULL;
    struct tree_t *current = root;
    struct tree_t *last_visited = NULL;

    while (current != NULL || stack != NULL)
    {
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        
        struct tree_t *peek = stack->data;

        if (peek->right != NULL && last_visited != peek->right) {
            current = peek->right;
        } else {
            struct tree_t *to_free = pop(&stack);
            last_visited = to_free;
            free(to_free);
        }
    }
}

struct tree_t *create_node(int value)
{
    struct tree_t *new_node = (struct tree_t *)malloc(sizeof(struct tree_t));
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = value;
    return new_node;
}
