#include "sort.h"
/**
 * sorted_insert - inserts a new node in a sorted list
 * @list: the sorted list
 * @newNode: the node from the unsorted list to be inserted in the
 * the new sorted list
 */
void sorted_insert(listint_t **list, listint_t *newNode)
{
	listint_t *current = NULL;

/* check if the list is empty */
	if (*list == NULL)
		*list = newNode;

	/* if the node is to be inserted before head */
	else if ((*list)->n >= newNode->n)
	{
		newNode->next = *list;
		newNode->next->prev = newNode;
		*list = newNode;
	}
	else
	{
		current = *list;
/* locate the node after which the new node is to be inserted */


		while (current->next != NULL && current->next->n < newNode->n)
		{
			current = current->next;
		}
		newNode->next = current->next;
		if (current->next)
			newNode->next->prev = newNode;
		current->next = newNode;
		newNode->prev = current;
	}
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in an ascending
 * @list: Double pointer to the doubly linked list to be sorted
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *temp = NULL, *current = *list;

	while (current != NULL)
	{
		temp = current->next;
		current->prev = current->next = NULL;
		sorted_insert(&sorted, current);
		current = temp;
	}

	*list = sorted;
	print_list(sorted);
}
