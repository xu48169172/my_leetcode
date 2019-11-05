#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node_list {
    char data[16];
    struct node_list *next;
};
struct hash_table {
    int table_size;
    struct node_list **lists;
};
int hash(const char *key, int table_size)
{
    unsigned int val = 0;
    while(*key != '\0') {
        val = (val << 5) + *key++;
    }
    return val % table_size;
}
struct hash_table* hash_table_init(int table_size)
{
    struct hash_table *h = malloc(sizeof(struct hash_table));
    h->table_size = table_size;

    h->lists = malloc(h->table_size * sizeof(struct node_list));
    for (int i = 0; i < h->table_size; i++) {
        h->lists[i] = malloc(sizeof(struct node_list));
        h->lists[i]->next = NULL;
        memset(h->lists[i]->data, 0, 16);
    }
    return h;
}

struct node_list* find(const char *key, struct hash_table *h)
{
    struct node_list *head = h->lists[hash(key, h->table_size)];
    struct node_list *tmp;
    tmp = head->next;
    while (tmp != NULL && strcmp(key, tmp->data)) {
        tmp = tmp ->next;
    }
    return tmp;
}
void insert(const char *key, struct hash_table *h)
{
    struct node_list *pos = find(key, h);
    if (pos == NULL) {
        struct node_list *new = malloc(sizeof(struct node_list));
        memset(new, 0, sizeof(struct node_list));
        struct node_list *head = h->lists[hash(key, h->table_size)];
        new->next = head->next;
        head->next = new;
        strncpy(new->data, key, 15);
    }
}
int main()
{
    struct hash_table *h = hash_table_init(100);
    insert("Jack", h);
    insert("Tim", h);
    insert("Ben", h);
    struct node_list *x = find("Jack", h);
    printf("%s\n", x->data);
    x = find("Ben", h);
    printf("%s\n", x->data);
    printf("\n");
}