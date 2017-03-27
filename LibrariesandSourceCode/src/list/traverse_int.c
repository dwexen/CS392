#include "mylist.h"
#include "my.h"

void traverse_int(struct s_node* head)
{
    struct s_node* current = head;
    if(head == NULL)
    {
        return;
    }
    while(current->next != NULL)
    {
        my_int(*(int*)(current->elem));
        my_str(" ");
        current = current->next;
    }
    my_int(*(int*)(current->elem));
}
