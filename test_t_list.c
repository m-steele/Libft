// Tester for the t_list functions

#include "libft.h"

void print_content(void *content)
{
	ft_printf("%s\n", (char *)content);
}

int main (void)
{
	t_list node3 = { "World!", NULL };
	t_list node2 = { "Hello", &node3 };
	t_list node1 = { "Yo!", &node2 };

	ft_lstiter(&node1, print_content);
	return(0);
}
