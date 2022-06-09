#include "lists.h"
/**
 * add_to_node - adds node to head
 * @h: pointer to list
 * @n: index
 * Return: dlistint_t
 */
dlistint_t *add_to_node(dlistint_t **h, int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *h;
	(*h)->prev = new;
	*h = new;
	return (new);
}
/**
 * insert_dnodeint_at_index - inserts node at a given position
 * @h: pointer to doubly linked list
 * @idx: index where node is to be inserted
 * @n: data to be added
 * Return: dlistint_t
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *ptr = *h, *hld, *new;
	unsigned int number = 0;

	if (*h == NULL)
		return (NULL);
	if (idx == 0)
	{
		new = add_to_node(h, n);
		return (new);
	}
	while (ptr)
	{
		if (idx == number)
		{
			new = malloc(sizeof(dlistint_t));
			if (new == NULL)
				return (NULL);
			new->n = n;
			hld->next = new;
			new->prev = hld;
			new->next = ptr;
			ptr->prev = new;
			return (new);
		}
		hld = ptr;
		ptr = ptr->next;
		number++;
	}
	if (idx == number)
	{
		new = malloc(sizeof(dlistint_t));
		if (new == NULL)
			return (NULL);
		new->n = n;
		hld->next = new;
		new->prev = hld;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}