/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:19 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:33 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class FileReplace {
	private:
		std::string p_fileName;
		std::string p_s1;
		std::string p_s2;
	
	public:
		FileReplace(std::string fileName, std::string s1, std::string s2);
		~FileReplace();

		void	replaceAndWriteToFile();
};

#endif