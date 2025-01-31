/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:52:26 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 10:45:21 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string name = "_default", const int sign_grade = 150, const int exec_grade = 150);
		Form(const Form &cpy);
		Form &operator=(const Form &src);
		~Form();

		const std::string	getName() const;
		size_t				getSignGrade() const;
		size_t				getExecGrade() const;
		bool				getSignatureStatus() const;
		void				beSigned(Bureaucrat &bureaucrat);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		const std::string	_name;
		const size_t		_sign_grade;
		const size_t		_exec_grade;
		bool				_signature_status;
		
};

std::ostream &operator<<(std::ostream &o, Form &a);
std::ostream &operator<<(std::ostream &o, Form *a);

#endif