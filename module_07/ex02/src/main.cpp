/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:07:54 by vbachele          #+#    #+#             */
/*   Updated: 2022/05/19 18:25:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Array.tpp"
// //Here the main objective is to read every member of the array

// /************* TEST 1 DEFAULT CONSTRUCTOR ***************/
// void	testByDefault(void)
// {
// 	std::cout << "----TEST WITH DEFAULT CONSTRUCTOR----" << std::endl;
// 	Array <int> test;
// 	std::cout << test.size() << std::endl;
// 	for (unsigned int i = 0; i < test.size(); i++)
// 		std::cout << test[i] << std::endl;
// 	std::cout << std::endl; 
// }

// /************* TEST 2 WITH PARAM ***************/
// /************* TEST 3 BY COPY ***************/
// void	testParamCopy(void)
// {
// 	std::cout << "----TEST WITH PARAMETER----" << std::endl;
// 	Array <int> test_param(3);
// 	std::cout << test_param.size() << std::endl;
// 	for (unsigned int i = 0; i < test_param.size(); i++) // here I display nonsense value because i didn't attribute some values
// 		std::cout << "Test with param: " << test_param[i] << std::endl;
// 	for (unsigned int i = 0; i < test_param.size(); i++) // here I give values
// 		test_param[i] = i + 1;
// 	for (unsigned int i = 0; i < test_param.size(); i++) // here I display the new values
// 		std::cout << "Test with param: " << test_param[i] << std::endl;
// 	std::cout << std::endl;
	
// 	std::cout << "----TEST BY COPY----" << std::endl;
// 	Array <int> test_copy(test_param);
// 	std::cout << test_copy.size() << std::endl;
// 	for (unsigned int i = 0; i < test_copy.size(); i++) // here I display the new values
// 		std::cout << "Test by copy: " << test_copy[i] << std::endl;
// 	std::cout << std::endl;
// }

// /************* TEST 4 ERRORS ***************/
// void	testErrors(void)
// {
// 	Array <int> test_errors(3);
	
// 	std::cout << std::endl;
// 	std::cout << "----TEST WITH ERRORS----" << std::endl;
// 	try {
// 		test_errors[-1];
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 		std::cerr << "Index negative impossible" << std::endl;
// 		std::cout << std::endl;
// 	}
// 	try {
// 		test_errors[4];
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 		std::cerr << "Index too far" << std::endl;
// 	}
// }

// int main (void)
// {
// 	testByDefault();
// 	testParamCopy();
// 	testErrors();
// 	return (0);
// }

#include <iostream>
#include <Array.tpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}