#pragma once
#include <iostream>

using uint = unsigned int;

namespace Lab1
{
	class Vigenere
	{
	public:
		Vigenere(const std::string& alphabet): 
			alphabet_(alphabet){}

		std::string encrypt(const std::string& word, const std::string& key);
		std::string decrypt(const std::string& word, const std::string& key);

		const std::string& getAlphabet() const;

	private:
		inline uint modSum(uint first, uint second, uint N);
		inline uint modDif(int first, int second, uint N);

		const std::string alphabet_;
	};
}
