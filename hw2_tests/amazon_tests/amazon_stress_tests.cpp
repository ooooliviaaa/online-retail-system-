//
// Created by cs104 on 3/15/19.
//

#include "amazon_checker.h"

#include "Utility.h"
#include "DatabaseParser.h"
#include "ConsoleParser.h"

#include <random_generator.h>

#include <gtest/gtest.h>

#include <iomanip>


TEST(AmazonStress, Buy10000Products)
{
    const size_t numProducts = 10000;
    const int initialQuantity = 7;
    const std::string author = "D. Quark";

    // build command set
    std::stringstream commands;
    commands << "OR Quark" << std::endl;

    for(size_t hitNumber = 1; hitNumber <= numProducts; ++hitNumber)
    {
        commands << "ADD nyan " << hitNumber << std::endl;
    }

    commands <<
            "BUYCART nyan\n"
            "QUIT database.out\n";

    // calculate how much money to give user so that they have more than enough for every product
    double startingMoney = numProducts * (1 + (numProducts * .01));
    double moneyRemaining = startingMoney;


    // build stress test dataset
    std::stringstream inputDatabase;
    std::stringstream outputDatabase;

    inputDatabase << "<products>" << std::endl;
    outputDatabase << "<products>" << std::endl;

    for(size_t productNum = 0; productNum < numProducts; ++productNum)
    {
        const std::string bookTitle = "The Secret Lives of " + std::string(productNum % 2 == 0 ? "Protons" : "Electrons") + " Vol. " + std::to_string(productNum);
        const double price = 1 + productNum * .01;

        std::stringstream isbn;
        isbn << "978-" << std::setfill('0') << std::setw(9) << productNum << "-0";

        // create input database entry
        inputDatabase << "book" << std::endl;
        inputDatabase << bookTitle << std::endl;
        inputDatabase << price << std::endl;
        inputDatabase << initialQuantity << std::endl;
        inputDatabase << isbn.str() << std::endl;
        inputDatabase << author << std::endl;

        // create output database entry
        outputDatabase << "book" << std::endl;
        outputDatabase << bookTitle << std::endl;
        outputDatabase << price << std::endl;
        outputDatabase << (initialQuantity - 1) << std::endl;
        outputDatabase << isbn.str() << std::endl;
        outputDatabase << author << std::endl;

        // we are buying one of these, so subtract from end money
        moneyRemaining -= price;
    }

    // footer on databases
    inputDatabase << "</products>\n"
                     "<users>\n"
                     "nyan " << std::fixed << startingMoney << " 0\n"
                     "</users>";

    outputDatabase << "</products>\n"
                     "<users>\n"
                     "nyan " << std::fixed << moneyRemaining << " 0\n"
                      "</users>";



    EXPECT_TRUE(checkDatabase(commands.str(), inputDatabase.str(), outputDatabase.str(), false));
}

TEST(AmazonStress, AndSearch10000Products)
{
    const size_t numProducts = 10000;
    const int quantity = 50;
    const std::string author = "U. Quark";


    std::string const commands =
            "AND Protons Quark\n"
            "QUIT database.out\n";

    // build stress test dataset
    std::stringstream inputDatabase;
    std::stringstream expectedOutput;

    inputDatabase << "<products>" << std::endl;
    expectedOutput << "Read " << numProducts << " products\n"
                                                "Read 1 users\n"
                                                "=====================================\n"
                                                "Menu: \n"
                                                "  AND term term ...                  \n"
                                                "  OR term term ...                   \n"
                                                "  ADD username search_hit_number     \n"
                                                "  VIEWCART username                  \n"
                                                "  BUYCART username                   \n"
                                                "  QUIT new_db_filename               \n"
                                                "====================================\n"
                                                "\n"
                                                "Enter command: \n";

    int hitNumber = 1;

    for(size_t productNum = 0; productNum < numProducts; ++productNum)
    {
        const std::string bookTitle = "The Secret Lives of " + std::string(productNum % 2 == 0 ? "Protons" : "Electrons") + " Vol. " + std::to_string(productNum);
        const double price = 1 + productNum * .01;

        std::stringstream isbn;
        isbn << "978-" << std::setfill('0') << std::setw(9) << productNum << "-0";

        // create database entry
        inputDatabase << "book" << std::endl;
        inputDatabase << bookTitle << std::endl;
        inputDatabase << price << std::endl;
        inputDatabase << quantity << std::endl;
        inputDatabase << isbn.str() << std::endl;
        inputDatabase << author << std::endl;

        if(productNum % 2 == 0)
        {
            // create expected output entry, if this is expected to show up in the search results (only 'Protons' ones)
            // note: order of hits doesn't matter, the checker is order-insensitive
            expectedOutput << "Hit " << hitNumber << std::endl;
            expectedOutput << bookTitle << std::endl;
            expectedOutput << "Author: " << author << " ISBN: " << isbn.str() << std::endl;
            expectedOutput << price << " " << quantity << " left." << std::endl;
            expectedOutput << std::endl;

            hitNumber++;
        }

    }

    // footer on output and database
    inputDatabase << "</products>\n"
                     "<users>\n"
                     "nyan 100.00 0\n"
                     "</users>";

    expectedOutput << std::endl;
    expectedOutput << "Enter command: " << std::endl;

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase.str(),
                                   {
                                           Menu,
                                           Input, Hit, // Search and parse hit.
                                           Input
                                   }, expectedOutput.str(), false));
}

