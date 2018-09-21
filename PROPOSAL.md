# Project Proposal

My final project will be a Calorie tracker. When the user opens up the application, there will be a title screen, which after that will
display the user's current information about his or her caloric intake. The main screen will contain a visualization of the caloric intake from the past
week on the right side of the screen, where the user can hover over to see what foods he or she has eaten during those days. On the left side of the screen,
the user can see any goals that he or she set for themselves. Below the goals, there will be a rectangle area, which will display how well the user is doing in 
terms of consuming calories. The user will be able to keep track of what foods he or she eats everyday, 
and the application will show through different visualizations of the number of calories consumed and also the nutritional values consumed. The 
user can also create different meal plans to control their caloric intake and save them within the database. Also, the user can input food data through files that the database can read. Along with that, users can also set limits to how many calories to consume.

I will be using either [mongodbc++](https://github.com/mongodb/mongo-cxx-driver) or [sqlitec++](https://github.com/SRombauts/SQLiteCpp) to keep track of all the data of the different foods. ~~Mongodbc++ and sqlitec++ are both data base libraries that can be used to create public domains to hold information. I will try to obtain a file of nutritional values of common foods for the user to pick from. However, if the user wants to add their own foods, the user can feed files to thesedatabases for them to process through and be shown in the application. Both of these database libraries should have the capabilities for me to accomplish 
this task.~~ Neither of these databases worked on my laptop, so instead of using
an actual database, I will instead be manually holding the data using standard
fin and fout.

~~To show the visualizations of one's calorie intake, I will be using [VTK](https://www.vtk.org/). VTK has many different features, such as modeling and 
3D-graphics, but I will mainly be utilizing its 2D graphs and visualization capabilities.~~ I decided to use ChartDirector instead because it has all the utilities that I need for the project and it actually works on my laptop. Showing the one's caloric consumption can be shown through a 2d graph with different shading to show if the whether the user has consumed too many or too little calories in one day. Other aspects of the application, such as the interface, will be built through openframeworks addons such as ofxGui and ofxUI.

I have basic knowledge of SQL, so I have experience dealing with databases. Fortunately both mongodbc++ and sqlitec++ have a lot of resources and 
guides for me to understand how to utilize these libraries. For the visualization, I have used matplotlib in python and I believe that VTK has
similar capabilities to it.

