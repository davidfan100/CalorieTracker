#include "chart_handler.h"
#include "../chartdir/chartdir.h"
#include "data_handler.h"
#include <fstream>
#include <iostream>

ChartHandler::ChartHandler() {
	graph_width = 0;
	graph_height = 0;
}

ChartHandler::ChartHandler(int width, int height) {
	graph_width = width - (width / 3);
	graph_height = height - 100;
}

void ChartHandler::SetUpRadarChart(DataHandler *data_h) {
	const char *labels[kNumOfDaysInWeek];
	double calories[kNumOfDaysInWeek];

	std::vector<std::string> data_labels = data_h->get_labels();
	std::vector<double> data_total = data_h->get_total_data();

	int counter_index = 0;

	//Getting the data from the past 7 days
	for (int i = data_total.size() - kNumOfDaysInWeek; i < data_total.size(); i++) {
		labels[counter_index] = data_labels[i].c_str();
		calories[counter_index] = data_total[i];

		counter_index++;
	}

	//Initializing the polar chart object
	PolarChart *rc = new PolarChart(graph_width, graph_height);

	//adding a title to the graph
	rc->addTitle("Calorie Intake throughout the week", "data/fonts/Cabin-Bold.ttf", 30);

	//setting the area to create the polar chart
	rc->setPlotArea(graph_width / 2, graph_height / 2, graph_height / 3);

	//adding the area with the calorie data
	rc->addAreaLayer(DoubleArray(calories, (int)(sizeof(calories) / sizeof(calories[0]))), 0x3498db);

	//setting the labels on the y-axis
	rc->angularAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));
	rc->angularAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 16);

	//creating the chart for the handler to use
	rc->makeChart("data/charts/radarchart.jpg");

	delete rc;
}

void ChartHandler::SetUpLineChart(DataHandler *data_h) {
	const char *labels[kNumOfDaysForMonth];
	double data[kNumOfDaysForMonth];

	std::vector<std::string> data_labels = data_h->get_labels();
	std::vector<double> data_total = data_h->get_total_data();

	//need the counter_index since the for loop starts near the end of the data lists
	int counter_index = 0;

	//Getting the data from the past 30 days
	for (int i = data_total.size() - kNumOfDaysForMonth; i < data_total.size(); i++) {
		labels[counter_index] = data_labels[i].c_str();
		data[counter_index] = data_total[i];

		counter_index++;
	}

	//Creating the line chart object
	XYChart *line_chart = new XYChart(graph_width, graph_height);

	//adding the title to the chart
	line_chart->addTitle("Calorie Intake throughout the past 30 days", "data/fonts/Cabin-Bold.ttf", 30);

	//Setting the plot area for the line chart
	line_chart->setPlotArea(310, 100, 700, 700);

	//Setting up layer to add the calorie data
	line_chart->addLineLayer(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), 0x8e44ad);

	//setting the labels for the xAxis
	line_chart->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));
	line_chart->xAxis()->setLabelStep(1);
	line_chart->xAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 8, TextColor, 90);

	//Setting the labels for the yAxis
	line_chart->yAxis()->setTitle("Calories", "data/fonts/Cabin-Regular.ttf", 16);
	line_chart->yAxis()->setTopMargin(50);

	//Creating the chart
	line_chart->makeChart("data/charts/linechart.jpg");

	delete line_chart;
}

void ChartHandler::SetUpMultiBarChart(DataHandler *data_h) {
	const char *labels[kNumOfDaysInWeek];
	double breakfast[kNumOfDaysInWeek];
	double lunch[kNumOfDaysInWeek];
	double dinner[kNumOfDaysInWeek];

	std::vector<std::string> data_labels = data_h->get_labels();
	std::vector<double> breakfast_data = data_h->get_breakfast_data();
	std::vector<double> lunch_data = data_h->get_lunch_data();
	std::vector<double> dinner_data = data_h->get_dinner_data();

	int counter_index = 0;

	//getting the calorie intake for breakfast, lunch, dinner and also expected calorie count
	for (int i = data_labels.size() - kNumOfDaysInWeek; i < data_labels.size(); i++) {
		labels[counter_index] = data_labels[i].c_str();
		breakfast[counter_index] = breakfast_data[i];
		lunch[counter_index] = lunch_data[i];
		dinner[counter_index] = dinner_data[i];

		counter_index++;
	}

	//creating the object to hold the multibar chart
	XYChart *multi_bar_chart = new XYChart(graph_width, graph_height);

	//adding title to the chart
	multi_bar_chart->addTitle("       Calorie Consumption throughout the past 7 days", "data/fonts/Cabin-Bold.ttf", 30);

	//setting the plot area for the multibar chart
	multi_bar_chart->setPlotArea(310, 140, 700, 700, 0xffffc0, 0xffffe0);

	//Creating a legend to differentiate breakfast, lunch, and dinner data
	multi_bar_chart->addLegend(800, 60, false, "data/fonts/Cabin-Regular.ttf", 14);

	//Adding a label to the y axis
	multi_bar_chart->yAxis()->setTitle("Calories", "data/fonts/Cabin-Regular.ttf", 16);
	multi_bar_chart->yAxis()->setTopMargin(50);

	//Adding the dates from our data to the x axis
	multi_bar_chart->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	//Adding layers to put the bars
	BarLayer *layer = multi_bar_chart->addBarLayer(Chart::Side, 3);

	//Adding data sets for each of the time of days
	layer->addDataSet(DoubleArray(breakfast, (int)(sizeof(breakfast) / sizeof(breakfast[0]))), 0xe74c3c, "Breakfast");
	layer->addDataSet(DoubleArray(lunch, (int)(sizeof(lunch) / sizeof(lunch[0]))), 0x2980b9, "Lunch");
	layer->addDataSet(DoubleArray(dinner, (int)(sizeof(dinner) / sizeof(dinner[0]))), 0x8e44ad, "Dinner");

	//creating the chart
	multi_bar_chart->makeChart("data/charts/barchart.jpg");

	delete multi_bar_chart;
}

void ChartHandler::SetUpDualBarChart(DataHandler *data_h) {
	const char *labels[kNumOfDaysInWeek];
	double expected_data[kNumOfDaysInWeek];
	double actual_data[kNumOfDaysInWeek];

	std::vector<std::string> data_labels = data_h->get_labels();
	std::vector<double> expect_data = data_h->get_expected_data();
	std::vector<double> act_data = data_h->get_total_data();

	int counter_index = kNumOfDaysInWeek - 1;

	//Getting data from the past 7 days of total and expected data
	for (int i = data_labels.size() - kNumOfDaysInWeek; i < data_labels.size(); i++) {
		labels[counter_index] = data_labels[i].c_str();
		expected_data[counter_index] = expect_data[i];
		actual_data[counter_index] = act_data[i];

		counter_index--;
	}

	//Creating the chart for the actual data
	XYChart *actual_chart = new XYChart(graph_width, graph_height);

	//Setting the plot area for the actual data chart
	actual_chart->setPlotArea(330, 100, 550, 545, 0x34495e);

	//Adding title to the actual chart
	actual_chart->addText(770, 60, "Actual Amount of Calories Consumed", "data/fonts/Cabin-Regular.ttf", 16)->setAlignment(Chart::TopRight);

	//creating the layer for the bar
	BarLayer *actual_layer = actual_chart->addBarLayer(DoubleArray(actual_data, (int)(sizeof(actual_data) / sizeof(actual_data[0]))),
		0xe74c3c);

	//swaping the x and y axis since we want the calories to be on the x axis
	actual_chart->swapXY(true);
	actual_chart->xAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 16);

	//Setting the width between each bar and setting the line data from the expected data, making it transparent to line
	//up the charts
	actual_layer->setBarGap(Chart::TouchBar);
	actual_layer->setBorderColor(-1, 1);
	actual_chart->addLineLayer(DoubleArray(expected_data, (int)(sizeof(expected_data) / sizeof(expected_data[0]))), Chart::Transparent);

	//Setting the font for the labels
	actual_chart->yAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 13);

	//Creating a textbox to show the dates from the data
	TextBox *text_box = actual_chart->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0])
		)));

	text_box->setSize(100, 0);
	text_box->setFontSize(13);
	text_box->setAlignment(Chart::Center);

	actual_chart->xAxis()->setTickLength(0);

	//Creating the chart for the expected data
	XYChart *expected_chart = new XYChart(graph_width, graph_height, Chart::Transparent);

	expected_chart->setPlotArea(280, 100, 550, 545, 0x2c3e50);

	expected_chart->addText(430, 60, "Expected Amount of Calories", "data/fonts/Cabin-Regular.ttf", 16);

	BarLayer *expected_layer = expected_chart->addBarLayer(DoubleArray(expected_data, (int)(sizeof(expected_data) / 
		sizeof(expected_data[0]))), 0x2980b9);

	expected_chart->swapXY(true);

	expected_chart->yAxis()->setReverse();

	expected_layer->setBarGap(Chart::TouchBar);
	expected_layer->setBorderColor(-1, 1);

	expected_chart->addLineLayer(DoubleArray(actual_data, (int)(sizeof(actual_data) / sizeof(actual_data[0]))),
		Chart::Transparent);

	expected_chart->yAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 13);

	//Creating the dual bar chart to combine the expected and actual charts
	MultiChart *dual_bar = new MultiChart(graph_width, graph_height);

	//Adding a title to the dual bar chart and adding the expected and actual charts
	dual_bar->addTitle("Expected vs Actual Amount of Calories Consumed", "data/fonts/Cabin-Bold.ttf", 30);
	dual_bar->addChart(360, 25, actual_chart);
	dual_bar->addChart(-240, 25, expected_chart);

	//Creating the dual bar chart
	dual_bar->makeChart("data/charts/dualbar.jpg");

	delete expected_chart;
	delete actual_chart;
	delete dual_bar;
}

void ChartHandler::SetUpPieChart(DataHandler *data_h) {
	const char *labels[kNumOfDaysInWeek];
	double data[kNumOfDaysInWeek];

	std::vector<std::string> data_labels = data_h->get_labels();
	std::vector<double> data_total = data_h->get_total_data();

	int counter_index = 0;

	//Getting data from the past 7 days
	for (int i = data_labels.size() - kNumOfDaysInWeek; i < data_labels.size(); i++) {
		labels[counter_index] = data_labels[i].c_str();
		data[counter_index] = data_total[i];

		counter_index++;
	}

	//Initializing colors to use for the sectors of the pie chart
	int colors[] = { 0x2ecc71, 0xf1c40f, 0xd35400, 0xe67e22, 0xe74c3c, 0x2980b9, 0x8e44ad};

	//Creating pie chart object
	PieChart *pie_chart = new PieChart(graph_width, graph_height);

	//adding title to the pie chart
	pie_chart->addTitle("Percentage of Calories consumed for the past 7 days", "data/fonts/Cabin-Bold.ttf", 30);
	pie_chart->setPieSize(graph_width / 2, graph_height / 2, graph_height / 3);

	//adding legend to the pie chart
	pie_chart->addLegend(graph_width - 300, 60, false, "data/fonts/Cabin-Regular.ttf", 15);

	//setting the format the labels should follow
	pie_chart->setLabelFormat("{percent}%");
	pie_chart->setLabelStyle("data/fonts/Cabin-Regular.ttf", 14);

	//adding the data to the pie chart
	pie_chart->setData(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), StringArray(labels,
		sizeof(labels) / sizeof(labels[0])));

	//setting the style of the pie chart
	pie_chart->setSectorStyle(Chart::RoundedEdgeShading, 0xffffff, 1);
	
	//setting the colors of each sector from our colors array
	pie_chart->setColors(Chart::DataColor, IntArray(colors, (int)(sizeof(colors) / sizeof(colors[0]))));

	//creating the chart
	pie_chart->makeChart("data/charts/piechart.jpg");

	delete pie_chart;
}

void ChartHandler::SetUpFontXYChart(DataHandler *data_h) {
	const char *labels[kNumOfDaysInWeek];
	double breakfast[kNumOfDaysInWeek];
	double lunch[kNumOfDaysInWeek];
	double dinner[kNumOfDaysInWeek];

	std::vector<std::string> data_labels = data_h->get_labels();
	std::vector<double> breakfast_data = data_h->get_breakfast_data();
	std::vector<double> lunch_data = data_h->get_lunch_data();
	std::vector<double> dinner_data = data_h->get_dinner_data();
	
	int counter_index = 0;

	//getting the labels, breakfast, lunch and dinner data from the data handler
	for (int i = data_labels.size() - kNumOfDaysInWeek; i < data_labels.size(); i++) {
		labels[counter_index] = data_labels[i].c_str();
		breakfast[counter_index] = breakfast_data[i];
		lunch[counter_index] = lunch_data[i];
		dinner[counter_index] = dinner_data[i];

		counter_index++;
	}

	//Creating the chart object for the fontxy chart
	XYChart *font_xy_chart = new XYChart(graph_width, graph_height);

	//setting the fontxy chart area
	font_xy_chart->setPlotArea(310, 100, 700, 700);

	//adding title to the chart
	font_xy_chart->addTitle("Calorie Intake throughout the past 7 days", "data/fonts/Cabin-Bold.ttf", 30);

	//adding legend to the chart
	font_xy_chart->addLegend(1075, 100, true, "data/fonts/Cabin-Regular.ttf", 16)->setBackground(0xd0d0d0, 0xd0d0d0, 1);

	//adding a title to the yaxis
	font_xy_chart->yAxis()->setTitle("Calories", "data/fonts/Cabin-Regular.ttf", 16);
	font_xy_chart->yAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 11);

	//setting the label style for the xaxis
	font_xy_chart->xAxis()->setLabelStyle("data/fonts/Cabin-Regular.ttf", 11, 0x2c3e50)->setFontAngle(90);
	font_xy_chart->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	//creating layer to add the bars
	BarLayer *font_xy_layer = font_xy_chart->addBarLayer(Chart::Stack, 5);

	//setting the styles of the labels
	font_xy_layer->setDataLabelStyle("data/fonts/Cabin-Regular.ttf");
	font_xy_layer->setAggregateLabelStyle("data/fonts/Cabin-Regular.ttf", 10)->setBackground(0xffff66, Chart::Transparent, 1);

	//adding the data for breakfast, lunch and dinner
	font_xy_layer->addDataSet(DoubleArray(breakfast, (int)(sizeof(breakfast) / sizeof(breakfast[0]))), 0xe74c3c, "Breakfast");
	font_xy_layer->addDataSet(DoubleArray(lunch, (int)(sizeof(lunch) / sizeof(lunch[0]))), 0x2980b9, "Lunch");
	font_xy_layer->addDataSet(DoubleArray(dinner, (int)(sizeof(dinner) / sizeof(dinner[0]))), 0x8e44ad, "Dinner");

	//creating the chart
	font_xy_chart->makeChart("data/charts/fontxychart.jpg");

	delete font_xy_chart;
}
