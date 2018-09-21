#pragma once

#include "ofMain.h"
#include "chart_handler.h"
#include "data_handler.h"
#include "../addons/ofxUI/src/ofxUI.h"

enum GraphState{
	NONE,
	RADARGRAPH,
	LINEGRAPH,
	MULTIBAR,
	DUALBAR,
	PIEGRAPH,
	FONTXY
};

class ofApp : public ofBaseApp{

private:
	GraphState current_state_ = NONE;
	ChartHandler *chart_handler_;
	DataHandler *data_handler_;

	ofxUIRectangle *graph_area_;
	ofxUICanvas *title_area_;
	ofxUICanvas *adding_area_;
	ofxUICanvas *goal_area_;
	ofxUICanvas *color_area_;

	ofxUICanvas *radar_button_;
	ofxUICanvas *line_button_;
	ofxUICanvas *multi_bar_button_;
	ofxUICanvas *dual_bar_button_;
	ofxUICanvas *pie_button_;
	ofxUICanvas *fontxy_button_;

	ofImage chart_loader_;
	ofImage banner_;

	bool is_string_drawn_;
	ofTrueTypeFont goal_title_;
	ofTrueTypeFont goal_display_;
	ofTrueTypeFont goal_description_;
	std::string goal_string_;
	ofxUICanvas *input_goal_;
	
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void GuiEvent(ofxUIEventArgs &event);
		std::string AddNewLines(std::string input);
};
