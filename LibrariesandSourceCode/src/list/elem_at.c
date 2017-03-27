#include "mylist.h"
#include "my.h"

void* elem_at(struct s_node* head, int n)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(n <= 0)
    {
        return head->elem;
    }
    while(n)
    {
        head = head->next;
        n--;
    }
    return head->elem;
}
