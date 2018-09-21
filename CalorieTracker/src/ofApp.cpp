#include "ofApp.h"
#include "chart_handler.h"
#include "data_handler.h"
#include "../addons/ofxUI/src/ofxUI.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(211, 84, 0);
	int xLocation = ofGetScreenWidth() / 3;
	int yLocation = ofGetScreenHeight() - 100;

	ofEnableSmoothing();

	//Creating area for the charts
	graph_area_ = new ofxUIRectangle(xLocation, 0, (ofGetScreenWidth() - (ofGetScreenWidth() / 3)), ofGetScreenHeight() - 100);

	//Creating radar chart button
	ofxUIRectangle radar_area = ofxUIRectangle(xLocation, yLocation,
		(ofGetScreenWidth() - xLocation) / 6, (ofGetScreenHeight() - yLocation));
	radar_button_ = new ofxUICanvas(radar_area);
	radar_button_->setColorBack(ofxUIColor(204, 51, 0));
	radar_button_->setFontSize(OFX_UI_FONT_LARGE, 14.5);
	radar_button_->addLabel("   Radar Chart", OFX_UI_FONT_LARGE);
	radar_button_->addButton("Radar Graph", false, 200, 60);
	radar_button_->setDrawOutlineHighLight(true);
	radar_button_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	radar_button_->drawOutlineHighlight();

	//Creating line chart button
	ofxUIRectangle line_area = ofxUIRectangle(radar_area.getMaxX(), yLocation, 
		(ofGetScreenWidth() - xLocation) / 6, (ofGetScreenHeight() - yLocation));
	line_button_ = new ofxUICanvas(line_area);
	line_button_->setColorBack(ofxUIColor(255, 102, 0));
	line_button_->setFontSize(OFX_UI_FONT_LARGE, 14.5);
	line_button_->addLabel("    Line Chart", OFX_UI_FONT_LARGE);
	line_button_->addButton("Line Graph", false, 200, 60);
	line_button_->setDrawOutlineHighLight(true);
	line_button_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	line_button_->drawOutlineHighlight();

	//Creating multi bar chart button
	ofxUIRectangle multi_bar_area = ofxUIRectangle(line_area.getMaxX(), yLocation,
		(ofGetScreenWidth() - xLocation) / 6, (ofGetScreenHeight() - yLocation));
	multi_bar_button_ = new ofxUICanvas(multi_bar_area);
	multi_bar_button_->setColorBack(ofxUIColor(255, 153, 0));
	multi_bar_button_->setFontSize(OFX_UI_FONT_LARGE, 14.5);
	multi_bar_button_->addLabel(" Multi Bar Chart", OFX_UI_FONT_LARGE);
	multi_bar_button_->addButton("Multi Bar Graph", false, 200, 60);
	multi_bar_button_->setDrawOutlineHighLight(true);
	multi_bar_button_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	multi_bar_button_->drawOutlineHighlight();

	//Creating dual bar chart button
	ofxUIRectangle dual_bar_area = ofxUIRectangle(multi_bar_area.getMaxX(), yLocation,
		(ofGetScreenWidth() - xLocation) / 6, (ofGetScreenHeight() - yLocation));
	dual_bar_button_ = new ofxUICanvas(dual_bar_area);
	dual_bar_button_->setColorBack(ofxUIColor(255, 153, 51));
	dual_bar_button_->setFontSize(OFX_UI_FONT_LARGE, 14.5);
	dual_bar_button_->addLabel(" Dual Bar Chart", OFX_UI_FONT_LARGE);
	dual_bar_button_->addButton("Dual Bar Graph", false, 200, 60);
	dual_bar_button_->setDrawOutlineHighLight(true);
	dual_bar_button_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	dual_bar_button_->drawOutlineHighlight();

	//Creating Pie chart button
	ofxUIRectangle pie_area = ofxUIRectangle(dual_bar_area.getMaxX(), yLocation,
		(ofGetScreenWidth() - xLocation) / 6, (ofGetScreenHeight() - yLocation));
	pie_button_ = new ofxUICanvas(pie_area);
	pie_button_->setColorBack(ofxUIColor(204, 153, 0));
	pie_button_->setFontSize(OFX_UI_FONT_LARGE, 14.5);
	pie_button_->addLabel("     Pie Chart", OFX_UI_FONT_LARGE);
	pie_button_->addButton("Pie Graph", false, 200, 60);
	pie_button_->setDrawOutlineHighLight(true);
	pie_button_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	pie_button_->drawOutlineHighlight();

	//Creating Fontxy chart button
	ofxUIRectangle fontxy_area = ofxUIRectangle(pie_area.getMaxX(), yLocation,
		((ofGetScreenWidth() - xLocation) / 6) + 1, (ofGetScreenHeight() - yLocation));
	fontxy_button_ = new ofxUICanvas(fontxy_area);
	fontxy_button_->setColorBack(ofxUIColor(255, 204, 102));
	fontxy_button_->setFontSize(OFX_UI_FONT_LARGE, 14.5);
	fontxy_button_->addLabel("  FontXY Chart", OFX_UI_FONT_LARGE);
	fontxy_button_->addButton("FontXY Graph", false, 200, 60);
	fontxy_button_->setDrawOutlineHighLight(true);
	fontxy_button_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	fontxy_button_->drawOutlineHighlight();

	//Creating area to display the title
	ofxUIRectangle area_for_title = ofxUIRectangle(0, 0, xLocation, ofGetScreenHeight() / 4);
	title_area_ = new ofxUICanvas(area_for_title);
	title_area_->setFont("fonts/patrick-hand-sc.ttf");
	title_area_->setFontSize(OFX_UI_FONT_LARGE, 48);
	title_area_->addLabel(" Calorie Tracker", OFX_UI_FONT_LARGE);
	title_area_->addSpacer();
	title_area_->setDrawOutlineHighLight(true);
	title_area_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	title_area_->drawOutlineHighlight();

	//Creating area for inputting data
	ofxUIRectangle area_for_adding = ofxUIRectangle(0, area_for_title.getMaxY(), xLocation, (ofGetScreenHeight() / 4) - 100);
	adding_area_ = new ofxUICanvas(area_for_adding);
	adding_area_->setColorBack(ofxUIColor(255, 153, 0));
	adding_area_->setFont("fonts/Cabin-Bold.ttf");
	adding_area_->setFontSize(OFX_UI_FONT_LARGE, 24);
	adding_area_->addLabel("Add Calorie Data", OFX_UI_FONT_LARGE);
	adding_area_->addSpacer();

	//([date],[calories for breakfast],[calories for lunch],[calories for dinner],[expected calories])
	adding_area_->setFontSize(OFX_UI_FONT_MEDIUM, 14);
	adding_area_->setFontSize(OFX_UI_FONT_SMALL, 7);
	adding_area_->addLabel("Input the data in the format with no spaces", OFX_UI_FONT_MEDIUM);
	adding_area_->addSpacer();
	adding_area_->addLabel("[Date],[Calories for Breakfast],[Calories for Lunch],[Calories for Dinner],[Expected Calories]", OFX_UI_FONT_SMALL);
	adding_area_->addSpacer();
	adding_area_->addTextInput("Data Input", "");
	
	adding_area_->setDrawOutlineHighLight(true);
	adding_area_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	adding_area_->drawOutlineHighlight();

	//Creating area for writing goals
	ofxUIRectangle area_for_goal = ofxUIRectangle(0, area_for_adding.getMaxY(), xLocation, ofGetScreenHeight() / 2 - 100);
	goal_area_ = new ofxUICanvas(area_for_goal);

	ofxUIRectangle input_goal_area = ofxUIRectangle(0, 528, xLocation, 27);
	input_goal_ = new ofxUICanvas(input_goal_area);
	input_goal_->addTextInput("Goal Input", "");

	goal_display_.load("fonts/Cantarell-Regular.ttf", 45, true, true);
	goal_title_.load("fonts/Cabin-Bold.ttf", 40);
	goal_description_.load("fonts/Cabin-Bold.ttf", 22);

	//Creating area for blank space
	ofxUIRectangle area_for_coloring = ofxUIRectangle(0, area_for_goal.getMaxY(), xLocation, 200);
	color_area_ = new ofxUICanvas(area_for_coloring);
	color_area_->setColorBack(ofxUIColor(128, 0, 0));
	color_area_->setDrawOutlineHighLight(true);
	color_area_->setColorOutlineHighlight(ofxUIColor(0, 0, 0));
	color_area_->drawOutlineHighlight();
	
	//Creating listeners to see when each button is pressed
	ofAddListener(radar_button_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(line_button_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(multi_bar_button_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(dual_bar_button_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(pie_button_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(fontxy_button_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(adding_area_->newGUIEvent, this, &ofApp::GuiEvent);
	ofAddListener(input_goal_->newGUIEvent, this, &ofApp::GuiEvent);

	//intializing the handlers
	chart_handler_ = new ChartHandler(ofGetScreenWidth(), ofGetScreenHeight());
	data_handler_ = new DataHandler();
	data_handler_->GetContentsFromFile("data/calories/calorie_data.txt");

	goal_string_ = "";
	is_string_drawn_ = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//Writing the title for the goal area
	ofSetColor(255);
	goal_title_.drawString("Goal Area", 0, 485);

	//Writing the title for the goal area
	ofSetColor(255);
	goal_description_.drawString("Set a goal for yourself to help you lose calories!", 0, 520);

	//Displaying the health banner
	banner_.load("images/healthbanner.jpg");
	banner_.setImageType(OF_IMAGE_COLOR);
	banner_.draw(5, 85);

	//Writing the goal the user inputted
	if (is_string_drawn_) {
		ofSetColor(255);
		goal_display_.drawString(goal_string_, 0, 620);
	}

	data_handler_->GetContentsFromFile("data/calories/calorie_data.txt");

	//Displaying the type of graph based on what button the user pushed
	switch (current_state_) {
		case RADARGRAPH:
			chart_handler_->SetUpRadarChart(data_handler_);
			chart_loader_.load("charts/radarchart.jpg");

			break;

		case LINEGRAPH:
			chart_handler_->SetUpLineChart(data_handler_);
			chart_loader_.load("charts/linechart.jpg");

			break;
			
		case MULTIBAR:
			chart_handler_->SetUpMultiBarChart(data_handler_);
			chart_loader_.load("charts/barchart.jpg");

			break;

		case DUALBAR:
			chart_handler_->SetUpDualBarChart(data_handler_);
			chart_loader_.load("charts/dualbar.jpg");

			break;

		case PIEGRAPH:
			chart_handler_->SetUpPieChart(data_handler_);
			chart_loader_.load("charts/piechart.jpg");

			break;

		case FONTXY:
			chart_handler_->SetUpFontXYChart(data_handler_);
			chart_loader_.load("charts/fontxychart.jpg");
			
			break;

	}

	chart_loader_.draw(graph_area_->getMinX(), 0);
}

void ofApp::GuiEvent(ofxUIEventArgs &event) {
	const int kMaxCharcterAmount = 63;
	string event_name = event.widget->getName();

	//Checking to see which button the user pushed
	if (event_name == "Radar Graph") {
		current_state_ = RADARGRAPH;

	} else if (event_name == "Line Graph") {
		current_state_ = LINEGRAPH;

	} else if (event_name == "Multi Bar Graph") {
		current_state_ = MULTIBAR;

	} else if (event_name == "Dual Bar Graph") {
		current_state_ = DUALBAR;

	} else if (event_name == "Pie Graph") {
		current_state_ = PIEGRAPH;

	} else if (event_name == "FontXY Graph") {
		current_state_ = FONTXY;

	} else if (event_name == "Data Input") { //Checking to see if the user is in the Data Input text box
		ofxUITextInput *text_input = (ofxUITextInput *)event.widget;
		std::string data_input = "";

		//When the user presses enter, the user's text will be put into a string
		if (text_input->getInputTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER) {
			data_input = text_input->getTextString();
		}

		if (data_input != "") {
			data_handler_->AddItem(data_input, "data/calories/calorie_data.txt");
		}

	} else if (event_name == "Goal Input") { //Checking to see if the user is in the Goal Input text box
		ofxUITextInput *text_input = (ofxUITextInput *)event.widget;

		if (text_input->getInputTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER) {
			is_string_drawn_ = true;
			goal_string_ = text_input->getTextString();

			//Checks if the goal is short enough. If it is then the program
			//will check if any new lines will be necessary to keep the goal
			//within the area
			if (goal_string_.size() > kMaxCharcterAmount) {
				goal_string_ = "Please input a shorter \ngoal";
			} else {
				goal_string_ = AddNewLines(goal_string_);
			}
		}
	}
}

std::string ofApp::AddNewLines(std::string input) {
	std::string new_input = "";
	std::vector<std::string> words;
	std::stringstream ss(input);

	std::string word = "";

	while (ss >> word) {
		words.push_back(word);
	}

	int char_counter = 0;
	int index_of_vector = 0;

	//Adds a new line whenever the character count of the line exceeds 21
	while (index_of_vector != words.size()) {
		if (words[index_of_vector].size() + char_counter < 21) {
			new_input += words[index_of_vector] + " ";
			char_counter += words[index_of_vector].size() + 1;
		} else {
			new_input += "\n";
			new_input += words[index_of_vector] + " ";

			char_counter = words[index_of_vector].size() + 1;
		}

		index_of_vector++;
	}

	return new_input;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
