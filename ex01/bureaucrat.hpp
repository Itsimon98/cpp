#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"
class Form;
class Bureaucrat
{
	private :
	const std::string _name;
	int _grade;
	public :
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(Bureaucrat const &copy);
	void signForm( Form& form );


	 Bureaucrat	&operator=(Bureaucrat const &copy);

	std::string getName() const;
	int	getGrade()  const;
	void	incrementGrade();
	void	decrementGrade();

	  class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
};
std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif

