#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <cstdlib>

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm&);

		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		void	execute(const Bureaucrat&);
};

#endif
