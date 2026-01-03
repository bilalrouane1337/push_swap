#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int				x;
	struct node		*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	new->next = NULL;
	if (*lst)
	{
        start = *lst;
		while (start->next)
			start = start->next;
		start->next = new;
	}
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return;
	while (*lst)
	{
		tmp = (*lst)->next;  // save next node
		free(*lst);          // free current node
		*lst = tmp;          // move to next node
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	new->next = *lst;  // point new node to current head
	*lst = new;        // update head
}

void keep_it_sorted_mine_two(t_list **node, int indexx)
{
	t_list *new_node = malloc(sizeof(t_list));

	t_list *temp = *node;
	t_list *sub = temp;
	
	new_node->x = indexx;

	if (!*node || temp->x >= indexx)
	{
		new_node->next = temp;
		*node = new_node;
		return ;
	}
	while (temp && temp->x < indexx)
	{
		sub = temp;
		temp = temp->next;
	}
	new_node->next = temp;
	sub->next = new_node;
	
}

void keep_it_sorted_mine_one(t_list **node, int indexx)
{
	t_list *new_node = malloc(sizeof(t_list));

	t_list *temp = *node;

	new_node->x = indexx;
	if(temp->next && temp->x < indexx)
	{
		while (temp->next && temp->next->x < indexx)
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	else if (temp->x > indexx)
	{
		new_node->next = temp;
		*node = new_node;
	}
	else if (!temp->next)
	{
		temp->next = new_node;
		new_node->next = NULL;
	}
}

void ft_lstadd_after(t_list *node, t_list *new)
{
    if (!node || !new)
        return;
    new->next = node->next; // point new node to the next of current node
    node->next = new;       // insert new node after current node
}

void ft_lstdel_node_mine(t_list **lst, t_list *node)
{
	t_list *temp = *lst;

	if (!lst || !*lst || !node)
		return;

	if (temp == node)
	{
		*lst = node->next;
		free(node);
		return;
	}
	while (temp->next && temp->next != node)
	{
		temp = temp->next;
	}
	if (temp->next)
	{
		temp->next = node->next;
		free(node);
	}
}

void	ft_lstbdd_sorted(t_list **lst, int i)
{
	t_list	*curr;

	t_list *new = malloc(sizeof(t_list));

	new->x = i;
	if (*lst == NULL || i < (*lst)->x)
	{
		new->next = *lst;
		*lst = new;
		return;
	}

	curr = *lst;
	while (curr->next && curr->next->x < i)
		curr = curr->next;

	new->next = curr->next;
	curr->next = new;
}

void	rev(t_list **lst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	if (!lst || !*lst)
		return;

	prev = NULL;
	curr = *lst;

	while (curr)
	{
		next = curr->next;   // save next node
		curr->next = prev;   // reverse link
		prev = curr;         // move prev forward
		curr = next;         // move curr forward
	}
	*lst = prev;            // update head
}


void reverse_mine(t_list **lst)
{
	t_list *curr = *lst;

	if (curr && curr->next)
	{
	
		t_list *prev = NULL;
		t_list *next = curr->next;
		t_list *next_next = curr->next->next;

		
		curr->next = prev;
		
		while (next)
		{
			next->next = curr;
			prev = curr;
			curr = next;
			next = next_next;
			if (next_next)
				next_next = next_next->next;
		}
		*lst = curr;
	}
}

int	main(void)
{
	t_list	*list = NULL;
	t_list	*tmp = NULL;

	t_list	*one = malloc(sizeof(t_list));
	t_list	*onee = malloc(sizeof(t_list));
	t_list	*two = malloc(sizeof(t_list)); 
	t_list	*three = malloc(sizeof(t_list)); 
	t_list	*four = malloc(sizeof(t_list));

	one->x = 5; 
	two->x = 10; three->x = 15; four->x = 20;

	ft_lstadd_back(&list, one); 
	ft_lstadd_back(&list, two); 
	ft_lstadd_back(&list, three); 
	ft_lstadd_back(&list, four);

	// ft_lstadd_sorted(&list, 18);

	tmp = list;
	while (tmp)
	{
		printf("%d -> ", tmp->x);
		tmp = tmp->next;
	}
	printf("NULL\n");


	// ft_lstclear(&list);

	rev(&list);

	tmp = list;
	while (tmp)
	{
		printf("%d -> ", tmp->x);
		tmp = tmp->next;
	}
	printf("NULL\n");

	// free(three);
	// free(two);
	// free(one);

	return (0);
}
