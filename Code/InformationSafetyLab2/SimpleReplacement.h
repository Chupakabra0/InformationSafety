#pragma once
#include <iostream>

namespace Lab1
{
	class SimpleReplacement
	{
	public:
		SimpleReplacement(const std::string alphabet, const std::string cypher) :
			alphabet_(alphabet), cypher_(cypher){}

		void shuffleCypher();
		std::string crypt(std::string word);
		std::string decrypt(std::string word);

		std::string getAlphabet();
		std::string getCypher();

		~SimpleReplacement() {}
	private:

		const std::string alphabet_ = nullptr;
		std::string cypher_ = nullptr;
	};
}

