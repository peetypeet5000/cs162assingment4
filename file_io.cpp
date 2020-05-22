#include "file_io.h"
using namespace std;


void readAsciiArt(int selection) {
    int dist, move;
    switch(selection) {
        case 1:
            dist = 15;
            move = 1;
            break;
        case 2:
            dist = 74;
            move = 18;
            break;
        case 3:
            dist = 66;
            move = 94;
            break;
        case 4:
            dist = 41;
            move = 163;
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

