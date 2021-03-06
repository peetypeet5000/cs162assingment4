#ifndef FILEIO
#define FILEIO

#include <string>
#include <iostream>
#include <fstream>
#include <limits>

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

//credit: https://stackoverflow.com/questions/9158150/colored-output-in-c/9158263


using namespace std;

void readAsciiArt(int);
ifstream& changeLine(ifstream&, int);
void pressSpace();

#endif