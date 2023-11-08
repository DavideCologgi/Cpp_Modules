/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:47:56 by dcologgi          #+#    #+#             */
/*   Updated: 2023/09/11 11:02:13 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    int i;
    int j;
    
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        for (i = 1; i < argc; i++)
        {
            for (j = 0; argv[i][j]; j++)
            {
                std::cout << (char)toupper(argv[i][j]);
            }
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return (0);
}