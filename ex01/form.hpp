#ifndef FORM_HPP
#define FORM_HPP
#include "bureaucrat.hpp"

class Form{
	private :
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;





	public :
	Form();
	~Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	const std::string getName();
	const bool isSigned();
	const int gradeToSign();
	const int gradeToExecute();
	 class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};
#endif
