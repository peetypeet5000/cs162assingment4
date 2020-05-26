#include "file_io.h"
using namespace std;


//reads art from file, uses the cases to know where to start
void readAsciiArt(int selection) {
    int dist, move;
    switch(selection) {
        case 1:
            dist = 14;
            move = 2;
            break;
        case 2:
            dist = 74;
            move = 18;
            break;
        case 3:
            dist = 66;
            move = 94;
            break;
        case 4: //jordan
            dist = 41;
            move = 163;
            break;
        case 5: //pit
            dist = 48;
            move = 205;
            break;
        case 6: //bats
            dist = 53;
            move = 254;
            break;
        case 7: //sign
            dist = 52;
            move = 311;
            break;
        case 8: //wum
            dist = 60;
            move = 365;
            break;
        case 9: //died
            dist = 52;
            move = 429;
            break;
        case 10: //gold
            dist = 51;
            move = 485;
            break;
        case 11: //exit
            dist = 53;
            move = 539;
            break;
    }

    //moves cursor to correct locaation
    ifstream fin("bft.txt");
    changeLine(fin, move);

    //actually print
    if(fin.is_open() == true) {
        string str;
        for(int i = 0; i <= dist; i++) {
            getline(fin, str);
            cout << str << "\n";
        }
    } else {
        cerr << "Error opening file (file_io.cpp)\n\n";
    }
    fin.close();
}


//credit:
//stackoverflow.com/questions/5207550/in-c-is-there-a-way-to-go-to-a-specific-line-in-a-text-file
ifstream& changeLine(ifstream& fin, int lines){
    fin.seekg(ios::beg);
    for(int i=0; i < lines - 1; ++i){
        fin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return fin;
}


//Just makes user enter ENTER so that they can read before continuing
void pressSpace() {
	std::string input = " ";
    std::cout << "\n\n*press ENTER to continue...*\n";
	std::getline(cin, input);
}

