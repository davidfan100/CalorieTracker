#define CATCH_CONFIG_MAIN
#include "../src/data_handler.h"
#include "../src/data_handler.cpp"
#include "catch.hpp"
#include <vector>
#include <fstream>

TEST_CASE("TestAddItemNormal1") {
	DataHandler data_handler = DataHandler();
	
	std::string input = "May 14,400,600,400,1500";

	data_handler.AddItem(input, "testing.txt");

	data_handler.GetContentsFromFile("testing.txt");

	REQUIRE(data_handler.get_labels()[0] == "May 14");
	REQUIRE(data_handler.get_breakfast_data()[0] == 400);
	REQUIRE(data_handler.get_lunch_data()[0] == 600);
	REQUIRE(data_handler.get_dinner_data()[0] == 400);
	REQUIRE(data_handler.get_expected_data()[0] == 1500);
}

TEST_CASE("TestAddItemNormal2") {
	DataHandler data_handler = DataHandler();

	std::string input = "July 2,700,500,823,1600";

	data_handler.AddItem(input, "testing1.txt");

	data_handler.GetContentsFromFile("testing1.txt");

	REQUIRE(data_handler.get_labels()[0] == "July 2");
	REQUIRE(data_handler.get_breakfast_data()[0] == 700);
	REQUIRE(data_handler.get_lunch_data()[0] == 500);
	REQUIRE(data_handler.get_dinner_data()[0] == 823);
	REQUIRE(data_handler.get_expected_data()[0] == 1600);
}

TEST_CASE("TestAddItemNormal3") {
	DataHandler data_handler = DataHandler();

	std::string input = "September 13,90,543,789,1500";

	data_handler.AddItem(input, "testing2.txt");

	data_handler.GetContentsFromFile("testing2.txt");

	REQUIRE(data_handler.get_labels()[0] == "Sept 13");
	REQUIRE(data_handler.get_breakfast_data()[0] == 90);
	REQUIRE(data_handler.get_lunch_data()[0] == 543);
	REQUIRE(data_handler.get_dinner_data()[0] == 789);
	REQUIRE(data_handler.get_expected_data()[0] == 1500);
}

TEST_CASE("TestAddItemEdge1") {
	DataHandler data_handler = DataHandler();

	std::string input = "September145i42034";

	data_handler.AddItem(input, "testing3.txt");

	data_handler.GetContentsFromFile("testing3.txt");

	REQUIRE(data_handler.get_labels().size() == 0);
	REQUIRE(data_handler.get_breakfast_data().size() == 0);
	REQUIRE(data_handler.get_lunch_data().size() == 0);
	REQUIRE(data_handler.get_dinner_data().size() == 0);
	REQUIRE(data_handler.get_expected_data().size() == 0);
}

TEST_CASE("TestAbbrevMonthNormal1") {
	DataHandler data_handler = DataHandler();

	std::string month = "October";

	month = data_handler.AbbrevMonth(month);

	REQUIRE(month == "Oct");
}

TEST_CASE("TestAbbrevMonthNormal2") {
	DataHandler data_handler = DataHandler();

	std::string month = "December";

	month = data_handler.AbbrevMonth(month);

	REQUIRE(month == "Dec");
}

TEST_CASE("TestAbbrevMonthNormal3") {
	DataHandler data_handler = DataHandler();

	std::string month = "February";

	month = data_handler.AbbrevMonth(month);

	REQUIRE(month == "Feb");
}

TEST_CASE("TestAbbrevMonthEdge1") {
	DataHandler data_handler = DataHandler();

	std::string month = "June";

	month = data_handler.AbbrevMonth(month);

	REQUIRE(month == "June");
}

TEST_CASE("TestGetContentsFromFile1") {
	DataHandler data_handler = DataHandler();

	data_handler.GetContentsFromFile("DataContents1.txt");

	REQUIRE(data_handler.get_labels()[0] == "May 3");
	REQUIRE(data_handler.get_breakfast_data()[0] == 400);
	REQUIRE(data_handler.get_lunch_data()[0] == 500);
	REQUIRE(data_handler.get_dinner_data()[0] == 600);
	REQUIRE(data_handler.get_expected_data()[0] == 1500);

	REQUIRE(data_handler.get_labels()[1] == "May 2");
	REQUIRE(data_handler.get_breakfast_data()[1] == 459);
	REQUIRE(data_handler.get_lunch_data()[1] == 867);
	REQUIRE(data_handler.get_dinner_data()[1] == 145);
	REQUIRE(data_handler.get_expected_data()[1] == 1900);	

	REQUIRE(data_handler.get_total_data()[0] == 1500);
	REQUIRE(data_handler.get_total_data()[1] == 1471);
}

TEST_CASE("TestGetContentsFromFileEdge") {
	DataHandler data_handler = DataHandler();

	data_handler.GetContentsFromFile("DataContents2.txt");

	REQUIRE(data_handler.get_labels().size() == 0);
	REQUIRE(data_handler.get_breakfast_data().size() == 0);
	REQUIRE(data_handler.get_lunch_data().size() == 0);
	REQUIRE(data_handler.get_dinner_data().size() == 0);
	REQUIRE(data_handler.get_expected_data().size() == 0);
}


