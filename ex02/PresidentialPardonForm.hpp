#ifndef PRESIDENT_HPP
#define PRESIDENT_HPP

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);

		PresidentialPardonForm& operator=(const PresidentialPardonForm&);

		void	execute(const Bureaucrat&);
};

#endif
