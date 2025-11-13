/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:47:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 12:24:20 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	Data	data;
	data.notEmpty = true;
	
	Data*	ptr = &data;

	std::cout << "=== HEXA TO UNSIGNED INT ===" << std::endl;
	uintptr_t	raw_ptr = Serializer::serialize(ptr);
	std::cout << raw_ptr << std::endl;
	
	std::cout << "\n=== UNSIGNED INT TO HEXA ===" << std::endl;
	Data*		ptr2 = Serializer::deserialize(raw_ptr);
	std::cout << ptr2 << std::endl;
	
	std::cout << "\n=== COMPARISON OF NEW AND ORI ===" <<	std::endl;
	std::cout << "Old: " << ptr << std::endl;
	std::cout << "New: " << ptr2 << std::endl;
}
