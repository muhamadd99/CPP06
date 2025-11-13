/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:04:16 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 12:40:01 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(const std::string& param)
{
	eType	type = checkType(param);
	//create a string array
	//use switch
	switch(type)
	{
		case PSEUDO:
		{
			handlePseudo(param);
			break ;
		}
		case CHAR:
		{
			handleChar(param);
			break ;
		}
		case INT:
		{
			handleInt(param);
			break ;
		}
		case FLOAT:
		{
			handleFloat(param);
			break ;
		}
		case DOUBLE:
		{
			handleDouble(param);
			break ;
		}
		case INVALID:
		{
			handleInvalid();
			break ;
		}
	}
}

eType	ScalarConverter::checkType(const std::string& param)
{
	if (param.empty())
		return INVALID;
	if(isPseudo(param))
		return PSEUDO;
	if(isChar(param))
		return CHAR;
	//if no f only digit
	if(isInt(param))
		return INT;
	//if have decimal and f
	if(isFloat(param))
		return FLOAT;
	//if no decimal no f
	if(isDouble(param))
		return DOUBLE;
	return INVALID;
}

// //only number
// //check overflow
// bool	isInt(const std::string& str)
// {
// 	if (str.empty())
// 		return (false);
// 	if (str.length() == 1 && (str[0] < 48 || str[0] > 57))
// 		return (false);
// 	if (str[0] != '+' && str[0] != '-' && (str[0] < 48 || str[0] > 57))
// 		return (false);
// 	for (int i = 1; str[i]; i++)
// 		if (str[i] < 48 || str[i] > 57)
// 			return (false);
// 	return (true);
// }
