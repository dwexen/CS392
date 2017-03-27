#include "mylist.h"
#include "my.h"

void add_node_at(struct s_node* node, struct s_node** head, int n)
{
    struct s_node* current;
    if(node == NULL || node->elem == NULL || head == NULL)
    {
        return;
    }
    current = (*head);
    if(n <= 0 || *head==NULL)
    {
        add_node(node, head);
        return;
    }
    while(n > 1 && current->next != NULL)
    {
        current = current->next;
        n--;
    }
    node->next = current->next;
    if (node->next != NULL)
    {
        node->next->prev = node;   
    }
    current->next = node;
    node->prev = current;
}
