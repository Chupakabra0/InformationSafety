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
		std::string encrypt(const std::string& word);
		std::string decrypt(const std::string& word);

		const std::string& getAlphabet() const;
		const std::string& getCypher() const;

		~SimpleReplacement() {}
	private:

		const std::string alphabet_;
		std::string cypher_;
	};
}

