#include "sort.h"

/**
 * swap_node - Swap two nodes in doubly-linked list.
 * @head: head of the doubly-linked list.
 * @a: first node to swap.
 * @b:second node to swap.
 */
void swap_node(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}



/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: A pointer to the head of the doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			swap_node(list, &j, i);
			print_list((const listint_t *)*list);
		}

	}


}
