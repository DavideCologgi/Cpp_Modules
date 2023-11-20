/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/20 12:32:40 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

size_t  findString(std::string line, std::string s1, size_t pos) {
	size_t  found;
	
	found = line.find(s1, pos);
	if (found != std::string::npos)
		return (found);
	else
		return (std::string::npos);
}

std::string replaceString(std::string line, size_t pos, std::string s2) {
	std::string result;
	
	result = line.substr(0, pos) + s2 + line.substr(pos + s2.length() - 1);
	return (result);
}

FileReplace::FileReplace(std::string fileName, std::string s1, std::string s2):
	p_fileName(fileName), p_s1(s1), p_s2(s2) {}

FileReplace::~FileReplace() {}

void	FileReplace::replaceAndWriteToFile() {
	std::ifstream inputFile(p_fileName.c_str());
	
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file " << p_fileName << std::endl;
		return;
	}
	
	std::ofstream outputFile((p_fileName + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create or open output file "
			<< p_fileName << ".replace" << std::endl;
		inputFile.close();
		return;
	}

	std::string line;
	bool	fileChanged = false;
	
	while (getline(inputFile, line)) {
		size_t  pos = 0;

		while ((pos = findString(line, p_s1, pos)) != std::string::npos) {
			line = replaceString(line, pos, p_s2);
			pos += p_s2.length();
			fileChanged = true;
		}
		outputFile << line << '\n';
	}
	if (!fileChanged) {
		std::cout << "No replacement made. String '" << p_s1 << "' not found in file."
			<< std::endl << "Created a copy of '" << p_fileName << "'." << std::endl;
	} else {
		std::cout << "Replacement successfull. Changes have been saved in "
			<< p_fileName << ".replace" << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
