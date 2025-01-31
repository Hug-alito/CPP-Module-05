/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:27:40 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/27 18:41:46 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    std::cout << "Bureaucrat Constructor called for " << this->getName() 
              << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
    std::cout << "Copy constructor called for Bureaucrat: " << cpy.getName() 
              << " with grade " << cpy.getGrade() << std::endl;
    *this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    std::cout << "Assignment operator called for Bureaucrat: " << src.getName() 
              << " with grade " << src.getGrade() << std::endl;
    
    if (this != &src)
        this->_grade = src.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called for Bureaucrat: " << this->getName() 
              << " with grade " << this->getGrade() << std::endl;
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Trying to increment" << std::endl;
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    std::cout << "Grade incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Trying to decrement" << std::endl;
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
    std::cout << "Grade decremented to " << _grade << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

size_t Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &a)
{
    o << a.getName() << ", bureaucrat grade " << a.getGrade();
    return o;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *a)
{
	if (a)
    	o << a->getName() << ", bureaucrat grade " << a->getGrade();
    else
		o << "Null pointer";
	return o;
}