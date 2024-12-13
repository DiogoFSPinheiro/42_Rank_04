/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 11:27:03 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include <fstream>

void	replaceStringsInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (s1.empty() || s2.empty()
		|| s1.find_first_not_of(" ") == std::string::npos
		|| s2.find_first_not_of(" ") == std::string::npos )
	{
		std::cout << "Error: Strings to find and replace cannot be empty." << std::endl;
		return ;
	}
	
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
	{
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return;
    }

	std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
	{
        std::cerr << "Error: Could not open output file: " << filename << std::endl;
		inputFile.close();
        return;
    }
	std::string line;

	while(std::getline(inputFile, line))
	{
		size_t pos = 0;
		pos = line.find(s1, pos);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.size());
			line.insert(pos, s2);
			pos += s2.size();
			pos = line.find(s1, pos);
		}
		outputFile << line;
		if (inputFile.peek() != EOF)
			outputFile << '\n';
	}
	outputFile.close();
	inputFile.close();
    std::cout << "Processing complete: " << filename + ".replace" << std::endl;
}

int main(int c, char *v[]) {

	if (c != 4)
	{
		std::cout << "It takes 4 arguments for the program to work properly" << std::endl;
		return (0);
	}
	std::string filename = v[1];
	std::string s1 = v[2];
	std::string s2 = v[3];

	replaceStringsInFile(filename, s1, s2);
	
	return 0;
}
