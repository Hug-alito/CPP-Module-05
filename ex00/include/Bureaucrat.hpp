/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:27:33 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/24 18:25:58 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name = "_default", int grade = 150);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		void				incrementGrade(void);
		void				decrementGrade(void);
		const std::string	getName(void) const;
		size_t				getGrade(void) const;

		class GradeTooLowException
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException
		{			
			public:
				virtual const char *what() const throw();
		};
		
	private:
		std::string _name;
		size_t		_grade;
		void		setGrade(int grade);

};

std::ostream &operator<<(std::ostream &o, Bureaucrat *a);

#endif