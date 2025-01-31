/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:10:39 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 16:18:51 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << " - PresidentialPardonForm Default Constructor called (it should not happen)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << " - PresidentialPardonForm Constructor called for the target " << this->_target << std::endl;
	std::cout << "\033[32m - SUCCESS: PresidentialPardonForm " << _name << " created with sign grade " << _sign_grade << " and execution grade " << _exec_grade << " for the target " << _target << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm("PresidentialPardonForm", 25, 5), _target(cpy._target)
{
	std::cout << " - PresidentialPardonForm Copy Constructor called to copy " << cpy._name << " into " << this->_name << std::endl;
	*this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << " - PresidentialPardonForm Assignation Operator called" << std::endl;
	if (&src == this)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << " - PresidentialPardonForm Destructor Called for " << this->_name << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_exec_grade)
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->_signature_status)
		throw (AForm::NotSignedException());
	else
		std::cout << "\033[32m" << this->_target << " has been pardoned by Zaphod Beeblebrox. Executed by " << executor.getName() << ".\033[0m" << std::endl;
}
