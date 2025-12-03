#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	int flag = 0;

	while (list)
	{
		if (flag)
			printf(", ");
		printf("%d", list->n);
		flag = 1;
		list = list->next;
	}
	printf("\n");
}
