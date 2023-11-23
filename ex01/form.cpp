#include "Form.hpp"
Form::Form(const std::string& name, int gradeToSign) : _name(name), _gradeToSign(gradeToSign),_gradeToExecute(12)
{
	if(gradeToSign < 1 || _gradeToExecute < 1)
	throw Form::GradeTooHighException();
	else if(gradeToSign > 150  || _gradeToExecute > 150)
	throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{

}
Form::~Form()
{

}
Form &Form::operator=(const Form &copy)
{
	if(this == &copy)
	return(*this);
	_isSigned = copy._isSigned;
	return(*this);
}

std::string Form::getName() const
{
	return(_name);
}

bool Form::getIsSigned() const
{
	return(_isSigned);
}
int Form::getGradeToSign() const
{
	return(_gradeToSign);
}
 int Form::getGradeToExecute()const
{
	return(_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    else
        _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
std::ostream&   operator<<( std::ostream& o, const Form& rhs ) {
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
return (o);
}
