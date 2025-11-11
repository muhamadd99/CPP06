/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:04:16 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/11 18:52:07 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void convert(const std::string& param)
{
	etype	type = checkType(param);
	//create a string array
	//use switch
	switch(type)
	{
		case INVALID:
			handleInvalid();
			break ;
		case PSEUDO:
			handlePseudo();
			break ;
		case CHAR:
			handleChar();
			break ;
		case INT:
			handleInt();
			break ;
		case FLOAT:
			handleFloat();
			break ;
		case DOUBLE:
			handleDouble();
			break ;
	}
}

etype	checkType(const std::string& param)
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
}

bool	isPseudo(const std::string& str)
{
	return (str == "-inff"|| str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan");
}

//
bool	isFloat(const std::string& str)
{
	int		dotFlag = 0;
	int		i = 0;
	bool	hasDigit = false;

	if (str.back() != 'F' && str.back() != 'f')
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for(; i < (str.length() - 1); i++)
	{
		if (str[i] == '.')
			dotFlag++;
		else if (!(isdigit(str[i])) && str[i] != '.')
			return false;
		else if (isdigit(str[i]))
			hasDigit = true;
	}
	if (dotFlag == 1 && hasDigit == true)
		return true;
	return false;
}

//only number
//check overflow
//why dont just use int
bool	isInt(const std::string& str)
{
	size_t	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return false;
	for (size_t k = i; k < str.length(); k++)
		if (!isdigit(str[k]))
			return false;
	return true;
}

//char literal only 3 char
//return true if displayable char
bool	isChar(const std::string& str)
{
	return (str.length() == 3 && str[0] == '\'' 
		&& str[2] == '\'' && str[1] >= 32 && str[1] <= 126);
}

//handle + -
//
bool	isDouble(const std::string &str)
{
	int		dotFlag = 0;
	int		i = 0;
	bool	hasDigit = false;

	if (str[0] == '.')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for(; i < str.length(); i++)
	{
		if (str[i] == '.')
			dotFlag++;
		if (!(isdigit(str[i])) && str[i] != '.')
			return false;
		if (isdigit(str[i]))
			hasDigit = true;
	}
	if (dotFlag == 1 && hasDigit == true)
		return true;
	return false;
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