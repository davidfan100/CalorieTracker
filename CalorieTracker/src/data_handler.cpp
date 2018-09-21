#include "data_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

DataHandler::DataHandler() {

}

void DataHandler::AddItem(std::string input, std::string file_location) {
	//Opens the file at the file location
	data_file_.open(file_location, std::ios_base::app);

	if (input.find(',') == std::string::npos) {
		return;
	}

	//putting the input into a stringstream to sepearte the string by words
	std::stringstream ss(input);

	std::string string_for_data;

	data_file_ << std::endl;

	//Used to make sure the last number doesn't have a space after the input
	int counter = 0;

	//Goes through the data to get the obtain the words of the string 
	//that are separated by commas
	while (getline(ss, string_for_data, ',')) {
		if (counter == kMaxNumOfCommas) {
			data_file_ << string_for_data;
		}
		else {
			data_file_ << string_for_data << " ";
			counter++;
		}
	}

	data_file_.close();
}

void DataHandler::GetContentsFromFile(std::string file_location) {
	//Opens the files of the data contents
	std::ifstream data_getter(file_location);

	std::string label;
	std::string month;
	std::string day;
	int breakfast;
	int lunch;
	int dinner;
	int expected;

	//Checks if the file is empty
	if (data_getter.peek() == std::ios_base::eofbit) {
		return;
	}

	//Goes through the file and extracts each individual data piece
	while (!data_getter.eof()) {
		data_getter >> month;
		data_getter >> day;

		//Abbreviates the month if it is too long
		month = AbbrevMonth(month);
		label = month + " " + day;
		labels_.push_back(label);

		data_getter >> breakfast;
		breakfast_data_.push_back(breakfast);

		data_getter >> lunch;
		lunch_data_.push_back(lunch);

		data_getter >> dinner;
		dinner_data_.push_back(dinner);

		//adds up the breakfast, lunch, and dinner data to obtain the total data
		total_data_.push_back(breakfast + lunch + dinner);

		data_getter >> expected;
		expected_data_.push_back(expected);
	}

}

std::string DataHandler::AbbrevMonth(std::string month) {
	if (month == "January") {
		return "Jan";
	} else if (month == "February") {
		return "Feb";
	} else if (month == "August") {
		return "Aug";
	} else if (month == "September") {
		return "Sept";
	} else if (month == "October") {
		return "Oct";
	} else if (month == "November") {
		return "Nov";
	} else if (month == "December") {
		return "Dec";
	}

	return month;
}

std::vector<std::string> DataHandler::get_labels() { 
	return labels_;
}

std::vector<double> DataHandler::get_breakfast_data() {
	return breakfast_data_;
}

std::vector<double> DataHandler::get_lunch_data() {
	return lunch_data_;
}

std::vector<double> DataHandler::get_dinner_data() {
	return dinner_data_;
}

std::vector<double> DataHandler::get_total_data() {
	return total_data_;
}

std::vector<double> DataHandler::get_expected_data() {
	return expected_data_;
}