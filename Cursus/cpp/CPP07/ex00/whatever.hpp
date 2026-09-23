/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:13:02 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/09 11:14:36 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

template <typename T> void swap(T &first, T &second)
{
	T third = first;
	first = second;
	second = third;
}

template <typename T> const T &min(const T &first, const T &second)
{
	if (first < second)
		return (first);
	return (second);
}

template <typename T> const T &max(const T &first, const T &second)
{
	if (first > second)
		return (first);
	return (second);
}