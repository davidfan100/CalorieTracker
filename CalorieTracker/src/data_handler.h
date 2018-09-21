#pragma once
#include <string>
#include <fstream>
#include <vector>

const int kMaxNumOfCommas = 4;

class DataHandler {

private:
	std::vector<std::string> labels_;
	std::vector<double> breakfast_data_;
	std::vector<double> lunch_data_;
	std::vector<double> dinner_data_;
	std::vector<double> total_data_;
	std::vector<double> expected_data_;
	std::ofstream data_file_;

public:
	DataHandler();
	void AddItem(std::string input, std::string file_location);
	void GetContentsFromFile(std::string file_location);
	std::string AbbrevMonth(std::string month);

	std::vector<std::string> get_labels();
	std::vector<double> get_breakfast_data();
	std::vector<double> get_lunch_data();
	std::vector<double> get_dinner_data();
	std::vector<double> get_total_data();
	std::vector<double> get_expected_data();

};