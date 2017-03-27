#include "mylist.h"
#include "my.h"

void add_node(struct s_node* node, struct s_node** head)
{
    if(node == NULL || node->elem == NULL || head == NULL)
    {
        return;
    }

    node->next = *head;
    if((*head) != NULL)
    {
        (*head)->prev = node;
    }
    (*head) = node;
}
