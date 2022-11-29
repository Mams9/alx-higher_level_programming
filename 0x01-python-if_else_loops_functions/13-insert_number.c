#include "lists.h"


/**
 * insert_node - Inserts a number into a sorted singly-linked list.
 * @head: A pointer the head of the linked list.
 * @number: The index of list where the new node isi added.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *h;
	listint_t *h_prev;

	h = *head;
	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	while (h != NULL)
	{
		if (h->n > number)
			break;
		h_prev = h;
		h = h->next;
	}

	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = h;
		if (h == *head)
			*head = new;
		else
			h_prev->next = new;
	}

	return (new);
}
