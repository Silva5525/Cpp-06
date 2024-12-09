/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:46:00 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/08 22:23:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/// New in C++;
/// @fn dynamic_cast to identify the type of the reference.
/// it returns a null pointer if the cast fails wich bad_cast
/// is thrown if the cast fails.
/// @fn std::bad_cast exception handling the catch block remains
/// empty because we don't need to do anything if the cast fails
/// it just should move to the next cast then.
/// @fn catch (...) is a catch-all handler that catches any exception
int	main(void)
{
	Base* base = generate();

	std::cout << "Identify pointer: ";
	identify(base);

	std::cout << "\nIdentify reference: ";
	identify(*base);
	std::cout << std::endl;

	delete base;

	return (0);
}
