 #include "push_swap.h"
#include "push_swap.h"

void sortedInsert(t_num** head_ref, t_num* new_node)
{
    t_num* current;
    // Special case for the head end
    if (*head_ref == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
    }
    else if ((*head_ref)->num >= new_node->num)
    {
        t_num* tail = (*head_ref)->prev;
        new_node->next = *head_ref;
        new_node->prev = tail;
        tail->next = new_node;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
    }
    else
    {
        // Locate the node before the point of insertion
        current = *head_ref;
        while (current->next != *head_ref && current->next->num < new_node->num)
        {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }
}

void sortedInsert_i(t_num** head_ref, t_num* new_node)
{
    t_num* current;
    // Special case for the head end
    if (*head_ref == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
    }
    else if ((*head_ref)->i_input >= new_node->i_input)
    {
        t_num* tail = (*head_ref)->prev;
        new_node->next = *head_ref;
        new_node->prev = tail;
        tail->next = new_node;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
    }
    else
    {
        // Locate the node before the point of insertion
        current = *head_ref;
        while (current->next != *head_ref && current->next->i_input < new_node->i_input)
        {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }
}

// Function to sort the linked list using insertion sort
void insertionSort(t_num** head, char *field)
{
    t_num* sorted = NULL;
    if (!head || !(*head))
        return ;
    t_num* current = *head;
    do
    {
        t_num* next = current->next;
        current->next = current->prev = NULL; // Break the link for insertion
        if (ft_strncmp(field, "num", ft_strlen(field)) == 0)
            sortedInsert(&sorted, current);
        if (ft_strncmp(field, "input", ft_strlen(field)) == 0)
            sortedInsert_i(&sorted, current);
        current = next;
    } while (current != *head);
    *head = sorted;
}
