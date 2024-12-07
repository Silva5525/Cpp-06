/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:38:11 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/07 17:35:28 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

/// @brief ScalarConverter class converts a string to a scalar value.
/// @note New in C++;
/// @see delete is used to prevent the creation of objects of this class.
/// because we only want to use the static method convert.
/// (anyways its private too so it can't be accessed from outside the class).
class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;

	public:
		static void convert(const std::string& str);

};

#endif