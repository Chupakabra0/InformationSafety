#pragma once
#include <vector>
#include "Vigenere.h"

const std::string& Lab1::Vigenere::getAlphabet()
{
	return alphabet_;
}

std::string Lab1::Vigenere::encrypt(const std::string& word, const std::string& key)
{
	auto result = std::string{};
	auto wordNumbers = std::vector<int>();
	auto keyNumbers = std::vector<int>();

	auto wordLength = word.length();

	for (auto it = word.begin(); it != word.end(); ++it)
	{
		auto place = static_cast<int>(alphabet_.find(*it));
		wordNumbers.push_back(place);
	}

	auto keyLength = key.length();
	if (keyLength == 0)
		throw std::invalid_argument("Key length must be bigger than 0!");

	for (size_t i = 0; i < wordLength; ++i)
	{
		auto place = static_cast<int>(alphabet_.find(key.at(i % keyLength)));
		keyNumbers.push_back(place);
	}

	for (size_t i = 0; i < wordLength; ++i)
	{
		auto letter = alphabet_.at(modSum(wordNumbers.at(i), keyNumbers.at(i), alphabet_.length()));
		result.push_back(letter);
	}

	return result;
}

std::string Lab1::Vigenere::decrypt(const std::string& word, const std::string& key)
{
	auto result = std::string{};
	auto wordNumbers = std::vector<int>();
	auto keyNumbers = std::vector<int>();

	auto wordLength = word.length();

	for (auto it = word.begin(); it != word.end(); ++it)
	{
		auto place = static_cast<int>(alphabet_.find(*it));
		wordNumbers.push_back(place);
	}

	auto keyLength = key.length();
	if (keyLength == 0)
		throw std::invalid_argument("Key length must be bigger than 0!");

	for (size_t i = 0; i < wordLength; ++i)
	{
		auto place = static_cast<int>(alphabet_.find(key.at(i % keyLength)));
		keyNumbers.push_back(place);
	}

	for (size_t i = 0; i < wordLength; ++i)
	{
		auto letter = alphabet_.at(modDif(wordNumbers.at(i), keyNumbers.at(i), alphabet_.length()));
		result.push_back(letter);
	}

	return result;
}

inline unsigned int Lab1::Vigenere::modSum(unsigned int first, unsigned int second, unsigned int N)
{
	if (first + second >= N)
	{
		return first + second - N;
	}

	return first + second;
}

inline unsigned int Lab1::Vigenere::modDif(int first, int second, unsigned int N)
{
	if (first - second < 0)
	{
		return first - second + N;
	}

	return first - second;
}