#pragma once

#include "data_handler.h"

const int kNumOfDaysInWeek = 7;
const int kNumOfDaysForMonth = 30;
class ChartHandler {
private:
	int graph_height;
	int graph_width;

public:
	ChartHandler();
	ChartHandler(int width, int height);
	void SetUpRadarChart(DataHandler *data_h);
	void SetUpLineChart(DataHandler *data_h);
	void SetUpMultiBarChart(DataHandler *data_h);
	void SetUpDualBarChart(DataHandler *data_h);
	void SetUpPieChart(DataHandler *data_h);
	void SetUpFontXYChart(DataHandler *data_h);
};