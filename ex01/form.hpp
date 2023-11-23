#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

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
	 std::string getName() const;
	 bool getIsSigned() const;
	 int getGradeToSign()const;
	 int getGradeToExecute()const;
	 class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
	void beSigned(const Bureaucrat &bureaucrat);

};
#endif
