/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:52:23 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 11:41:49 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(const std::string name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signature_status(false)
{
	std::cout << "Form constructor called with name: " << name << ", sign grade: " << sign_grade << ", exec grade: " << exec_grade << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	_signature_status = false;
	std::cout << "Form " << _name << " created with sign grade " << _sign_grade << " and execution grade " << _exec_grade << std::endl;
}

Form::Form(const Form &cpy) : _name(cpy._name), _sign_grade(cpy._sign_grade), _exec_grade(cpy._exec_grade), _signature_status(cpy._signature_status)
{
	std::cout << "Form copy constructor called: copying " << cpy._name << " into " << this->_name << std::endl;
	*this = cpy;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form assignment operator called: assigning " << src._name << " to " << this->_name << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " is being destroyed" << std::endl;
}

const std::string Form::getName() const
{
	return _name;
}

size_t Form::getSignGrade() const
{
	return _sign_grade;
}

size_t Form::getExecGrade() const
{
	return _exec_grade;
}

bool Form::getSignatureStatus() const
{
	return _signature_status;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	_signature_status = true;
	std::cout << this->_name << " was signed by " << bureaucrat.getName() << "!" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, Form &a)
{
	o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getSignatureStatus() <<
	std::endl;
	return (o);
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	if (a)
	{
		o << "Form " << a->getName() <<
		":\n\tsign-grade:\t" << a->getSignGrade() <<
		"\n\texec-grade:\t" << a->getExecGrade() <<
		"\n\tis signed:\t" << a->getSignatureStatus() <<
		std::endl;
	}
    else
		o << "Null pointer";
	return o;
}