# Setting up Visual Studio Project to use SFML
## Visual Studio 2015/2017

1. Download SFML 2.4.2 version - "Visual C++ 14(2015) - 32-bit" at https://www.sfml-dev.org/download/sfml/2.4.2/
2. Extract the SFML zip file and keep note of where it's located
3. Create a new project in visual studio or use one of the examples provided
4. Right click on your project in the Solution Explorer(tab on left or right side) and click "Properties"
5. Change the configuration on the top left to "All Configurations"
6. In the Solution Explorer click the drop down menu on "C/C++" -> "General"
7. For "Additional Include Directories" navigate to your SFML folder and within it there is an include folder, select that.
8. Make sure you hit "Apply" or "Ok" after every change it undoes and change you make it you switch tabs
9. In the Solution Explorer click the drop down menu on "Linker" -> "General"
10. For "Additional Library Directories" navigate to your SFML folder and select the lib folder with it
11. On the left now hit the drop down menu for Linker again and select "Input"
12. Click on additional dependencies and add "sfml-windows.lib", "sfml-system.lib", "sfml-graphics.lib" excluding the quotes/commas and each on sperate lines.
14. Make sure that to the left of the run button(green play button on toolbar) is the build platform is set to "x86" and NOT "x64"
13. Lastly go into your SFML folder and navigate to the bin folder, copy all the .dll files into and
paste them into the "Debug" and "Release" folder located in your project directory, If you don't have these folders try running the sfml example and one of them should be generated depending
on what mode("Debug" or "Release") you're in
