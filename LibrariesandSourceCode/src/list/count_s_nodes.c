#include "mylist.h"
#include "my.h"

int count_s_nodes(struct s_node* head)
{
    int length = 0;
    struct s_node* current = head;
    while(current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}
