/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:57:34 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/08 20:22:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

#include "Data.hpp"

/// @brief Serializer class serializes and deserializes a pointer to a Data object.
/// New in C++;
/// @fn uintptr_t is a type that is capable of storing a data pointer,
/// which is a pointer to an object of any type. (unsigned integer type)
/// It has higher portability than void* and is guaranteed to be able to
/// hold a pointer to any object type. 
/// Its a ideal choice becouse we are serializing and deserializing
/// a pointer (Data*) into an integer type and back so no can be lost.
class Serializer
{
	private:
		Serializer() = delete;
		Serializer(const Serializer&) = delete;
		Serializer& operator=(const Serializer&) = delete;
		~Serializer() = delete;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif