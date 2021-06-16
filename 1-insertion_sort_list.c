#include "sort.h"
/**
 * insertion_sort_list - SOrts a doubly linked list
 * using insertion sort algorithm
 * @list: double ptr to the head of the unordered doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *current;

	if (list == NULL || (*list)->next == NULL)
		return;



	current = *list;
	while(current)
	{
		prev = current->prev;
		while(prev && prev->n > current->n)
		{
			swapNodes(list, prev, current);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
/**
 * swapNodes - Swaps two nodes given pointers to their addresses
 * @list: head ptr to the list in which nodeA and nodeB belong
 * @nodeA: ptr to the first node to be swapped
 * @nodeB: ptr to the second node to be swapped
 *
 * Return: Void
 */

void swapNodes(listint_t **list, listint_t  *nodeA, listint_t *nodeB)
{
	listint_t *prevA, *nextB;

	if (nodeA == NULL || nodeB == NULL)
		return;

	prevA = nodeA->prev;
	nextB = nodeB->next;


	if (prevA) /* check if node A is the head node */
		prevA->next = nodeB;

	if (nextB)
		nextB->prev = nodeA;

	nodeA->next = nextB;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
	nodeB->prev = prevA;

	if (prevA == NULL)
		*list = nodeB;
}
