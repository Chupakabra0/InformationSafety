#include <list>
#include <algorithm>
#include "SimpleReplacement.h"

void Lab1::SimpleReplacement::shuffleCypher()
{
	std::random_shuffle(cypher_.begin(), cypher_.end());
}

std::string Lab1::SimpleReplacement::crypt(std::string word)
{
	auto result = std::string{};

	for (auto it = word.begin(); it != word.end(); ++it)
	{
		auto place = static_cast<int>(alphabet_.find(*it));
		result.push_back(cypher_.at(place));
	}

	return result;
}

std::string Lab1::SimpleReplacement::decrypt(std::string word)
{
	auto result = std::string{};

	for (auto it = word.begin(); it != word.end(); ++it)
	{
		auto place = static_cast<int>(cypher_.find(*it));
		result.push_back(alphabet_.at(place));
	}

	return result;
}

std::string Lab1::SimpleReplacement::getAlphabet()
{
	return alphabet_;
}

std::string Lab1::SimpleReplacement::getCypher()
{
	return cypher_;
}