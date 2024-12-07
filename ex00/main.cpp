/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:41:34 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/07 18:42:13 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/// @brief simple test main for ScalarConverter.
/// New in C++; (check ScalarConverter.cpp for more details)
/// @fn std::fixed sets the format of floating-point output to fixed notation.
/// @fn std::setprecision() sets the decimal precision to be used to 
/// format floating-point values on output operations (if 1 -> 1 decimal = 4,22 -> 4,2).
/// @fn isprint() checks if a character is printable.
/// @fn std::stoi() (s to i) converts a string or substr to an integer.
/// @fn std::stof() (s to f) converts a string or substr to a float.
/// @fn std::stod() (s to d) converts a string or substr to a double.
/// @fn str.find() returns the position of the first occurrence of a substring.
/// @fn std::string::npos is a static member constant value with the greatest possible value
/// for an element of type size_t. (indicates no matches found)
/// @fn std::invalid_argument is a standard exception class that is thrown when an argument
/// with invalid value like "abc".
/// @fn std::out_of_range is a standard exception class that is thrown when an argument
/// is out of range like "999999999999" or INTMAX + 1.
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./scalar <literal> \n";
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	
	return (0);
}