#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat("ash", 150);

         std::cout << bureaucrat << std::endl;

       // bureaucrat.incrementGrade();
          bureaucrat.decrementGrade();
    } catch (Bureaucrat::GradeTooLowException &e) {
         std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
