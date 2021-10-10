#pragma once
#include <Windows.h>
#include <algorithm>

#include "SimpleReplacement.h"
#include "Vigenere.h"


int main(const int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto alphabet = std::string{ "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " };
	std::string cypher = alphabet;
	auto word = std::string{ "Я ЛЮБЛЮ КУШАТЬ" };
	auto key = std::string{ "Я И ЕДА" };

	if (argc == 2)
	{
		word = static_cast<std::string>(argv[1]);
		std::replace(word.begin(), word.end(), '_', ' ');
	}

	try
	{
		//auto simple = Lab1::SimpleReplacement(alphabet, cypher);

		//simple.shuffleCypher();

		//std::cout << simple.getAlphabet() << "\n";
		//std::cout << simple.getCypher() << "\n";

		//auto result = simple.encrypt(word);

		//std::cout << result << "\n";

		//auto result2 = simple.decrypt(result);

		//std::cout << result2 << "\n";

		auto vigenere = Lab1::Vigenere::Vigenere(alphabet);

		std::cout << vigenere.getAlphabet() << "\n";

		auto result = vigenere.encrypt(word, key);

		std::cout << result << "\n";

		auto result2 = vigenere.decrypt(result, key);

		std::cout << result2 << "\n";
	}
	catch (const std::exception& exception)
	{
		std::cout << "Error: " << exception.what() << "\n";
	}



	system("pause");
}
