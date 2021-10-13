#include <Windows.h>

#include "SimpleReplacement.h"
#include "Vigenere.h"

#include "argparser/argparse.hpp"


int main(const int argc, char* argv[])
{
	// config part
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// rus part
	//auto alphabet = std::string{ "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " };

	constexpr auto alphabetSize = 26u;
	std::string alphabet;

	alphabet.resize(alphabetSize);
	std::iota(alphabet.begin(), alphabet.end(), 'A');
	alphabet += ' ';

	std::string cypher = alphabet;

	// argparse part
	argparse::ArgumentParser program("InformationSafetyLab2.exe");

	program.add_argument("-sr", "--SimpleReplacement")
		.default_value<bool>(false)
		.implicit_value(true)
		.help("enables to use SimpleReplacement crypt");

	program.add_argument("-vig", "--Vigenere")
		.default_value<bool>(false)
		.implicit_value(true)
		.help("enables to use Vigenere crypt");

	program.add_argument("-w", "--Word")
		.default_value<std::string>("ЭТО СЛОВО")
		.help("use this param for any crypt");

	program.add_argument("-k", "--Key")
		.default_value<std::string>("ЭТО КЛЮЧ")
		.help("use this param for Vigenere crypt");

	program.add_argument("-d", "--Direction")
		.default_value<std::string>("f")
		.help("process direction [f or b]");

	program.add_argument("-a")
		.help("alphabet = english alphabet (and space)");

	try 
	{
		program.parse_args(argc, argv);
	}
	catch (const std::runtime_error& error) 
	{
		std::cout << error.what() << std::endl;
		std::cout << program;
		exit(0);
	}

	// crypt part
	auto direction = program.get<std::string>("--Direction");
	auto word = program.get<std::string>("--Word");
	try
	{
		if (static_cast<uint>(program.get<bool>("--SimpleReplacement")))
		{
			auto simple = Lab1::SimpleReplacement(alphabet, cypher);
			simple.shuffleCypher();

			if (direction._Equal(static_cast<const char*>("f")))
			{
				std::cout << simple.encrypt(word) << "\n";
			}
			else
			{
				std::cout << simple.decrypt(word) << "\n";
			}
		}
		else if (program.get<bool>("--Vigenere"))
		{
			auto key = program.get<std::string>("--Key");
			auto vigenere = Lab1::Vigenere::Vigenere(alphabet);

			if (direction._Equal(static_cast<const char*>("f")))
			{
				std::cout << vigenere.encrypt(word, key) << "\n";
			}
			else
			{
				std::cout << vigenere.decrypt(word, key) << "\n";
			}
		}
		else
		{
			std::cout << "You didnt shoose any crypt type. Plz, try again." << "\n";
		}
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
		std::cout << program;
		exit(0);
	}

	system("pause");
}
