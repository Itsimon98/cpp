#include "Form.hpp"
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
	throw Form::GradeTooHighException();
	else if(gradeToSign > 150  || gradeToExecute > 150)
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
