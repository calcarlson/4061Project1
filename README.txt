/*test machine: LIND40-40
date: 02/20/20
name: Nam Trinh, Cal Carlson, Jessica Cunningham
x500: trinh064, carl5362, cunni536
*/

The purpose of our program is to create a dependency graph based on an input file, then execute the commands stored within the dependency graph using depth first search.

The program is compiled using a make file. The command "make main.o" will compile all the necessary files for this to function properly.

First, our program takes a text file as an input in the main.c file and reads the number of nodes as an integer. The command arguments are put into a character array, and the parent-child relationships are stored in an integer array. These arguements are then passed to the graph.c file, where the graph is created. This graph is then entered into depth first search, where the order of execution is decided. Next, the output file is created and the process IDs, parent process IDs, and commands are printed into the file in the order they were executed in.

When programming this project, we assumed that all possible inputs would be of the same format as input1.txt (first number of nodes, then commands, then parent-child relationships).

Team Members:
Nam Trinh: trinh064
Cal Carlson: carl5362
Jessica Cunningham: cunni536

Contributions:
Nam - graph.c, debugging
Cal - main.c, debugging
Jessica - README file, help with graph.c, debugging
