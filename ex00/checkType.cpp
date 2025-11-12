/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:51:17 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/12 13:20:47 by mbani-ya         ###   ########.fr       */
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
bool	ScalarConverter::isInt(const std::string& str)
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
bool	ScalarConverter::isChar(const std::string& str)
{
	return (str.length() == 3 && str[0] == '\'' 
		&& str[2] == '\'' && str[1] >= 32 && str[1] <= 126);
}

//handle + -
//
bool	ScalarConverter::isDouble(const std::string &str)
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