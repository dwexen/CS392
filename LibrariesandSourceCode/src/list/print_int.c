#include "mylist.h"
#include "my.h"

void print_int(struct s_node* node)
{
    if(node == NULL)
    {
        return;
    }
    my_int((node->elem));
}
