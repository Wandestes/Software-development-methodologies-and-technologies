# Software-development-methodologies-and-technologies

This is console application for solving quadratic equations with the ability to read local files.
- Made by student

## Instruction:

# First step

Firstful u need to download Visual studio if u want download all my project or u can just go into [Software-development-methodologies-and-technologies/ConsoleApplication1/ConsoleApplication1
/ConsoleApplication1.cpp] and copy text from cpp file for your compiler

# Second step

Second one u need to create txt file, write there 3 numbers (For windows it would be like that: 2 5 -2, dw u can find example there --> [Software-development-methodologies-and-technologies/ConsoleApplication1/x64/Debug/Test.txt]) and change file path in code:

####  Code: {
    void fileMode(){    
      ifstream file;
      file.open("C:\\Users\\Wandestes\\source\\repos\\ConsoleApplication1\\x64\\Debug\\Test.txt");  <-- There 
      if (!file) {
          cout << "File does not exist or cannot be opened." << endl;
          exit(1);
      }
    }
}



Or if use my second code and u could make it from cmd like this:

- Select mode:
- 1. Interactive mode
- 2. File mode
- Your choice: 2
- Enter file path: C:\\Users\\Wandestes\\source\\repos\\ConsoleApplication1\\x64\\Debug\\Test.txt <-- ***There u write urs file location***
- Equation is: (2) x^2 + (1) x + (-3) = 0 <-- ***And how u see program read file and continue func.***
- There are 2 roots
- x1 = 1
- x2 = -1.5

## Thanks for reading this i hope it helps u 😊


