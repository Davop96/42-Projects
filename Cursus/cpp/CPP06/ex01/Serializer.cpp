/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 21:20:33 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/08/04 21:20:37 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//Convert a pointer to a Data object into an unsigned integer (uintptr_t)
uintptr_t Serializer::serialize(Data *ptr)
{
    // reinterpret_cast is used to convert the pointer to a value of type uintptr_t
    return (reinterpret_cast<uintptr_t>(ptr));
}

// Converts an unsigned integer (uintptr_t) into a pointer to a Data object
Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}