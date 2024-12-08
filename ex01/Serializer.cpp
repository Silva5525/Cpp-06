/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:57:32 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/08 20:23:17 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/// @brief Serializes a pointer to a Data object.
/// means converting a pointer to a Data object into an
/// integer type. This is done by casting the pointer to
/// an integer type, in this case uintptr_t.
/// @param ptr the pointer to the Data object.
/// @return the serialized pointer.
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/// @brief Deserializes a pointer to a Data object.
/// @param raw the serialized pointer.
/// @return the pointer to the Data object.
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
