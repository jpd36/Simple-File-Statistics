1.[30pt] Simple File StatisticsWrite a program that will process one or more files and print out various statistics for these files. Thefile names should be provided via command-line arguments or the program will simply use stdio streamto get input (if there are no command-line arguments).If the user does not provide any command line arguments, the input should be read from the stdiostream instead of a standard file. If the user provides one or more command-line arguments, the pro-gram should process files with the names provided by command-line arguments one by one, and printout statistics for each file separately. If more files are processed, summary statistics should also beprinted out.

The program should report the following statistics about each file (also summary statistics if multiplefiles are processed):

i) Number of characters in the file.
ii) Number of lines in the file (i.e. number of newline characters).
iii) Number of words in the file. A word is a sequence of any characters except for the space,newlineor tabulator characters not separated by these characters. Therefore, in a string "This isthefirst line\nThis\t\this the 2nd"we wouldhave 9 words (\n and \tarethe specialcharacters).

The program will be similar to the wccommand provided in Linux(test it to get an idea). I’d suggest touse the functions defined in ctype.h. For example, isspaceis a good function to identify white spaceand distinguish it from the rest (other characters form words).

2.[70pt] Account Management SystemWrite a menu-driven, interactive program for managing bank accounts. All account information shouldbe stored in a binary file accounts.dat. Your data file accounts.datshould contain at least 7different customers when you submit this assignment. You can limit the maximum number of accounts in thebank by 50. You may store all accounts in memory (as an array), which should simplify most operations, but any change  on any account should be  immediately reflected  in the  data file (accounts.dat)not only on exit.

For each customer, the data file should store the following fields (you decide on reasonable datatypes):

•First name
•Middle initial
•Last name
•Account number (any 6-digit number)
•Account balance
