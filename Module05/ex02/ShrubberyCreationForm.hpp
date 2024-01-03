#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;

    public:
        ShrubberyCreationForm(std::string targ);
        ~ShrubberyCreationForm();

        void    execute(const Bureaucrat& executor);
};