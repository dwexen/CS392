#include "mylist.h"
#include "my.h"

void traverse_char(struct s_node* head)
{
    struct s_node* current;
    if(head == NULL)
    {
        return;
    }
    current = head;
    while(current->next != NULL)
    {
        my_char(*(char*)(current->elem));
        my_str(" ");
        current = current->next;
    }
    my_char(*(char*)(current->elem));
}
