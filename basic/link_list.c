#include <stdio.h>
#include <stdio.h>
#include <string.h>

struct link_list {
    struct link_list *pre;
    struct link_list *next;
    int data;
};
void list_init(struct link_list *l)
{
    l->next = l;
    l->pre = l;
}
void _list_add(struct link_list *pre, struct link_list *next, struct link_list *l)
{
    l->next = next;
    l->pre = pre;
    pre->next = l;
    next->pre = l;
}
void list_add_tail(struct link_list *head, struct link_list *l)
{
    _list_add(head->pre, head, l);
}
void list_add_head(struct link_list *head, struct link_list *l)
{
    _list_add(head, head->next, l);
}
void list_del(struct link_list *l)
{
    l->pre->next = l->next;
    l->next->pre = l->pre;
}
struct link_list HEAD={
    .pre = &HEAD,
    .next = &HEAD,
    .data = -1
};
void delete(int val)
{
    struct link_list *tmp;
    for (tmp=HEAD.next; tmp != &HEAD; tmp = tmp->next) {
        if (tmp->data == val) {
            list_del(tmp);
            //break; //如果多个元素都等于val
        }
    }

}
int main()
{   
    for (int i = 0; i< 10; i++) {
        struct link_list *d = malloc(sizeof(struct link_list));
        memset(d, 0, sizeof(struct link_list));
        d->data = i;
        list_add_tail(&HEAD, d);
    }
    struct link_list *tmp;
    for (tmp=HEAD.next; tmp != &HEAD; tmp = tmp->next) {
        printf("%d ", tmp->data);
    }
    printf("\n");

    for (int i = 0; i< 10; i++) {
        struct link_list *d = malloc(sizeof(struct link_list));
        memset(d, 0, sizeof(struct link_list));
        d->data = i;
        list_add_head(&HEAD, d);
    }
    delete(9);
    delete(8);
    for (tmp=HEAD.next; tmp != &HEAD; tmp = tmp->next) {
        printf("%d ", tmp->data);
    }
    printf("\n");
    return 0;
}