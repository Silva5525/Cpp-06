/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:43:28 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/08 22:24:50 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

#include <ctime>
#include <cstdlib>

/// @brief Base class destructor.
/// The base class is the parent class of A, B and C.
/// The destructor is virtual to ensure that the derived classes
/// destructors are called when the base class is deleted.
class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif