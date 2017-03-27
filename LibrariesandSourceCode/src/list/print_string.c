#include "mylist.h"
#include "my.h"

void print_string(struct s_node* node)
{
    if(node == NULL)
    {
        return;
    }
    my_str(node->elem);
}
