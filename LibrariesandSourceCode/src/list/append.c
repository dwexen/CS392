#include "mylist.h"
#include "my.h"

void append(struct s_node* node, struct s_node** head)
{
    struct s_node* current;
    if(head == NULL || node->elem == NULL || node == NULL)
    {
        return;
    }
    current = (*head);
    if(current == NULL)
    {
        add_node(node, head);
        return;
    }
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
    node->prev = current;
}
