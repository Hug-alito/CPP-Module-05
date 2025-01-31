/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:51:27 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 12:31:30 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signature_status(false)
{
	std::cout << "AForm constructor called with name: " << name << ", sign grade: " << sign_grade << ", exec grade: " << exec_grade << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	_signature_status = false;
	std::cout << "AForm " << _name << " created with sign grade " << _sign_grade << " and execution grade " << _exec_grade << std::endl;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _sign_grade(cpy._sign_grade), _exec_grade(cpy._exec_grade), _signature_status(cpy._signature_status)
{
	std::cout << "AForm copy constructor called: copying " << cpy._name << " into " << this->_name << std::endl;
	*this = cpy;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm assignment operator called: assigning " << src._name << " to " << this->_name << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " is being destroyed" << std::endl;
}

const std::string AForm::getName() const
{
	return _name;
}

size_t AForm::getSignGrade() const
{
	return _sign_grade;
}

size_t AForm::getExecGrade() const
{
	return _exec_grade;
}

bool AForm::getSignatureStatus() const
{
	return _signature_status;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _sign_grade)
		throw AForm::GradeTooLowException();
	_signature_status = true;
	std::cout << this->_name << " was signed by " << bureaucrat.getName() << "!" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &o, AForm &a)
{
	o << "AForm " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getSignatureStatus() <<
	std::endl;
	return (o);
}

std::ostream &operator<<(std::ostream &o, AForm *a)
{
	if (a)
	{
		o << "AForm " << a->getName() <<
		":\n\tsign-grade:\t" << a->getSignGrade() <<
		"\n\texec-grade:\t" << a->getExecGrade() <<
		"\n\tis signed:\t" << a->getSignatureStatus() <<
		std::endl;
	}
    else
		o << "Null pointer";
	return o;
}