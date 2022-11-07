#ifndef CONSOLE_PARSER_H
#define CONSOLE_PARSER_H

#include "Utility.h"
#include <set>
#include <vector>
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>

#include <kwsys/RegularExpression.hxx>

enum ConsoleParserCommand
{
	Menu,
	Input,
	Hit,
	Cart,
	InvalidRequest,
	InvalidUsername
};

class ConsoleParser
{
public:
	class ConsoleProduct
	{
	public:
		ConsoleProduct(const std::string& name, const std::string& info, int stock, double price);
		bool operator<(const ConsoleProduct& rhs) const;
		bool operator==(const ConsoleProduct& rhs) const;

		std::string mName;
		std::string mInfo;
		int mStock;
		double mPrice;
	};

	class Hit : public std::set<ConsoleProduct>
	{
	public:
		void AddProduct(ConsoleProduct&& p);
		bool operator==(const Hit& rhs) const;
	};

	class Cart : public std::vector<ConsoleProduct>
	{
	public:
		void AddProduct(ConsoleProduct&& p);
		bool operator==(const Cart& rhs) const;
	};

	testing::AssertionResult CompareHit(const ConsoleParser &actual) const;
	testing::AssertionResult CompareCart(const ConsoleParser &actual) const;
	testing::AssertionResult ParseMenu(std::istream &stream);
	testing::AssertionResult ParseInput(std::istream &stream);
	testing::AssertionResult ParseHit(std::istream &stream);
	testing::AssertionResult ParseCart(std::istream &stream);
	testing::AssertionResult ParseInvalidRequest(std::istream &stream);
	testing::AssertionResult ParseInvalidUsername(std::istream &stream);

	// regex to match the equals sign line that denotes the menu
	static kwsys::RegularExpression menuEqualsSep;

	// regex to match the command line prompt given by the program
	static kwsys::RegularExpression enterCommandLine;

	// regexes to match the error messages
	static kwsys::RegularExpression invalidRequest;
	static kwsys::RegularExpression invalidUsername;


public:
	/**
	 * Parse a sequence of commands feom an input file.
	 * @param stream
	 * @param sequence
	 * @return
	 */
	testing::AssertionResult parseSequence(std::istream& stream, std::vector<ConsoleParserCommand> sequence);

private:
	testing::AssertionResult ParseConsoleCommand(std::istream &stream, std::string const &sectionName);

	template<typename T>
    testing::AssertionResult ParseConsoleProduct(std::istream &stream, std::vector<T> &container);

private:
	std::vector<std::string> mCommand;
	std::vector<Hit> mHit;
	std::vector<Cart> mCart;
};

template<typename T>
testing::AssertionResult ConsoleParser::ParseConsoleProduct(std::istream &stream, std::vector<T> &container)
{
	std::streampos pos = stream.tellg();
	T hits;

	std::string content;
	int running = 1;
	int counter;
	while (stream >> content >> counter)
	{

		if(counter != running)
		{
			return testing::AssertionFailure() << "Product numbering is not continuous!  Prev number was " << (running - 1) << ", this listing was " << counter;
		}

		getline(stream, content); // remove newline

		std::string name, info;
		double price;
		int stock;

		getline(stream, name);
		getline(stream, info);
		stream >> price >> stock;

		// throw away the rest of the line
		getline(stream, content);

		if (stream.fail())
		{
			return testing::AssertionFailure() << "Product description is formatted incorrectly!";
		}
		else
		{
			// product parsed successfully
			RemoveWhiteSpace(trim(name));
			RemoveWhiteSpace(trim(info));

			if(name.empty() || info.empty() || stock < 0)
			{
				return testing::AssertionFailure() << "Parts of the search result were empty or formatted incorrectly!";
			}

			hits.AddProduct(ConsoleProduct(name, info, stock, price));
		}

		++running;
		pos = stream.tellg(); // set position to after current search
	}
	container.emplace_back(hits);
	stream.clear();
	stream.seekg(pos); // restore position to before failed "Hit #"

	return testing::AssertionSuccess();
}

std::ostream & operator<<(std::ostream & stream, const ConsoleParser::ConsoleProduct product);


#endif
