/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:43:24 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/09 09:12:06 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/// @brief Generates a random class.
/// @return A pointer to the generated class. the return(nullptr) is
/// never reached because the switch statement covers all possible
/// cases.
Base* generate()
{
	std::srand(std::time(0));
	int r = rand() % 3;

	switch (r)
	{
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
	}
	return (nullptr);
}

/// @brief Identifies the type of the pointer.
/// @param p The pointer to identify.
/// @example Forbidden functions : std::typeinfo for this exercise becouse it
/// identify would be already solved with it:
// void identify(Base* p)
// {
//     if (p)
//         std::cout << typeid(*p).name() << "\n";
//     else
//         std::cout << "Null pointer\n";
// }
void	identify(Base* p)
{
	if (!p)
	{
		std::cout << "Null pointer\n";
		return ;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Not identified\n";
}

/// @brief Identifies the type of the reference.
/// @param p The reference to identify. (reference can't be null in C++)
/// New in C++;
/// @fn dynamic_cast to identify the type of the reference.
/// it returns a null pointer if the cast fails wich bad_cast
/// is thrown if the cast fails.
/// @fn std::bad_cast exception handling the catch block remains
/// empty because we don't need to do anything if the cast fails
/// it just should move to the next cast then.
/// @fn catch (...) is a catch-all handler that catches any exception
/// @example  functions : std::typeinfo for this exercise becouse it
/// identify would be already solved with it:
// void identify(Base& p)
// {
// 	std::cout << typeid(p).name() << "\n";
// }
void identify(Base& p)
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A";
	}
	catch (...) {}
	
	try 
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B";
	}
	catch (...) {}

	try 
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C";
	}
	catch (...) {}
}
