/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:37:52 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 15:59:26 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << " - ShrubberyCreationForm Default Constructor called (it should not happen)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << " - ShrubberyCreationForm Constructor called for the target " << this->_target << std::endl;
	std::cout << "\033[32m - SUCCESS: PresidentialPardonForm " << _name << " created with sign grade " << _sign_grade << " and execution grade " << _exec_grade << " for the target " << _target << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy) : AForm("ShrubberyCreationForm", 145, 137), _target(cpy._target)
{
	std::cout << " - ShrubberyCreationForm Copy Constructor called to copy " << cpy._name << " into " << this->_name << std::endl;
	*this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << " - ShrubberyCreationForm Assignation Operator called" << std::endl;
	if (&src == this)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << " - ShrubberyCreationForm Destructor Called for " << this->_name << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_exec_grade)
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->_signature_status)
		throw (AForm::NotSignedException());
	else
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream outfile (filename.c_str());
		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
}
