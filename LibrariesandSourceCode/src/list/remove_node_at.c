#include "mylist.h"
#include "my.h"

void* remove_node_at(struct s_node** head, int n)
{
    struct s_node* current;
    void* temp;
    if(head == NULL || (*head) == NULL)
    {
        return NULL;
    }
    my_str("past first null check\n");
    current = (*head);
    temp = current->elem;
    if(n <= 0 || (*head)->next == NULL)
    {
        remove_node(head);
        return temp;
    }
    my_str("past n<= 0 check\n");
    while(current->next != NULL && n > 0)
    {
        current = current->next;
        n--;
    }
    temp = current->elem;
    if(current->next == NULL)
    {
        current->prev->next = NULL;
        free(current);
        return temp;
    }
    my_str("past current->next !=NULL || n==0\n");
    current->prev->next = current->next;
    my_str("past current->prev->next\n");
    current->next->prev = current->prev;
    my_str("past current->prev->next\n");
    my_str("past temp = current->elem");
    free(current);
    return temp;
}
