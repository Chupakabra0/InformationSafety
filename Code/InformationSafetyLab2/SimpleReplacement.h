#pragma once
#include <iostream>

namespace Lab1
{
	class SimpleReplacement
	{
	public:
		SimpleReplacement(const std::string& alphabet, std::string& cypher) :
			alphabet_(alphabet), cypher_(cypher){}

		void shuffleCypher();
		std::string crypt(const std::string& word);
		std::string decrypt(const std::string& word);

		std::string getAlphabet();
		std::string getCypher();

		~SimpleReplacement() {}
	private:

		const std::string& alphabet_;
		std::string& cypher_;
	};
}

