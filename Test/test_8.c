#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *Insert(struct node *root, int key)
{
    struct node *p, *temp;
    p = root;
    temp = (struct node *)(malloc(sizeof(struct node)));
    temp->data = key;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while (p->next != NULL)
            p = p->next;

        p->next = temp;
    }
    return root;
}

struct node *Delete(struct node *root, int key)
{
    struct node *p = root;
    struct node *q = NULL;
    if (p->data == key)
    {
        root = root->next;
        free(p);
    }
    else
    {
        while (p != NULL && p->data != key)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }
    return root;
}
void display(struct node *root)
{
    struct node *p = root;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

int main()
{
    printf("\n\tName -- Suman Kumar   Roll No -- 210010140013\n");
    printf("\t Class -- BTech I.T (3rd SEM)\n");
    int arr[] = {1, 2, 3, 4, 5};
    struct node *root = NULL;
    for (int i = 0; i < 5; i++)
    {
        root = Insert(root, arr[i]);
    }
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    printf("\nLinked list before delete : ");
    display(root);
    root = Delete(root, 10);
    printf("Linked list after delete : ");
    display(root);
    return 0;
} 
