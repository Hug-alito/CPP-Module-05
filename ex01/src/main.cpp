/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:58:16 by hrischma          #+#    #+#             */
/*   Updated: 2025/01/31 11:44:18 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
    std::cout << "--- Create ---" << std::endl;
    Bureaucrat *a = new Bureaucrat("A Intern", 140);
    Bureaucrat *b = new Bureaucrat("B CEO", 1);
    Bureaucrat *x = new Bureaucrat();
    Form *f = new Form();
    Form *z = new Form("Contract", 140, 140);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test creating a bad form" << std::endl;
    try
    {
        Form *bad = new Form("bad", 160, 120);
        delete bad;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Form *bad = new Form("bad", 120, 160);
        delete bad;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;

    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Form *bad = new Form("bad", 0, 120);
        delete bad;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Form *bad = new Form("bad", 120, 0);
        delete bad;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Test with form F default ('default', 150, 150)" << std::endl;
    try
    {
        f->beSigned(*a);
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << a->getName() << " was not able to sign " << f->getName() 
                << ": " << e.what() << std::endl;   
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << a->getName() << " was not able to sign " << f->getName() 
                << ": " << e.what() << std::endl;       
    }

    try
    {
        f->beSigned(*b);
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << b->getName() << " was not able to sign " << f->getName() 
                << ": " << e.what() << std::endl;   
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << b->getName() << " was not able to sign " << f->getName() 
                << ": " << e.what() << std::endl;       
    }

    try
    {
        f->beSigned(*x);
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << x->getName() << " was not able to sign " << f->getName() 
                << ": " << e.what() << std::endl;   
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << x->getName() << " was not able to sign " << f->getName() 
                << ": " << e.what() << std::endl;       
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Test with form Z ('Contract', 140, 140)" << std::endl;
    try
    {
        z->beSigned(*a);
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << a->getName() << " was not able to sign " << z->getName() 
                << ": " << e.what() << std::endl;   
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cerr << a->getName() << " was not able to sign " << z->getName() 
                << ": " << e.what() << std::endl;       
    }

    try
    {
        z->beSigned(*b);
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << b->getName() << " was not able to sign " << z->getName() 
                << ": " << e.what() << std::endl;   
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cerr << b->getName() << " was not able to sign " << z->getName() 
                << ": " << e.what() << std::endl;       
    }

    try
    {
        z->beSigned(*x);
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << x->getName() << " was not able to sign " << z->getName() 
                << ": " << e.what() << std::endl;   
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cerr << x->getName() << " was not able to sign " << z->getName() 
                << ": " << e.what() << std::endl;       
    }

    delete a;
    delete b;
    delete x;
    delete f;
    delete z;
    
    return 0;
}
