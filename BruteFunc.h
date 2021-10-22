#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <omp.h>
#include "md5.h"


static bool m_find = false;


bool compare(std::string str1, std::string str2) {
	if (md5(str1) == md5(str2)) return 1;
	return 0;
}

bool compare_with_hash(std::string str, std::string hash) {
	if (md5(str) == hash) return 1;
	return 0;
}

std::vector<std::string> get_passwords_from_file(std::string filename) {
	std::vector<std::string> passwords;
	std::ifstream file;
	file.open(filename);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			passwords.push_back(line);
		file.close();
	}
	return passwords;
}

void runDictBrute(std::vector<std::string> passwords, std::string hash) {
	#pragma omp parallel for
	for (int i = 0; i < passwords.size(); i++)
	{
		if (!m_find)
		{
			if (compare_with_hash(passwords[i], hash))
			{
				m_find = true;
				std::cout << "Found! It's " << passwords[i] << std::endl;
				break;
			}
		}
		else
		{
			break;
		}
	}
}