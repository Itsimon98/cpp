#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat ;
class AForm{
	private :
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	std::string _target;





	public :
	AForm();
	virtual ~AForm();
	AForm(const std::string& name, int gradeToSign);
	AForm(const std::string &name, int gradeToSign, int gradeToExecute, std::string target);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	void        beSigned( const Bureaucrat& bureaucrat );
	 std::string getName() const;
	 bool getIsSigned() const;
	 int getGradeToSign()const;
	 int getGradeToExecute()const;
	 void	setIsSigned(bool);
	 std::string			getTarget(void) const;
	 void	setTarget (std::string);
	 void	beExecuted(const Bureaucrat&);
	 virtual void	execute(const Bureaucrat&) = 0;
	 class GradeTooHighException : public std::exception {
		 public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
	virtual const char *what() const throw();
	};
	class FormNotSignedException: public std::exception
		{
			const char* what(void) const throw();
		};


};
std::ostream&   operator<<( std::ostream& o, const AForm& rhs );
#endif
