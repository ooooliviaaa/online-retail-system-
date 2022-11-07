//
// Created by cs104 on 3/1/19.
//

#include "amazon_checker.h"

#include "DatabaseParser.h"
#include "ConsoleParser.h"

#include <user_code_runner.h>

#include <kwsys/SystemTools.hxx>

#include <fstream>

testing::AssertionResult checkDatabase(std::string const &inputFile, std::string const &inputDatabase, std::string const &expectedDatabase, bool useValgrind)
{
	std::stringstream outputDatabase;
	std::stringstream outputFile;

	SUB_ASSERT(testAmazon(inputFile, inputDatabase, outputDatabase, outputFile, useValgrind))

	// parse the products and users from the database
	DatabaseParser studentDatabase;
	SUB_ASSERT(studentDatabase.ParseProduct(outputDatabase));
	SUB_ASSERT(studentDatabase.ParseUser(outputDatabase));

	// now, parse the expected solution
	DatabaseParser solutionDatabase;
	std::istringstream solutionDatabaseStream(expectedDatabase);
	SUB_ASSERT(solutionDatabase.ParseProduct(solutionDatabaseStream));
	SUB_ASSERT(solutionDatabase.ParseUser(solutionDatabaseStream));

	// now, check that they're the same
	SUB_ASSERT(solutionDatabase.CompareProduct(studentDatabase));
	SUB_ASSERT(solutionDatabase.CompareUser(studentDatabase));

	return testing::AssertionSuccess();
}


testing::AssertionResult checkConsoleOutput(std::string const &inputFile, std::string const &inputDatabase, std::vector<ConsoleParserCommand> commandTypes, std::string const &expectedConsoleOutput, bool useValgrind)
{
	std::stringstream outputDatabase;
	std::stringstream outputFile;

	SUB_ASSERT(testAmazon(inputFile, inputDatabase, outputDatabase, outputFile, useValgrind));

	ConsoleParser studentConsole;
	ConsoleParser solutionConsole;
	std::stringstream expectedOutputStream(expectedConsoleOutput);
	SUB_ASSERT(studentConsole.parseSequence(outputFile, commandTypes));
	SUB_ASSERT(solutionConsole.parseSequence(expectedOutputStream, commandTypes));

	EXPECT_TRUE(solutionConsole.CompareHit(studentConsole));
	EXPECT_TRUE(solutionConsole.CompareCart(studentConsole));

	return testing::AssertionSuccess();
}


testing::AssertionResult testAmazon(std::string const & inputFile, std::string const & inputDatabase, std::stringstream & outputDatabase, std::stringstream & outputFile, bool useValgrind)
{
	// get name of current test
	std::string testName = testing::UnitTest::GetInstance()->current_test_info()->name();

	// set up file structure
	std::string executablePath = AMAZON_EXECUTABLE; // this definition points to the amazon executable
	std::string testFolder = TEST_BINARY_DIR "/amazon_tests/testFiles/" + testName;
	kwsys::SystemTools::MakeDirectory(testFolder);

	std::string databaseFilePath = testFolder + "/database.txt";
	std::string inputFilePath = testFolder + "/input.txt";
	std::string outputFilePath = testFolder + "/output.txt";
	std::string outputDatabaseFilePath = testFolder + "/database.out";

	{
		// write database to file
		std::ofstream databaseWriter(databaseFilePath);
		databaseWriter << inputDatabase << std::endl;
	}


	// run the program
	UserCodeRunner runner(testFolder, executablePath, {databaseFilePath}, outputFilePath, useValgrind);
	runner.setStdin(inputFile, inputFilePath);
	runner.setCheckExitCode(false);
	SUB_ASSERT(runner.execute());

	// now, get the output
	{
		std::ifstream outputFileFstream(outputFilePath);

		if (!outputFile)
		{
			return testing::AssertionFailure() << "Couldn't open output file " << outputFilePath;
		}

		// set the output file as the stream's buffer
		outputFile << outputFileFstream.rdbuf();
	}

	{
		std::ifstream outputDatabaseFstream(outputDatabaseFilePath);

		if (!outputFile)
		{
			return testing::AssertionFailure() << "Couldn't open output database file " << outputDatabaseFilePath;
		}

		// set the output file as the stream's buffer
		outputDatabase << outputDatabaseFstream.rdbuf();
	}


	return testing::AssertionSuccess();
}

