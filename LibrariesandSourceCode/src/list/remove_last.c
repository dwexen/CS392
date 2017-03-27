#include "mylist.h"
#include "my.h"

void* remove_last(struct s_node** node)
{
    void* temp;
    struct s_node* current;
    if(node == NULL || (*node) == NULL)
    {
        return NULL;
    }
    current = *node;
    temp = current->elem;
    my_str("past first check\n");
    if(current->next == NULL)
    {
        my_str("before remove\n");
        remove_node(node);
        my_str("after remove\n");
        return temp;
    }
    my_str("past second check\n");
    while(current->next != NULL)
    {
        current = current->next;
    }
    temp = current->elem;
    current->prev->next = NULL;
    free(current->next);
    return temp;
}
