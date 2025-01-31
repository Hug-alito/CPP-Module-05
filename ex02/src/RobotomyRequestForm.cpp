/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:33:57 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 16:21:31 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << " - RobotomyRequestForm Default Constructor called (it should not happen)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << " - RobotomyRequestForm Constructor called for the target " << this->_target << std::endl;
	std::cout << "\033[32m - SUCCESS: PresidentialPardonForm " << _name << " created with sign grade " << _sign_grade << " and execution grade " << _exec_grade << " for the target " << _target << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy) : AForm("RobotomyRequestForm", 72, 45), _target(cpy._target)
{
	std::cout << " - RobotomyRequestForm Copy Constructor called to copy " << cpy._name << " into " << this->_name << std::endl;
	*this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << " - RobotomyRequestForm Assignation Operator called" << std::endl;
	if (&src == this)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << " - RobotomyRequestForm Destructor Called for " << this->_name << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_exec_grade)
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->_signature_status)
		throw (AForm::NotSignedException());
	else
	{
		std::cout << "Brrr" << std::endl;
		int i = rand();
		if (i % 2)
			std::cout << "\033[32m" << this->_target << "robotomized successfully by " << executor.getName() << ".\033[0m" << std::endl;
		else
			std::cout << "\033[32m" << this->_target << "\033[31m not\033[32m robotomized by " << executor.getName() << ".\033[0m" << std::endl;
	}
}
