/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:31:35 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/12 16:45:54 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Hello, World!");
	if (node == NULL)
	{
		printf("Failed to create a new node\n");
		return (1);
	}
	printf("Node content: %s\n", (char *)node->content);
	free(node);
	return (0);
} */
