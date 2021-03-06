/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:32 by vincent           #+#    #+#             */
/*   Updated: 2022/05/10 09:24:07 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

void	display (int i)
{
	std::cout << i << std::endl;
}


int main (void)
{
	//vect is an array fixed size
	std::vector <int> vect;
	
	/************* VECTOR ***************/
	srand(time(NULL));
	vect.push_back(rand());
	vect.push_back(rand());
	vect.push_back(rand());
	vect.push_back(rand());
	vect.push_back(rand());
	vect.push_back(10);
	vect.push_back(rand());
	vect.push_back(rand());
	vect.push_back(10);
	std::for_each(vect.begin(), vect.end(), display);
	std::cout << std::endl;
	/**** VECTOR NOT FOUND ****/
	
	easyfind(vect, 10);
	easyfind(vect, -45);
	easyfind(vect, 150);
	easyfind(vect, 0);
	return (0);
}