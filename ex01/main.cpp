#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

    try {
        Bureaucrat bureaucrat("ash",13);
        Form form("formN", 13);
        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
