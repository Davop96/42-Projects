/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:19:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 19:19:35 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int replace(char **argv, std::string str)
{
	std::string     old_word = argv[2];
	std::string     new_word = argv[3];
	std::ofstream	outfile;
	size_t          pos = 0;

	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for(size_t i = 0; i < str.length(); i++)
	{
		pos = str.find(old_word, i);
		if (pos != std::string::npos && pos == i)
		{
			outfile << new_word;
			i += old_word.length() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int main(int argc, char **argv)
{
    char            c;
	std::string		str;
    std::ifstream	infile;

    if (argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		std::cout << "Error: old_word is empty." << std::endl;
		return (1);
	}
    infile.open(argv[1]);
    if (!infile.is_open())
    {
        std::cout << "Error: could not open " << argv[1] << ": Maybe no such file or directory or does not have the permissions." << std::endl;
        return (1);
    }
    while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
    infile.close();
    return (replace(argv, str));
}