#include "form.hpp"
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
	throw Form::GradeTooHighException();
	else if(gradeToSign > 150  || gradeToExecute > 150)
	throw Form::GradeTooLowException();
}
Form::~Form()
{

}
Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{

}

Form &Form::operator=(const Form &copy)
{
	if(this == &copy)
	return(*this);
	_isSigned = copy._isSigned;
	return(*this);
}
