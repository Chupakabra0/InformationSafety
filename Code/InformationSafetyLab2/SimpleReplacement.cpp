#pragma once
#include <list>
#include <algorithm>
#include "SimpleReplacement.h"

void Lab1::SimpleReplacement::shuffleCypher()
{
	std::random_shuffle(cypher_.begin(), cypher_.end());
}

std::string Lab1::SimpleReplacement::encrypt(const std::string& word)
{
	std::string result;

	for (auto it = word.begin(); it != word.end(); ++it)
	{
		auto place = static_cast<int>(alphabet_.find(*it));
		result.push_back(cypher_.at(place));
	}

	return result;
}

std::string Lab1::SimpleReplacement::decrypt(const std::string& word)
{
	std::string result;

	for (auto it = word.begin(); it != word.end(); ++it)
	{
		auto place = static_cast<int>(cypher_.find(*it));
		result.push_back(alphabet_.at(place));
	}

	return result;
}

const std::string& Lab1::SimpleReplacement::getAlphabet() const
{
	return alphabet_;
}

const std::string& Lab1::SimpleReplacement::getCypher() const
{
	return cypher_;
}