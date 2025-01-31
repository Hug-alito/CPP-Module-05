/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:26:47 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 23:48:51 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << "Intern Assignation Operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

AForm* createShrubberyForm(const std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(const std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialForm(const std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string form_name, const std::string target)
{
	std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*form_creators[])(const std::string) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (form_name == form_names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return form_creators[i](target);
		}
	}

	std::cout << "Error: Form \"" << form_name << "\" does not exist." << std::endl;
	return nullptr;
}
