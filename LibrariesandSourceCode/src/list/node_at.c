#include "mylist.h"
#include "my.h"

struct s_node* node_at(struct s_node* head, int n)
{
    if(head == NULL)
    {
        return NULL;
    }
    my_str("past head == NULL\n");
    if(n <= 0)
    {
        return head;
    }
    my_str("past n<=0\n");
    while(n > 1 && head->next != NULL)
    {
        my_str("before head->next\n");
        head = head->next;
        my_str("after head->next\n");
        n--;
    }
    my_str("past n while loop");
    return head;
}
