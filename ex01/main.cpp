/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:10:04 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/08 20:40:44 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/// @brief test main for Serializer class.
/// it creates a Data object, serializes it, deserializes it and 
/// compares the original and the deserialized object.
/// @note New in C++;
/// @param uintptr_t is a type that is capable of storing a data pointer,
/// which is a pointer to an object of any type. (unsigned integer type)
/// It has higher portability than void* and is guaranteed to be able to
/// hold a pointer to any object type. 
/// Its a ideal choice becouse we are serializing and deserializing
/// a pointer (Data*) into an integer type and back so no can be lost.
int	main(void)
{
	Data firstData = {42, "Max Power"};

	std::cout << "Original Data adress: " << &firstData << '\n';

	uintptr_t serialData = Serializer::serialize(&firstData);
	std::cout << "Serialized (uintptr_t): " << serialData << '\n';

	Data* deSerialData = Serializer::deserialize(serialData);

	std::cout << "Deserialized Data address: " << deSerialData << '\n';

	if (deSerialData == &firstData)
		std::cout << "Deserialized: Id: " << deSerialData->id << " Name: " 
			<< deSerialData->name << '\n';
	else
		std::cout << "Deserialization failed.\n";
		
	return (0);
}
