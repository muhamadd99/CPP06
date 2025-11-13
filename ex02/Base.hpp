/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:55:29 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 17:00:31 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base {
public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	* generate(void);
void	identify(Base* p);
void	identify(Base& p);