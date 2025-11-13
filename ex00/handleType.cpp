/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:52:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 21:16:17 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

void	ScalarConverter::handleInvalid()
{
	std::cout << "This is not a literal" << std::endl;
}

void	ScalarConverter::handlePseudo(const std::string& param)
{
	if (param == "-inff" || param == "-inf")
	{
		std::cout << "Char: " << "Impossible" << std::endl;
		std::cout << "Int: " << "Impossible" << std::endl;
		std::cout << "Float: " << NINF_FLOAT << "f" << std::endl;
		std::cout << "Double: " << NINF_DOUBLE << std::endl;
	}
	else if (param == "+inff" || param == "+inf")
	{
		std::cout << "Char: " << "Impossible" << std::endl;
		std::cout << "Int: " << "Impossible" << std::endl;
		std::cout << "Float: " << PINF_FLOAT << "f" << std::endl;
		std::cout << "Double: " << PINF_DOUBLE << std::endl;
	}
	else if (param == "nan" || param == "nanf")
	{
		std::cout << "Char: " << "Impossible" << std::endl;
		std::cout << "Int: " << "Impossible" << std::endl;
		std::cout << "Float: " << NAN_FLOAT << "f" << std::endl;
		std::cout << "Double: " << NAN_DOUBLE << std::endl;
	}
}

void	ScalarConverter::handleInt(const std::string& param)
{
	long	longValue = std::atol(param.c_str());

	if (longValue > MAX_INT || longValue < MIN_INT)
	{
		std::cout << "impossible" << std::endl;
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
	std::cout << "float: " << static_cast<float>(longValue) << ".0f" << std::endl;
	//double conversion
	std::cout << "double: " << static_cast<double>(longValue) << ".0" << std::endl;
}

void	ScalarConverter::handleChar(const std::string& param)
{
	char	c = (param.length() == 3) ? param[1] : param[0];
	//char conversion
	std::cout << "char: " << param << std::endl;
	//int conversion
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	//float conversion
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	//double conversion
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::handleFloat(const std::string& param)
{
	//remove F
	std::string	strNoF = param;
	strNoF = strNoF.substr(0, strNoF.length() - 1);
	float	f = std::atof(strNoF.c_str());
	// long	l = std::atol(strNoF.c_str());
	//add .0
	bool NoDecimal = (f == static_cast<long long>(f));
	
	//check if more than max_float or min_float
	if (std::isinf(f))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << f << std::endl;
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
	std::cout << "int: ";
	if (f >= MAX_INT || f < MIN_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	//float conversion
	std::cout << "float: " << f << (NoDecimal ? ".0f" : "f") << std::endl;
	//double conversion
	std::cout << "double: " << static_cast<double>(f) << (NoDecimal ? ".0" : "") << std::endl;
}

void	ScalarConverter::handleDouble(const std::string& param)
{
	double	d = std::atof(param.c_str());
	//add .0
	bool NoDecimal = (d == static_cast<long long>(d));
	
	if (std::isinf(d)) 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: " << ((d > 0) ? "+inf" : "-inf") << std::endl;
        return ;
    }
	//char conversion
	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (d < 32 || d == 127)//space and 
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	//int conversion
	std::cout << "int: ";
	if (d > MAX_INT || d < MIN_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	//float conversion
	std::cout << "float: ";
	if (d > MAX_FLOAT || d < MIN_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (NoDecimal ? ".0f" : "f") << std::endl;
	//double conversion
	std::cout << "double: " << d << (NoDecimal ? ".0" : "") << std::endl;
}
