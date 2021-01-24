# Welcome to DIABETES TRACKER

Dated: 23.01.2021

This project is brought to you by **Atrik Ray**.
As of now, I am a CSE undergrad, expected to graduate by 2023.

It intends to judge a whether a person is 
1. Diabetic or not
2. If diabetic, then whether it is primary or secondary
3. If primary, then whether it is insulin dependent or independent
All these are done interactively based on user inputs.
User inputs are checked. The user is prompted to re-enter in case of invalid input.

This is achieved by a class named diabetes and its member functions.

## REPOSITORY DETAILS
The [Project directory](https://github.com/AtrikGit6174/Diabetes-Tracker/tree/master/Project) contains
1. [DIABETES.cpp](https://github.com/AtrikGit6174/Diabetes-Tracker/blob/master/Project/DIABETES.CPP): The latest version
2. [Images folder](https://github.com/AtrikGit6174/Diabetes-Tracker/tree/master/Project/Images): Sample outputs
3. [Orginal.txt](https://github.com/AtrikGit6174/Diabetes-Tracker/blob/master/Project/Original.txt): The original TurboC++ version
4. [bmi-chart.png](https://github.com/AtrikGit6174/Diabetes-Tracker/blob/master/Project/bmi-chart.png): For bmi values (personal reference)
5. [Colour.png](https://github.com/AtrikGit6174/Diabetes-Tracker/blob/master/Project/Colour.PNG): For console colours (personal reference)

## DISCLAIMER
The program symptoms and analysis are based on a general view
and may not be accurate for every person.
In case you require immediate attention, it is best to
communicate with a professional medical practitioner.

## SYSTEM REQUIREMENTS
* Operating System: Windows 7 or above
(Might be supported for lower versions)
* Compiler: GCC 4 or above, or any other compiler supporting C++11 or above

## IMAGES
Two test cases for reference

### [Secondary Diabetes](https://github.com/AtrikGit6174/Diabetes-Tracker/tree/master/Project/Images/Secondary%20Diabetes)

<img src="Images/Secondary%20Diabetes/1_Welcome%20Screen.PNG" width="300" hight="360">
<img src="Images/Secondary%20Diabetes/2_Personal%20Information.PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/3_Diagnosis%20Window.PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/4_Level%201%20Symptoms%20(1).PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/4_Level%201%20Symptoms%20(2).PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/4_Level%201%20Symptoms%20(3).PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/5_Diabetic.PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/6_Level%202%20Symptoms.PNG" width="300" height="360">
<img src="Images/Secondary%20Diabetes/7_Secondary%20Diabetes.PNG" width="300" height="360">

### [Not Diabetic](https://github.com/AtrikGit6174/Diabetes-Tracker/tree/master/Project/Images/Not%20Diabetic)

<img src="Images/Not%20Diabetic/1_Welcome%20Screen.PNG" width="300" height="360">
<img src="Images/Not%20Diabetic/2_Personal%20Information.PNG" width="300" height="360">
<img src="Images/Not%20Diabetic/3_Diagnosis%20Window.PNG" width="300" height="360">
<img src="Images/Not%20Diabetic/4_Level%201%20Symptoms%20(1).PNG" width="300" height="360">
<img src="Images/Not%20Diabetic/5_Level%201%20Symptoms%20(2).PNG" width="300" height="360">
<img src="Images/Not%20Diabetic/6_Not%20Diabetic.PNG" width="300" height="360">

## CREDITS
1. _Mr Sudarshan Manna_ & _Ms. Tamali Sinha_, for teaching me my first language C++
	and helping code this program.
2. _Sayantani Das_, for her invaluable inputs on the symptoms and cases and 
	for satisfying the curiosity of the Biology lover in me.
3. _Meghna Dutta_, for being the second tester after me and helping me debug.
	She is available @ [https://github.com/Meghna180401](https://github.com/Meghna180401)
4. _Atrik Ray_, that's me, for patiently reading through many, many lines of 
	un-indented skeletal code, making meaning out of it, and changing the
	functions to enhance portability.
5. _YOU_, the reader, for your time and patience and interest!

## ADDITIONAL INFO ABOUT THE PROGRAM
### History
This program was done for my AISSCE 2019 Board Practical Submissions. 
It was built from a skeletal code obtained from the Internet and
modified by my school teachers and me.
The name of my school is mentioned in the program.

However, it was built for **TurboC++ IDE and its associated compiler.**
It used several header files that are unsupported by other environments
and many of its header files have been deprecated in recent C++ standards.

Keeping this in mind, before uploading, I have brought about many changes
to keep the code and program in compliance with latest standards and brought
about many fundamental changes in the conditions and prompts, consulting with 
my friend Sayantani Das, who is an upcoming MBBS.

### New & Noteworthy changes
The header files `<dos.h>`, `<graphics.h>` and associated functions are not supported 
in other environments. 
In view of this, functions like `<textcolor(_attr_)>` were removed and changed to modern 
versions which instruct the Windows console, namely `<system("color _attr_")>`. These attr of the `<system("color")>` can be found in the Colour.png file.

Importantly, the UDF `<gotoxy(const WORD, const WORD)>` function was required to simulate the 
`<gotoxy(int, int)>` function of the MS-Dos Box console.

Credits go to the site: 
* [http://ntcoder.com/bab/2008/08/07/gotoxy-in-a-console-application-in-windows/](http://ntcoder.com/bab/2008/08/07/gotoxy-in-a-console-application-in-windows/)  
for the `<gotoxy(const WORD, const WORD)>` UDF.

The calculation of bmi and age based on a one-time user input was designed, which were absent 
in the original code.

To enhance interactivity and ensure proper output, the option of re-entering the input 
is prompted in case an user enters an invalid character using the functions `<checkInput (char, vector <char>)>` & `<ReEntry (char, int, vector <char>, int)>`.

The function names are quite apt for any other developer to understand and build upon
this code. Justified comments are inserted to help the interested developer.

The `<disclaimer ()>` member function is added to remind the user that this program
is no way as accurate or knowledgeable as a professional medical practitioner.

