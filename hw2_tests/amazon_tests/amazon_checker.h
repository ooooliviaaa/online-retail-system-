//
// Auto-checker for Amazon
//

#ifndef CS104_HW4_TEST_SUITE_AMAZON_CHECKER_H
#define CS104_HW4_TEST_SUITE_AMAZON_CHECKER_H

#include "ConsoleParser.h"

#include <gtest/gtest.h>

/**
 * Checks that, when run on the given input, the user's amazon program produces a database with the same content as the one given.
 *
 * Note that this actually parses both databases according to the assignment rules, so it performs a fuzzy comparison between them.
 * It's not just a string compare.
 * @param inputFile
 * @param inputDatabase
 * @param expectedDatabase
 * @return
 */
testing::AssertionResult checkDatabase(std::string const & inputFile, std::string const & inputDatabase, std::string const & expectedDatabase, bool useValgrind = true);

/**
 * Checks that the console output of running Amazon on the given input matches the expected output.
 * This does a fuzzy comparison by parsing both sets of outputs according to the given command list, then checking that they match
 * @param inputFile
 * @param inputDatabase
 * @param expectedDatabase
 * @return
 */
testing::AssertionResult checkConsoleOutput(std::string const & inputFile, std::string const & inputDatabase, std::vector<ConsoleParserCommand> commandTypes, std::string const & expectedConsoleOutput, bool useValgrind = true);


/**
 * Runs the user's Amazon program on the given database and input, and returns the output in the outputDatabase and outputFile variables
 * @param inputFile
 * @param inputDatabase
 * @param outputDatabase
 * @param outputFile
 * @return An assertion failure iff the execution of the program failed
 */
testing::AssertionResult testAmazon(std::string const & inputFile, std::string const & inputDatabase, std::stringstream & outputDatabase, std::stringstream & outputFile, bool useValgrind = true);

#endif //CS104_HW4_TEST_SUITE_AMAZON_CHECKER_H
