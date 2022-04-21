#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_list - prints all elements of a list
 * @h: pointer to address of first node
 * Return: size_t
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	if (h == NULL)
		exit(0);

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");

		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		n++;
	}
	return (n);
}
