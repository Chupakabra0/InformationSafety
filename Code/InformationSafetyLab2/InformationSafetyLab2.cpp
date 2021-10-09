#include <Windows.h>
#include "SimpleReplacement.h"
#include <algorithm>


int main(const int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto alphabet = std::string{ "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ " };
	auto word = std::string{ "ПРИВЕТ" };

	if (argc == 2)
	{

		word = static_cast<std::string>(argv[1]);
		std::replace(word.begin(), word.end(), '_', ' ');
	}

	try
	{
		auto simple = Lab1::SimpleReplacement(alphabet, alphabet);

		simple.shuffleCypher();

		std::cout << simple.getAlphabet() << "\n";
		std::cout << simple.getCypher() << "\n";

		auto result = simple.crypt(word);

		std::cout << result << "\n";

		auto result2 = simple.decrypt(result);

		std::cout << result2 << "\n";
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << "\n";
	}



	system("pause");
}
