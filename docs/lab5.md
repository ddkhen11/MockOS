# CSE 332 Lab Base

Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Names: Malcolm Newmark, Adam Shumway, Daniel Khen
Lab #: 5

Document your lab work here according to the lab specification
1. For this command, we use the getFileNames function from the AbstractFileSystem member variable in order to print 
   out all the file names if "ls" is called. If "ls -m" is called, we use the MetadataDisplayVisitor to display the 
   metadata of each file in the file system. We gain access to the pointer to each file in the file system by 
   opening the file with the file system and then closing the file when we're done displaying it.
# FIX MetadataDisplayVisitor.cpp
2. For this command, we use the deleteFile function from the AbstractFileSystem member variable to delete
   the files entered along with the "rm" input.
3. For this functionality, we changed the execute function in TouchCommand.cpp so that if -p is added to the end of 
   the touch command, it prompts the user to create a password and makes a PasswordProxy with the file it already 
   initially created. Then, it adds either the PasswordProxy of the initially created file or just the initally 
   created file to the file system. 
4. Implementing cat command:
   We started this command by making CatCommand a ConcreteCommand object of the command pattern. We implemented the 
   interface of AbstractCommand. For the displayInfo method, we outputted that the cat command would work to display 
   and append contents to a file. For the execute method, we read in the program name and information from the user, 
   and if the input is to be displayed, the program will write out the input, if the user adds a '-a', then the 
   input will be appended onto the file. The execute method ends by closing the file. 
5. Implementing the display command:
   We started this command by making DisplayCommand a ConcreteCommand object of the command pattern. We implemented 
   the interface of AbstractCommand. For the displayInfo method, we outputted that display command displays the 
   contents of a file. For the execute method, we read in the program name and information and if the user added a 
   '-d' we displayed the contents of the file. This execute method ends by closing the file.
6. I implemented the prototype pattern by adding a virtual clone method to AbstractFile which takes in a string as a 
   parameter. Every implementation of this method in every concrete class returns a pointer to a copy of that object 
   with the string parameter as its name. 
7. Implementing the Macro command:
   We started this command by making MacroCommand a ConcreteCommand object of the command pattern. We implemented
   the interface of AbstractCommand. For the displayInfo method, we outputted that macro command creates new 
   commands out of existing commands. For the execute method, if the number of commands was the same as the number 
   of inputs, it executes each command with the corresponding parsed input, and then checks to see if each was 
   successful. This execute method ends by closing the file. The addCommand and setParseStrategy methods were also 
   added as public to the class; addCommand pushed back an inputted command onto the vector of AbstractCommands, 
   setParseStrategy took an inputted parsing strategy as a parameter and set it equal to the original parse strategy.

   