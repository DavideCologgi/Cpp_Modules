/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:05 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 11:42:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ)
    : AForm(targ, 145, 137) {
        this->target = targ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (this->getSign() == false) {
        throw FormNotSignedException();
    }
    else if (executor.getGrade() > this->getExeGrade()) {
        throw GradeTooLowException();
    }

    std::ofstream file((this->getName() + "_shrubbery").c_str());
    file << "                      ___"                     << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--."       << std::endl;
    file << "             ,-'          __,,-- \\"           << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )"      << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /"         << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'"           << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__"        << std::endl;
    file << "     (     ,-'                  `."            << std::endl;
    file << "      `._,'     _   _             ;"           << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'"            << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\""             << std::endl;
    file << "        `--\'   \"Hb  HH  dF\""                << std::endl;
    file << "                \"Hb HH dF"                    << std::endl;
    file << "                 \"HbHHdF"                     << std::endl;
    file << "                  |HHHF"                       << std::endl;
    file << "                  |HHH|"                       << std::endl;
    file << "                  |HHH|"                       << std::endl;
    file << "                  |HHH|"                       << std::endl;
    file << "                  |HHH|"                       << std::endl;
    file << "                  dHHHb"                       << std::endl;
    file << "                .dFd|bHb."                     << std::endl;
    file << "              .dHFdH|HbTHb."                   << std::endl;
    file << "           .dHFdHHFdHH|HHhoHHb."               << std::endl;
    file << "##########################################"    << std::endl;
    file.close();

    std::cout << "Some shrubbery created!" << std::endl;
}
