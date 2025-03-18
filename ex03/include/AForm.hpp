/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:52:42 by hrischma          #+#    #+#             */
/*   Updated: 2025/03/18 17:20:51 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		virtual ~AForm();

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
		
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		virtual void		execute(Bureaucrat const &executor) const = 0;
				
	protected:
		AForm(const std::string name = "_default", const int sign_grade = 150, const int exec_grade = 150);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &src);
		const std::string	_name;
		const size_t		_sign_grade;
		const size_t		_exec_grade;
		bool				_signature_status;

	private:
		
};

std::ostream &operator<<(std::ostream &o, AForm &a);
std::ostream &operator<<(std::ostream &o, AForm *a);

#endif
