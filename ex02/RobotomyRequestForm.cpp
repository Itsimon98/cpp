#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm::AForm("Unnamed Robotomy Request Form", 72, 45, "unspecified")

{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm::AForm("Unnamed Robotomy Request Form", 72, 45, target)

{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
	AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute(), src.getTarget())
{
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	setIsSigned(src.getIsSigned());
	setTarget(src.getTarget());
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& bur)
{
	std::cout << getName() << " was executed by " << bur.getName() << "." << std::endl;
	std::cout << "BrrrrBrrrrBrrrrrr" << std::endl;
	srand(time(NULL));
	std::cout << getTarget() << (rand() % 2 ? " was successfully robotomized!" : "'s robotomy failed!") << std::endl;
}
