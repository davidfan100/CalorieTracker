# Calorie Tracker
Calorie Tracker is an application used to help people visual their caloric intake
so see if they need any changes to their current diet. The user will have 6 different visualizations to see their caloric intake. The user can also add
data in the specified format and also write goals for themselves, which will
be displayed on the application.

# Getting Started for Windows Users
## Prerequisites

* The lastest version of [Visual Studio](https://www.visualstudio.com/downloads/) (**Install the Windows 8.1 SDK when installing VS**)
* The most recent release of OpenFrameworks(http://openframeworks.cc/download/) 
(the openframework folder should be called something like of_v0.9.8_vs_release)
* Calorie Tracker, which you can just download from the github

### Download the following addons and libraries for this project
* [ofxUi](https://github.com/rezaali/ofxUI)
* [ofxXmlSettings](https://github.com/openframeworks/openFrameworks/tree/master/addons/ofxXmlSettings) (if it isn't already installed)
* [ChartDirector](http://www.advsofteng.com/download.html) (download this 
if for some reason your computer isn't recognizing it. Chartdirector should
already be within the project)

### Installing addons
* To install the addons, obtain the src file from ofxUI and ofxXmlSettings,
create a folder (call it the name of the addon | ex: ofxUI) within the addon folder of the openframework folder, and add the src file to the respective folders.

## Setting up the project in Visual Studio
1. In the openframeworks folder, there should be a folder that says project generator. Click on it and open the project generator. Click import and find where you
downloaded the Calorie Tracker folder. Click update

2. Open the Calorie Tracker Solution file. Now right click on the soultion file in the solution explorer and click **retarget solution**. Change the windows sdk version
to 8.1 and click **OK**.

3. Go to the top left of Visual Studio and find the project dropdown button. In the dropdown,
click on Calorie Tracker properties.

3. In **Configuration Properties->General**, find the **Use of MFC** tab and change
it to **Use MFC in a Shared DLL** (you can just click the box until you see the setting you want)

4. Now, go to **Linker->Input** and find the Additional Dependencies area. Click on the box and an arrow should appear. Click the arrow and click edit. Input where
the chartdir60.lib is located. For instance for me, mine is located in 
C:\Users\df100\source\of_v0.9.8_vs_release\apps\myApps\final-project-davidfan100\CalorieTracker\lib32\chartdir60.lib (an easy way to find the location is 
to go to the location of the file and then clicking the area which shows you where you are) 
**Remember to also put the location in double quotes or else Visual Studio will not recognize it**

5. After that, click the **Local Windows Debugger**, and see if it runs

# Using the application
* To use the data input, you must put the data in the specified format with no spaces or else the program may run into some problems. Later on,
I hope to install a real database for users to input their data.

* To use the goal area, type something in the text area, and it will either display it on the screen, or will tell you that you need to write a shorter
goal. 

* To see all the graphs, click the button of the type of graph that you want to see.

* If you want to remove data, you will have to go into **bin/data/calories/calories.txt** and delete the data manually
**Remember to remove the new line after your last entry**

# Built With
* [OpenFrameworks](http://openframeworks.cc/) - the C++ framework used


# Sources
[Picture of Banner](http://www.activehealthywell.com/slide/lifemed-banner/)