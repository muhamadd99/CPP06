/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:52:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/12 15:05:48 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>

void	ScalarConverter::handleInvalid(const std::string& param)
{
	std::cout << "This is not a literal" << std::endl;
}

void	ScalarConverter::handlePseudo(const std::string& param)
{
	if (param == "-inff" || param == "-inf")
	{
		std::cout << "Char: " << "Impossible" << std::endl;
		std::cout << "Int: " << "Impossible" << std::endl;
		std::cout << "Float: " << -std::numeric_limits<float>::infinity() << f << std::endl;
		std::cout << "Double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (param == "+inff" || param == "+inf")
	{
		std::cout << "Char: " << "Impossible" << std::endl;
		std::cout << "Int: " << "Impossible" << std::endl;
		std::cout << "Float: " << std::numeric_limits<float>::infinity() << f << std::endl;
		std::cout << "Double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (param == "nan" || param == "nanf")
	{
		std::cout << "Char: " << "Impossible" << std::endl;
		std::cout << "Int: " << "Impossible" << std::endl;
		std::cout << "Float: " << std::numeric_limits<float>::quiet_NaN() << std::endl;
		std::cout << "Double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
}

void	Scalvoid	ScalarConverter::handleInt(const std::string& param)
{
	long	longValue = std::atol(param.c_str());

	//what if they give value bigger than long?
	if (longValue > INT_MAX || longValue < INT_MIN)
	{
		std::cout << "Overflow" << std::endl;
		return;
	}
	//char conversion
	std::cout << "char: ";
	if (longValue < 0 || longValue > 127)
		std::cout << "impossible" << std::endl;
	else if (longValue < 32 || longValue == 127)//space and 
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(longValue) << "'" << std::endl;
	//int conversion
	std::cout << "int: " << static_cast<int>(longValue) << std::endl;
	//float conversion
	std::cout << "float: " << static_cast<float>(longValue) << "f" << std::endl;
	//double conversion
	std::cout << "double: " << static_cast<double>(longValue) << std::endl;
}

void	ScalarConverter::handleChar(const std::string& param)
{
	char	c = param[1];

	//char conversion
	std::cout << "char: " << param << std::endl;
	//int conversion
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	//float conversion
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	//double conversion
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::handleFloat(const std::string& param)
{
	std::string	strNoF = param;
	strNoF = substr(0, strNoF.length() - 1);
	float	f = std::atof(strNoF.c_str());
	//how to check if more than max_float or min_float?
	
	if (isinf(f))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	//char conversion
	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (f < 32 || f == 127)//space and 
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	//int conversion
	std::cout << "int: "
	if (f > INT_MAX || f < INT_MIN)
	{
		std::cout << "Overflow" << std::endl;
		return;
	}
	else
		std::cout << f << std::endl;
	//float conversion
	std::cout << "float: " << f << "f" << std::endl;
	//double conversion
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::handleDouble(const std::string& param)
{
	
}
