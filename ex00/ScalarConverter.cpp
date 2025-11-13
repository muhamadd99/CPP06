/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:04:16 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 21:22:20 by mbani-ya         ###   ########.fr       */
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
	if(isInt(param))
		return INT;
	if(isFloat(param))
		return FLOAT;
	if(isDouble(param))
		return DOUBLE;
	return INVALID;
}
