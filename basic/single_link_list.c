#include <stdio.h>
#include <stdlib.h>

struct node_list {
    int val;
    struct node_list *next;
};
int is_node_list_empty(struct node_list *head)
{
    return head->next == NULL;
}
// 找到 key
struct node_list *find(struct node_list *head, int key)
{
    struct node_list *p;
    p = head->next;
    while (p != NULL && p->val != key)
        p = p->next;
    return p;
}
struct node_list *find_previous(struct node_list *head, int key)
{
    struct node_list *p;
    p = head;
    while (p->next != NULL && p->next->val != key)
        p = p->next;
    return p;
}
int is_last(struct node_list *p)
{
    return p->next == NULL;
}
void delete(struct node_list *head, int key)
{
    struct node_list *p;
    struct node_list *tmp;
    p = find_previous(head, key);
    if (!is_last(p)) {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}
void insert(struct node_list *head, int key)
{
    struct node_list *tmp = malloc(sizeof(struct node_list));
    memset(tmp, 0, sizeof(struct node_list));
    tmp->val = key;
    tmp->next = head->next;
    head->next = tmp;
}
struct node_list head;
int main()
{
    head.val = -1;
    head.next = NULL;
    for (int i = 0; i < 10; i++) {
        insert(&head, i);
    }
    struct node_list *p;
    for (p = head.next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
    delete(&head, 0);
    delete(&head, 9);
    for (p = head.next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
}