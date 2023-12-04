#include "Form.hpp"
AForm::AForm(void): _name("Unnamed Form"), _isSigned(false),_gradeToSign(1), _gradeToExecute(1),_target("unspecified")
{
}
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec, std::string target) : _name(name), _gradeToSign(gradeToSign),_gradeToExecute(gradeToExec), _target(target)
{
	if(gradeToSign < 1 || _gradeToExecute < 1)
	throw AForm::GradeTooHighException();
	else if(gradeToSign > 150  || _gradeToExecute > 150)
	throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{

}
AForm::~AForm()
{

}
AForm &AForm::operator=(const AForm &copy)
{
	if(this == &copy)
	return(*this);
	_isSigned = copy._isSigned;
	return(*this);
}

std::string AForm::getName() const
{
	return(_name);
}

bool AForm::getIsSigned() const
{
	return(_isSigned);
}
int AForm::getGradeToSign() const
{
	return(_gradeToSign);
}
 int AForm::getGradeToExecute()const
{
	return(_gradeToExecute);
}
std::string AForm::getTarget() const
{
	return(_target);
}

void AForm::setTarget(std::string target)
{
	_target = target;
}
void AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    else
        _isSigned = true;
}

void AForm::beExecuted(const Bureaucrat& bur)
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (bur.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	execute(bur);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
}

std::ostream&   operator<<( std::ostream& o, const AForm& rhs ) {
    o << "Form name: " << rhs.getName() << std::endl
	<<" with target: " << rhs.getTarget()
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
return (o);
}
