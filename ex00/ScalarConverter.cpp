/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:38:26 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/07 18:40:22 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/// @brief Checks for real literals with length == 1/ isdigit/ isprint.
/// @param str to check.
/// @return true if the string is a real literal, false otherwise.
static bool realLiteral(const std::string& str)
{
	return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

/// @brief Checks for pseudo-literals.
/// +inf (positive infinity) and -inf (negative infinity) represent overflow or
/// unbounded positive/negative values in floating-point arithmetic.
/// If the string is not "nan", it is one of the infinity values (+inf, -inf, +inff, -inff).
/// @param str The string to check.
/// @return returns true if the string is a pseudo-literal, false otherwise.
static bool fakeLiteral(const std::string& str)
{
	return (str == "+inf" || str == "-inf" || str == "nanf"
			|| str == "+inff" || str == "-inff" || str == "nan");
}

/// @brief checks if the string is a mashup of literals like "-+123kio42" or "123,42f".
/// @param str string to check.
/// @return false if the string is a mashup of literals, true otherwise.
/// @author why is this not already standard function in C++? xD
static bool mashupLiteral(const std::string& str)
{
	bool fpoint = false;
	bool sign = false;

	for (size_t i = 0; i < str.length(); ++i)
	{
		char c = str[i];
		if (std::isdigit(c))
			continue;
		if ((c == '+' || c == '-') && i == 0)
		{
			if (sign)
				return (false);
			sign = true;
			continue;
		}
		if (c == '.')
		{
			if (fpoint)
				return (false);
			fpoint = true;
			continue;
		}
		if (c == 'f' && i == str.length() - 1) continue;
			return (false);
	}
	return (true);
}

/// @brief converts a string to a scalar value in the 4 formats: char, int, float, double.
/// @param str to convert.
/// New in C++;
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
void ScalarConverter::convert(const std::string& str)
{
	std::cout << std::fixed << std::setprecision(1);

	if (realLiteral(str))
	{
		std::cout << "char: '" << str[0] << "'. "
				<< "int: " << static_cast<int>(str[0]) << ". "
				<< "float: " << static_cast<float>(str[0]) << "f. "
				<< "double: " << static_cast<double>(str[0])
				<< ". \n";
		return ;
	}
	
	if (fakeLiteral(str))
	{
		std::string sign = (str[0] == '-') ? "-" : "+";
		if (str == "nan" || str == "nanf")
			std::cout << "char: No. int: No. float: nanf. double: nan.\n";
		else
			std::cout << "char: No. int: No. float: "
					<< sign << "inff double: " << sign << "inf\n";
		return ;
	}

	try
	{
		if (!mashupLiteral(str))
			throw std::invalid_argument("mashupLiteral");
		int i = std::stoi(str);
		std::cout << "char: ";
		if (isprint(i) && (str.find('.') == std::string::npos))
			std::cout << "'" << static_cast<char>(i) << "'. ";
		else
			std::cout << "No. ";
		std::cout << "int: " << i << ". "
				<< "float: " << std::stof(str) << "f. "
				<< "double: " << std::stod(str) << ". \n";
		return ;
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Invalid argument: Cannot convert '" << str << "' .\n";
	}
	catch (const std::out_of_range&)
	{
		    std::cerr << "Out of range: '" << str << "' is too long.\n";
	}

	std::cout << "char: No. "
			<< "int: No. "
			<< "float: No. "
			<< "double: No. \n";
}
