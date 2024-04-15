/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:48:56 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/15 11:51:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

/* int	main(void)
{
	t_list	*list;

	list = ft_lstnew("Hello, world!");
	printf("Before deletion: %s\n", (char *)list->content);
	ft_lstdelone(list, free);
	printf("After deletion: %s\n", (char *)list->content);
	return (0);
}
 */