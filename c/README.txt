Instructions:

1) compile the program by typing 'make'.
1.1) if any errors occur, type 'make clean' and try instruction 1) again.

2) for help on how to run the program, run ./queue --help
2.1) There are 2 flags to be set:
     -f FILENAME.txt | reads queue from a file, each element must be separated by either a space or a newline.
     -s SIZE | sets the maximum size of the queue to the number after the flag.
2.2) If no flags are set, the program will prompt the user to input the maximum size of the queue.

3) Once the program is running, the user has 4 options.
3.1) 1 - Enqueue (note: user must type '1' to access the option) 
     2 - Dequeue (note: user must type '2' to access the option)
     3 - Print Queue (note: user must type '3' to access the option)
     4 - Exit (note: user must type '4' to access the option)

4) Currently, there are no safety checks for wrong data input by the user, so please be considerate and type in your data carefully.

Please refer further questions to hector.cardenas@rochester.edu
