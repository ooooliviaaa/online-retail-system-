
#include "amazon_checker.h"

#include "Utility.h"
#include "DatabaseParser.h"
#include "ConsoleParser.h"

#include <gtest/gtest.h>



TEST(DatabaseReadback, EmptyDatabase)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"</products>\n"
			"<users>\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"</products>\n"
			"<users>\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(DatabaseReadback, Book)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"</products>\n"
			"<users>\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"</products>\n"
			"<users>\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(DatabaseReadback, Clothing)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(DatabaseReadback, Movie)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(DatabaseReadback, User)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100 0\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(DatabaseReadback, Mixed)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.5\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100 0\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(ConsoleInterface, Quit)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 4 products\n"
			"Read 3 users\n"
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
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input}, expectedOutput));
}

TEST(ConsoleInterface, HitBook)
{
	std::string const commands =
			"OR 978-013292372-9 978-013292372-2\n"
   			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 1 products\n"
			"Read 0 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"</products>\n"
			"<users>\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}


TEST(ConsoleInterface, HitClothing)
{
	std::string const commands =
			"AND Crew men\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 1 products\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Men's Fitted Shirt         \n"
			"Size: Medium Brand: J. Crew\n"
			"39.99 25 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"user 10000.00 0\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(ConsoleInterface, HitMovie)
{
	std::string const commands =
			"OR horror drama\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 1 products\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"\n"
			"Enter command: \n";


	std::string const inputDatabase =
			"<products>\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Planet Earth VHS\n"
			"20.25\n"
			"4\n"
			"Documentary\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"user 1000.0 0\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(ConsoleInterface, CaseInsensitive)
{
	std::string const commands =
			"OR Foo\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 2 products\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"FOO         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.99 8 left.\n"
   			"\n"
			"Hit   2\n"
			"foo         \n"
			"Genre: Programming Rating: TV-14\n"
			"20.25 4 left.\n"
			"\n"
			"\n"
			"Enter command: \n";


	std::string const inputDatabase =
			"<products>\n"
			"movie\n"
			"FOO\n"
			"0.99\n"
			"8\n"
			"Disaster\n"
			"PG-13\n"
			"movie\n"
			"foo\n"
			"20.25\n"
			"4\n"
			"Programming\n"
			"TV-14\n"
			"</products>\n"
			"<users>\n"
			"user 1000.0 0\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(ConsoleInterface, HugeQuantity)
{
	std::string const commands =
			"OR Disaster\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 2 products\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"The Killer Rabbit of Caerbannog: A Documentary         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.01 800000 left.\n"
			"\n"
			"\n"
			"Enter command: \n";


	std::string const inputDatabase =
			"<products>\n"
			"movie\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"0.01\n"
			"800000\n"
			"Disaster\n"
			"PG-13\n"
			"movie\n"
			"foo\n"
			"20.25\n"
			"4\n"
			"Programming\n"
			"TV-14\n"
			"</products>\n"
			"<users>\n"
			"user 1000.0 0\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}


TEST(ConsoleInterface, AddOneToCart)
{
	std::string const commands =
			"OR 978-013292372-9 978-013292372-2\n"
			"ADD user 1\n"
			"VIEWCART user\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 1 products\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: \n";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Graveyard of the Pacific\n"
			"9.95\n"
			"7\n"
			"978-192661331-4\n"
			"Anthony Dalton\n"
			"</products>\n"
			"<users>\n"
			"user 10000.00 0\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu,
															 Input, Hit, Input, // Search, parse hit, and add to cart.
															 Input, Cart, // View cart.
															 Input }, expectedOutput));
}

TEST(Database, BuyCart)
{
	std::string const commands =
			"OR 978-013292372-9 978-013292372-2\n"
			"ADD user 1\n"
			"VIEWCART user\n"
			"BUYCART user\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"</products>\n"
			"<users>\n"
			"user 10000.00 0\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"19\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"</products>\n"
			"<users>\n"
			"user 9920.01 0\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}


TEST(DatabaseReadback, ThreeBooks)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"East of Eden\n"
			"19.99\n"
			"10\n"
			"978-837023774-5\n"
			"John Steinbeck\n"
			"book\n"
			"00001010 00001111\n"
			"0.11\n"
			"0\n"
			"111-000000000-1\n"
			"A. Robot\n"
			"</products>\n"
			"<users>\n"
			"user 10000.00 0\n"
   			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"East of Eden\n"
			"19.99\n"
			"10\n"
			"978-837023774-5\n"
			"John Steinbeck\n"
			"book\n"
			"00001010 00001111\n"
			"0.11\n"
			"0\n"
			"111-000000000-1\n"
			"A. Robot\n"
			"</products>\n"
			"<users>\n"
			"user 10000.00 0\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}


TEST(DatabaseReadback, ThreeClothes)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"clothing\n"
			"Women's Blouse\n"
			"34.99\n"
			"8\n"
			"Small\n"
			"JCPenny\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"user 10000 0\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"clothing\n"
			"Women's Blouse\n"
			"34.99\n"
			"8\n"
			"Small\n"
			"JCPenny\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"user 10000 0\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}


TEST(DatabaseReadback, ThreeMovies)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Logan\n"
			"99.99\n"
			"99\n"
			"Action\n"
			"R\n"
			"movie\n"
			"' '\n"
			"7.50\n"
			"1000\n"
			"Neo-deconstructionalism\n"
			"G\n"
			"</products>\n"
			"<users>\n"
			"user 10000 0\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Logan\n"
			"99.99\n"
			"99\n"
			"Action\n"
			"R\n"
			"movie\n"
			"' '\n"
			"7.50\n"
			"1000\n"
			"Neo-deconstructionalism\n"
			"G\n"
			"</products>\n"
			"<users>\n"
			"user 10000 0\n"
			"</users>";
	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(ConsoleInterface, AddTwoItems)
{
	std::string const commands =
			"AND Hidden Figures\n"
			"ADD saty 1\n"
			"AND Great Men\n"
			"ADD saty 1\n"
			"VIEWCART saty\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 4 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"Item 2\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
			{Menu,
			Input, Hit, Input, // Search, parse hit, and add item to cart.
			Input, Hit, Input, // Search, parse hit, and add item to cart.
			Input, Cart, // View cart
			Input // Quit
			}, expectedOutput));
}

TEST(ConsoleInterface, AddTwoIdenticalItems)
{
	std::string const commands =
			"AND Hidden Figures\n"
			"ADD saty 1\n"
			"AND Hidden Figures\n"
			"ADD saty 1\n"
			"VIEWCART saty\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 4 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"Item 2\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  1 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.5\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"1\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100 0\n"
			"redekopp 50 1\n"
			"saty 120 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
								   {Menu,
									Input, Hit, Input, // Search, parse hit, and add item to cart.
									Input, Hit, Input, // Search, parse hit, and add item to cart.
									Input, Cart, // View cart
									Input // Quit
								   }, expectedOutput));
}

TEST(Database, BuyCartTwoItems)
{
	std::string const commands =
			"AND Hidden Figures\n"
			"ADD saty 1\n"
			"AND Hidden Figures\n"
			"ADD saty 1\n"
			"VIEWCART saty\n"
			"BUYCART saty\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	std::string const expectedDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.5\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"3\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100 0\n"
			"redekopp 50 1\n"
			"saty 84.02 1\n"
			"</users>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(ConsoleInterface, OrMultipleHit)
{
	std::string const commands =
			"OR Hidden Trojan and\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 4 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"Hit   2\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"Hit   3\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  5 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
						  		  {
									Menu,
									Input, Hit, // Search, parse hit
									Input // Quit
								   }, expectedOutput));
}

TEST(ConsoleInterface, AndMultipleHit)
{
	std::string const commands =
			"AND Great and\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 5 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Great Heights         \n"
			"Genre: and Rating: PG-13\n"
			"22.49  5 left.\n"
			"\n"
			"Hit   2\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
								   {
										   Menu,
										   Input, Hit, // Search, parse hit
										   Input // Quit
								   }, expectedOutput));
}

TEST(ConsoleInterface, AddToTwoUsersCarts)
{
	std::string const commands =
			"AND Great Men\n"
			"ADD redekopp 1\n"
			"AND Figures DVD\n"
			"ADD rafsilva 1\n"
			"VIEWCART redekopp\n"
			"VIEWCART rafsilva\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 5 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  5 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
								   {
									   Menu,
									   Input, Hit, Input, // Search, parse hit, add item to cart.
									   Input, Hit, Input, // Search, parse hit, add item to cart.
									   Input, Cart, // Viewcart.
									   Input, Cart, // Viewcart.
									   Input
								   }, expectedOutput));
}

TEST(ConsoleInterface, AddSameProductTwoUsersCarts)
{
	std::string const commands =
			"AND 111-000000000-1 Robot\n"
			"ADD redekopp 1\n"
			"ADD rafsilva 1\n"
			"VIEWCART redekopp\n"
			"VIEWCART rafsilva\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 5 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"00001010 00001111         \n"
			"Author: A. Robot ISBN: 111-000000000-1\n"
			"0.11  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"00001010 00001111         \n"
			"Author: A. Robot ISBN: 111-000000000-1\n"
			"0.11  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"00001010 00001111         \n"
			"Author: A. Robot ISBN: 111-000000000-1\n"
			"0.11  5 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women and Robot's of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"book\n"
			"00001010 00001111\n"
			"0.11\n"
			"5\n"
			"111-000000000-1\n"
			"A. Robot\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
								   {
										   Menu,
										   Input, Hit, Input, // Search, parse hit, add item to cart.
										   Input, // add item to cart.
										   Input, Cart, // Viewcart.
										   Input, Cart, // Viewcart.
										   Input
								   }, expectedOutput));
}


TEST(ConsoleInterface, AddTwoProductsTwoUsers)
{
	std::string const commands =
			"AND Great Men\n"
			"ADD redekopp 1\n"
			"AND Figures DVD\n"
			"ADD redekopp 1\n"
			"AND Great Men\n"
			"ADD rafsilva 1\n"
			"AND Data Abstraction\n"
			"ADD rafsilva 1\n"
			"VIEWCART redekopp\n"
			"VIEWCART rafsilva\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 5 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"Item 2\n"
			"Hidden Figures DVD         \n"
			"Genre: Drama Rating: PG\n"
			"17.99  5 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Great Men and Women of Troy         \n"
			"Author: Tommy Trojan ISBN: 978-000000000-1\n"
			"19.50  5 left.\n"
			"\n"
			"Item 2\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
								   {
										   Menu,
										   Input, Hit, Input, // Search, parse hit, add item to cart.
										   Input, Hit, Input, // Search, parse hit, add item to cart.
										   Input, Hit, Input, // Search, parse hit, add item to cart.
										   Input, Hit, Input, // Search, parse hit, add item to cart.
										   Input, Cart, // View cart.
										   Input, Cart, // View cart.
										   Input
								   }, expectedOutput));
}

TEST(Database, BuyTwoProductsTwoUsers)
{
	std::string const commands =
			"AND Great Men\n"
			"ADD redekopp 1\n"
			"AND Figures DVD\n"
			"ADD redekopp 1\n"
			"AND Great Men\n"
			"ADD rafsilva 1\n"
			"AND Data Abstraction\n"
			"ADD rafsilva 1\n"
			"VIEWCART redekopp\n"
			"VIEWCART rafsilva\n"
			"BUYCART redekopp\n"
			"BUYCART rafsilva\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";


	std::string const expectedDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"19\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.5\n"
			"3\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"4\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 0.51 0\n"
			"redekopp 12.51 1\n"
			"saty 120 1\n"
			"</users>";
	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(ConsoleInterface, BuyCartInsufficientFunds)
{
	// this should buy one book, but not the second one, since the user doesn't have enough money

	std::string const commands =
			"AND Data Abstraction\n"
			"ADD rafsilva 1\n"
			"AND Data Abstraction\n"
			"ADD rafsilva 1\n"
			"VIEWCART rafsilva\n"
			"BUYCART rafsilva\n"
			"VIEWCART rafsilva\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 5 products\n"
			"Read 3 users\n"
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
			"Enter command: \n"
			"Hit   1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Hit   1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"Item 2\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 20 left.\n"
			"\n"
			"\n"
			"Enter command: \n"
			"\n"
			"Enter command: \n"
			"Item 1\n"
			"Data Abstraction & Problem Solving with C++         \n"
			"Author: Carrano and Henry ISBN: 978-013292372-9\n"
			"79.99 19 left.\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction & Problem Solving with C++\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano and Henry\n"
			"book\n"
			"Great Men and Women of Troy\n"
			"19.50\n"
			"5\n"
			"978-000000000-1\n"
			"Tommy Trojan\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"movie\n"
			"Hidden Figures DVD\n"
			"17.99\n"
			"5\n"
			"Drama\n"
			"PG\n"
			"movie\n"
			"Great Heights\n"
			"22.49\n"
			"5\n"
			"and\n"
			"PG-13\n"
			"</products>\n"
			"<users>\n"
			"rafsilva 100.00 0\n"
			"redekopp 50.00 1\n"
			"saty 120.00 1\n"
			"</users>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
               {
                       Menu,
                       Input, Hit, Input, // Search, parse hit, add item to cart.
                       Input, Hit, Input, // Search, parse hit, add item to cart.
                       Input, Cart, // View cart.
                       Input, Cart, // Buy cart.
                       Input, Cart, // View cart.
                       Input
               }, expectedOutput));
}

TEST(Database, BuyCartInsufficientFunds)
{
    std::string const commands =
            "AND Data Abstraction\n"
            "ADD rafsilva 1\n"
            "AND Data Abstraction\n"
            "ADD rafsilva 1\n"
            "VIEWCART rafsilva\n"
            "BUYCART rafsilva\n"
            "VIEWCART rafsilva\n"
            "QUIT database.out\n";

    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.50\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "5\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 100.00 0\n"
            "redekopp 50.00 1\n"
            "saty 120.00 1\n"
            "</users>";

    // it should have bought one book, but not the second one, since the user doesn't have enough money

    std::string const expectedDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "19\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.5\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "5\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 20.01 0\n"
            "redekopp 50 1\n"
            "saty 120 1\n"
            "</users>";

    EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(ConsoleInterface, AddItemToMultipleUsers)
{
    std::string const commands =
            "AND Figures DVD\n"
            "ADD rafsilva 1\n"
            "AND Figures DVD\n"
            "ADD redekopp 1\n"
            "VIEWCART rafsilva\n"
            "VIEWCART redekopp\n"
            "QUIT database.out\n";

    std::string const expectedOutput =
            "Read 5 products\n"
            "Read 3 users\n"
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
            "Enter command: \n"
            "Hit   1\n"
            "Hidden Figures DVD         \n"
            "Genre: Drama Rating: PG\n"
            "17.99  1 left.\n"
            "\n"
            "\n"
            "Enter command: \n"
            "\n"
            "Enter command: \n"
            "Hit   1\n"
            "Hidden Figures DVD         \n"
            "Genre: Drama Rating: PG\n"
            "17.99  1 left.\n"
            "\n"
            "\n"
            "Enter command: \n"
            "\n"
            "Enter command: \n"
            "Item 1\n"
            "Hidden Figures DVD         \n"
            "Genre: Drama Rating: PG\n"
            "17.99  1 left.\n"
            "\n"
            "\n"
            "Enter command: \n"
            "Item 1\n"
            "Hidden Figures DVD         \n"
            "Genre: Drama Rating: PG\n"
            "17.99  1 left.\n"
            "\n"
            "\n"
            "Enter command: ";


    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.50\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "1\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 100.00 0\n"
            "redekopp 50.00 1\n"
            "saty 120.00 1\n"
            "</users>";

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
                                   {
                                       Menu,
                                       Input, Hit, Input, // Search, parse hit, add item to cart.
                                       Input, Hit, Input, // Search, parse hit, add item to cart.
                                       Input, Cart, // View cart.
                                       Input, Cart, // View cart.
                                       Input
                                   }, expectedOutput));
}

TEST(Database, BuySingleStockItemMultipleUsers)
{
    std::string const commands =
            "AND Figures DVD\n"
            "ADD rafsilva 1\n"
            "AND Figures DVD\n"
            "ADD redekopp 1\n"
            "BUYCART rafsilva\n"
            "BUYCART redekopp\n"
            "QUIT database.out\n";

    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.50\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "1\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 100.00 0\n"
            "redekopp 50.00 1\n"
            "saty 120.00 1\n"
            "</users>";

    std::string const expectedDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.5\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "0\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 82.01 0\n"
            "redekopp 50 1\n"
            "saty 120 1\n"
            "</users>";

    EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(ConsoleErrors, ViewCartUnknownUser)
{
    std::string const commands =
            "VIEWCART aaron\n"
            "QUIT database.out\n";

    std::string const expectedOutput =
            "Read 5 products\n"
            "Read 3 users\n"
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
            "Enter command: \n"
            "Invalid username\n"
            "\n"
            "Enter command: ";


    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.50\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "1\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 100.00 0\n"
            "redekopp 50.00 1\n"
            "saty 120.00 1\n"
            "</users>";

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
               {
                       Menu,
                       Input, InvalidUsername, // View cart for invalid username.
                       Input
               }, expectedOutput));
}

TEST(ConsoleErrors, BuyCartUnknownUser)
{
    std::string const commands =
            "BUYCART aaron\n"
            "QUIT database.out\n";

    std::string const expectedOutput =
            "Read 5 products\n"
            "Read 3 users\n"
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
            "Enter command: \n"
            "Invalid username\n"
            "\n"
            "Enter command: ";


    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.50\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "1\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 100.00 0\n"
            "redekopp 50.00 1\n"
            "saty 120.00 1\n"
            "</users>";

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
                       {
                               Menu,
                               Input, InvalidUsername, // View cart for invalid username.
                               Input
                       }, expectedOutput));
}

TEST(ConsoleErrors, AddInvalidHitToCart)
{
    std::string const commands =
            "AND Great Men\n"
            "ADD aaron 1\n"
            "QUIT database.out\n";

    std::string const expectedOutput =
            "Read 5 products\n"
            "Read 3 users\n"
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
            "Enter command: \n"
            "Hit   1\n"
            "Great Men and Women of Troy         \n"
            "Author: Tommy Trojan ISBN: 978-000000000-1\n"
            "19.50  5 left.\n"
            "\n"
            "\n"
            "Enter command: \n"
            "Invalid request\n"
            "\n"
            "Enter command: ";


    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction & Problem Solving with C++\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano and Henry\n"
            "book\n"
            "Great Men and Women of Troy\n"
            "19.50\n"
            "5\n"
            "978-000000000-1\n"
            "Tommy Trojan\n"
            "clothing\n"
            "Men's Fitted Shirt\n"
            "39.99\n"
            "25\n"
            "Medium\n"
            "J. Crew\n"
            "movie\n"
            "Hidden Figures DVD\n"
            "17.99\n"
            "1\n"
            "Drama\n"
            "PG\n"
            "movie\n"
            "Great Heights\n"
            "22.49\n"
            "5\n"
            "and\n"
            "PG-13\n"
            "</products>\n"
            "<users>\n"
            "rafsilva 100.00 0\n"
            "redekopp 50.00 1\n"
            "saty 120.00 1\n"
            "</users>";

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase,
                                   {
                                           Menu,
                                           Input, Hit, // Search and parse hit.
                                           Input, InvalidRequest, // Add invalid index to user.
                                           Input
                                   }, expectedOutput));
}
