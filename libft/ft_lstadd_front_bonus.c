/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:51:58 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/12 16:56:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* int	main(void)
{
	t_list	*list;
	t_list	*new_node;

	list = NULL;
	new_node = ft_lstnew("Hello");

	ft_lstadd_front(&list, new_node);
	if (list)
	{
		printf("First element: %s\n", (char *)list->content);
		printf("Next element: %p\n", list->next);
	}
	else
	{
		printf("List is empty\n");
	}
	return (0);
}
 */