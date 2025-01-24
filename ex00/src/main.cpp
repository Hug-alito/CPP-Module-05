/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:58:16 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/24 18:33:30 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	std::cout << "--- NEW TEST --- " << std::endl;

    try
    {
        Bureaucrat bob("Bob", 151);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
	std::cout << std::endl;	
	std::cout << "--- NEW TEST --- " << std::endl;

    Bureaucrat* alice = NULL;

    try
    {
        alice = new Bureaucrat("Alice", 1);
        alice->incrementGrade();
        delete alice;
        alice = NULL;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        if (alice)
        {
            delete alice;
            alice = NULL;
        }
    }
	
	std::cout << std::endl;
	std::cout << "--- NEW TEST --- " << std::endl;

    try
    {
        Bureaucrat charlie("Charlie", 150);
        charlie.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "On the stack, the prog waits for the end of try block (automatically delete the instance) then goes on the exception caught" << std::endl;
	std::cout << "On the heap, same but deconstructor called on both cases (if ok and if exception)" << std::endl;
	
    return 0;
}
