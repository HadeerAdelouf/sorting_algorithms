#include"sort.h"

/**
 * Swap_Nodes - swap 2 nodes in double LS
 * @first : first node address
 * @second :second node address
 * Return : void
 */
void Swap_Nodes(listint_t *first, listint_t *second)
{
    if (first->prev)
        first->prev->next = second;
    if (second->next)
            second->next->prev = first;
    first->next = second->next;
    second->prev = first->prev;
    first->prev = second;
    second->next = first;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *x, *j;

        if (!(*list)->next || !list || !*list)
            return;
        x = (*list)->next;
        while (x)
        {
            j = x;
            x = x->next;
            while (j && j->prev)
            {
                if (j->prev->n > j->n)
                {
                    Swap_Nodes(j->prev, j);
                    if (!j->prev)
                        *list = j;
                    print_list((const listint_t *)*list);
                }
                else
                    j = j->prev;
            }
        }
}
