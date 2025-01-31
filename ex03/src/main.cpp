/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:58:16 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 23:44:09 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	delete rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Alice");
	delete rrf;

	rrf = someRandomIntern.makeForm("non-existent form", "Bob");
	delete rrf;

	return 0;
}

