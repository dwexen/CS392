#include "mylist.h"
#include "my.h"

void traverse_string(struct s_node* head)
{
    struct s_node* current;
    if(head == NULL)
    {
        return;
    }
    current = head;
    while(current->next != NULL)
    {
        my_str(current->elem);
        my_str(" ");
        current = current->next;
    }
    my_str(current->elem);
}
