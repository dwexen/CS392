#include "mylist.h"
#include "my.h"

void debug_char(struct s_node* head)
{
    struct s_node* current;
    if(head == NULL)
    {
        return;
    }
    if(count_s_nodes(head) == 1)
    {
        current = head;
        my_str("(NULL <- ");
        my_char((elem_at(current,0)));
        my_str(" -> NULL)");
        return;    
    }
    current = head;
    my_str("(NULL <- ");
    my_char((elem_at(current,0)));
    my_str(" -> ");
    my_char((elem_at(current->next,0)));
    my_str(" ) ");
    current = current->next;
    while(current->next != NULL)
    {
        my_str("( ");
        my_char((elem_at(current->prev,0)));
        my_str(" <- ");
        my_char((elem_at(current,0)));
        my_str(" -> ");
        my_char((elem_at(current->next,0)));
        my_str(" ) ");
        current = current->next;
    }
    my_str("( ");
    my_char((elem_at(current->prev,0)));
    my_str(" <- ");
    my_char((elem_at(current,0)));
    my_str(" -> NULL)");
}
