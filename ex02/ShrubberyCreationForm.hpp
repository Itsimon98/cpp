#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm&);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

		void	execute(const Bureaucrat&);
};

#endif

