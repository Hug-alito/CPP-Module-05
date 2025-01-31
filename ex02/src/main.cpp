/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:58:16 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 16:28:17 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main()
{
   std::cout << "---- Our 2 bureaucrats ----" << std::endl;
   Bureaucrat *b = new Bureaucrat("Vice President", 2);
   Bureaucrat *c = new Bureaucrat("Intern", 150);

   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << b << std::endl;
   std::cout << c << std::endl;

   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "---- Test of Presidential Pardon Form ----" << std::endl;
   std::cout << std::endl;
   AForm *a = new PresidentialPardonForm("John");

   std::cout << std::endl;
   
   std::cout << a << std::endl;
   
   try
   {
      a->beSigned(*b);
      a->execute(*b);
      a->execute(*c);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
      std::cerr << "\033[031m" << c->getName() << " was not able to execute " << a->getName() << ". Err: " << e.what() << "\033[0m" << std::endl; 
   }
   delete a;

   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "---- Test of Robotomy Request Form ----" << std::endl;
   std::cout << std::endl;
   AForm *r = new RobotomyRequestForm("Nono");

   std::cout << std::endl;
   
   std::cout << r << std::endl;
   
   try
   {
      r->beSigned(*b);
      r->execute(*b);
      r->execute(*c);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
      std::cerr << "\033[031m" << c->getName() << " was not able to execute " << r->getName() << ". Err: " << e.what() << "\033[0m" << std::endl; 
   }
   delete r;

   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "---- Test of Robotomy Request Form ----" << std::endl;
   std::cout << std::endl;
   AForm *s = new ShrubberyCreationForm("Home");

   std::cout << std::endl;
   
   std::cout << s << std::endl;
   
   try
   {
      s->beSigned(*b);
      s->execute(*b);
      s->execute(*c);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
      std::cerr << "\033[031m" << c->getName() << " was not able to execute " << s->getName() << ". Err: " << e.what() << "\033[0m" << std::endl; 
   }
   delete s;
   
   delete b;
   delete c;
}
