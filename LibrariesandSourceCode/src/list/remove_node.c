#include "mylist.h"
#include "my.h"

void* remove_node(struct s_node** node)
{
    void* temp; 
    if(node == NULL || (*node) == NULL)
    {
        return NULL;
    }
    temp = (*node)->elem;
    if((*node)->next == NULL)
    {
        free((*node));
        (*node) = NULL;
        return temp;
    }
    (*node) = (*node)->next;
    free((*node)->prev);
    (*node)->prev = NULL;
    return temp;
}
