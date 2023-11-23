#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade) : _name(_name), _grade(_grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{

}

Bureaucrat::~Bureaucrat()
{
}

 Bureaucrat& Bureaucrat::operator=(const Bureaucrat& overl)
 {
	if(this != &overl)
		_grade = getGrade();
	return (*this);
 }

std::string Bureaucrat::getName() const
{
	return(this->_name);
}
int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
	throw Bureaucrat::GradeTooLowException();
	_grade--;
}

void Bureaucrat::incrementGrade()
{
	if(_grade  - 1 < 1)
	throw Bureaucrat::GradeTooHighException();
	_grade++;
}
std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
