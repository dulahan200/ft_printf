/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:03:42 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/12 18:10:36 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Parameters lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.
Return value The new list.
NULL if the allocation fails.
External functs. malloc, free
Description Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list rsting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

#include "libft.h"
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_new;
	t_list	*rst_lst;

	if (!f || !del)
		return (NULL);
	rst_lst = NULL;
	while (lst)
	{
		node_new = ft_lstnew(f(lst->content));
		if (!node_new)
		{
			ft_lstclear(&rst_lst, del);
			del(node_new);
			return (NULL);
		}
		ft_lstadd_back(&rst_lst, node_new);
		lst = lst->next;
	}
	return (rst_lst);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_new;
	t_list	*rst_lst;
	t_list	*tmp;

	if (!f || !del)
		return (NULL);
	rst_lst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		node_new = ft_lstnew(tmp);
		if (!node_new)
		{
			ft_lstclear(&rst_lst, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&rst_lst, node_new);
		lst = lst->next;
	}
	return (rst_lst);
}
