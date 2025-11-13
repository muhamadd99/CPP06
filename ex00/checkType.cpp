/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:51:17 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 17:47:46 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::isPseudo(const std::string& str)
{
	return (str == "-inff"|| str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan");
}

//
bool	ScalarConverter::isFloat(const std::string& str)
{
	int		dotFlag = 0;
	bool	hasDigit = false;
	size_t	i = 0;
	size_t	lastChar = str.length() - 1;

	if (str[lastChar] != 'F' && str[lastChar] != 'f')
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for(; i < lastChar; i++)
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
bool	ScalarConverter::isInt(const std::string& str)
{
	size_t	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return false;
	for (; i < str.length(); i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

//char literal only 3 char
//return true if displayable char
bool	ScalarConverter::isChar(const std::string& str)
{
	if (str.length() == 1 && std::isprint(str[0]))
		return (true);
	if (str.length() == 3 && str[0] == '\'' 
		&& str[2] == '\'' && std::isprint(str[0]))
		return (true);
	return (false);
}

//handle + -
//
bool	ScalarConverter::isDouble(const std::string &str)
{
	int		dotFlag = 0;
	size_t	i = 0;
	bool	hasDigit = false;

	if (str[i] == '-' || str[i] == '+') 
		i++;
	// if (str[0] == '.')
	// 	i++;
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