/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:04:12 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/12 22:19:37 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <limits>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum eType {
	INVALID,
	PSEUDO,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
public:
	static eType	checkType(const std::string& param);
	static void 	convert(const std::string& Param);
	static void		handleInvalid();
	static void		handlePseudo(const std::string& param);
	static void		handleInt(const std::string& param);
	static void		handleChar(const std::string& param);
	static void		handleFloat(const std::string& param);
	static void		handleDouble(const std::string& param);
	static bool		isPseudo(const std::string& str);
	static bool		isFloat(const std::string& str);
	static bool		isInt(const std::string& str);
	static bool		isChar(const std::string& str);
	static bool		isDouble(const std::string &str);
};