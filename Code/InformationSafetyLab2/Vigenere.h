#pragma once
#include <iostream>

namespace Lab1
{
	class Vigenere
	{
	public:
		Vigenere(const std::string& alphabet): 
			alphabet_(alphabet){}

		std::string encrypt(const std::string& word, const std::string& key);
		std::string decrypt(const std::string& word, const std::string& key);

		const std::string& getAlphabet();

	private:
		inline unsigned int modSum(unsigned int first, unsigned int second, unsigned int N);
		inline unsigned int modDif(int first, int second, unsigned int N);

		const std::string alphabet_;
	};
}
