#include "Form.hpp"

int main()
{
    try
    {
        Form form("Form", 1, 1);
        Form form2("Form2", 150, 150);

        std::cout << form.getName() << std::endl;
        std::cout << form.getGradeToSign() << std::endl;
        std::cout << form.getGradeToExecute() << std::endl;
        std::cout << form.getIsSigned() << std::endl;
        Bureaucrat bureaucrat("Bureaucrat", 1);
        form.beSigned(bureaucrat);
        std::cout << form.getIsSigned() << std::endl;
        std::cout << std::endl << "--------------" << std::endl << std::endl;
        std::cout << form2.getName() << std::endl;
        std::cout << form2.getGradeToSign() << std::endl;
        std::cout << form2.getGradeToExecute() << std::endl;
        std::cout << form2.getIsSigned() << std::endl;
        Bureaucrat bureaucrat2("Bureaucrat2", 150);
        form2.beSigned(bureaucrat2);
        std::cout << form2.getIsSigned() << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form form("Form3", 50, 50);
        Bureaucrat bureaucrat("Bureaucrat3", 10);
        Bureaucrat bureaucrat2("Bureaucrat4", 70);

        std::cout << std::endl << "--------------" << std::endl << std::endl;
        std::cout << form.getIsSigned() << std::endl;
        form.beSigned(bureaucrat);
        std::cout << form.getIsSigned() << std::endl;
        form.beSigned(bureaucrat2);
        std::cout << form.getIsSigned() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }





    return (0);
}
