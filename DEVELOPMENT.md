# Development for CalorieTracker

# April 15
* Installed sqlite3c++ into my project

# April 16
* sqlite3c++ didn't work, trying to fix the error

* Using this [website tutorial](https://dcravey.wordpress.com/2011/03/21/using-sqlite-in-a-visual-c-application/) on installing sqlite3c++
but still isn't working.

* Trying to install VTK using cmake files. Used this [video tutorial](https://www.youtube.com/watch?v=IgvbhyDh8r0) to install VTK, but so far
I am still getting errors

* Might try out Chart Director instead, since it seems easier to install 
and has the capabilities that I need.

* Attempting to outline the interface of CalorieTracker

* Got Chart Director to run on visual studio with the provided examples.
Just need to get it running on my solution file.

# April 17

* Added the ofxDatGui addon to openframeworks

* Got the ofxDatGui examples; want to use the dropdown menus from this
library

* trying to get the ofxDatGui to work on my project, but currently isn't happening.

# April 18

* adding implmentation to add what you eat during different times of the day, 
such as for lunch and dinner

# April 21

* attempting to install mongodb c driver. Not having any success right now

* installed the mongodb softwore onto my computer perfectly fine

* planning to add more visualizations of calorie consumption since it seems like
I won't be having mongodbc++ installed anytime soon

# April 22

* Figuring out how to create the interface using ofxGui and ofxDatGui

* Found an addon called ofxUi that may be better suited for my project

* Deciding on other ways to hold data without mongodb and sqlite3

# April 23

* Using ofxUi to create the canvas to put my graphs in and buttons to choose which
graph to show

* started creating buttons to switch from each graphs, staring to create the graphs

* got the graph buttons to work, where if you click a button, the specific graph will show up

* finished writing code for 4 of the graphs

# April 24

* planning to work on the data handler using std fin and fout rather than the databases

* finished writing the data handler

* started to decide the color palettes and fonts for the application

# April 27

* started to work on the data input for the application

* connected the DataHandler to the ChartHandler

# April 30

* Finished coding the ChartHandler to use the DataHandler's data now

* Got the data input to work

* Finished writing the code to add a goal to the application

# May 1

* Started customizing the charts

* began to comment the code for the chart handler

# May 2

* commented the code for the data handler

* edited some of the other comments in the code