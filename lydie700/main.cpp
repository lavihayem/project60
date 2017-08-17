#include <cstdlib>
#include <iostream>
#include <fstream>                      //include library for file processing
#include <cctype>
// #include<iomanip>

using namespace std;

void countSizeOfWord(ifstream &infile);
void countLetter(ifstream &);
void stringWordCount(ifstream &infile);

void print(ifstream &infile);
ifstream infile;


int main(int argc, char *argv[])
{
    string line;
    int stringWordCount1=0;
    infile.open("test6000.txt");   //open the file

    if ( !infile.is_open() )           //check to see if file was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
    }
    countLetter(infile);
    cout<<endl;
    cout << endl << endl;
    infile.close();




    infile.open("test6000.txt");
    stringWordCount(infile);// call function
    //  cout << "Word Count:   " << stringWordCount1<< endl;
    infile.close();                  //close the file

    cout << endl << endl;

    infile.clear();
    infile.open("test6000.txt");
    countSizeOfWord(infile);


     cout << endl << endl;
    infile.close();
    infile.open("test6000.txt");

 print(infile);



    /*   cout << endl << endl;
       infile.close();                      //close the file
       system("PAUSE");
       return EXIT_SUCCESS;
       */

}
void countLetter(ifstream &infile)
{
    char c;
    int i, letter[26];

    for ( i = 0; i < 26; ++i)                                 // initialize array to zero
    {
        letter[i] = 0;
    }


    while (!infile.eof() && (c = infile.get()))             // count the letters
    {
        if (isalpha(c))
        {
            c = toupper(c);
            ++letter[c - 'A'];// let say the c is A so A-A IS 0 so the slat[0] reserved for A and we count how //                              many are there.different senerio let say the 2nd letter is B and B-A is 1 //the                                slot 1 is reserve for B....
        } // end if

    }
    // print the results
    for (i = 0; i < 26; ++i)  // only make 6 colonm
    {
        if (i % 6 == 0)
            cout << endl;
        cout.width(5);
        cout << right << (char) ('A' + i) <<":";
        cout.width(5);
        cout << right << letter[i];
    } // end for
}// end of function


//***************************************2nd way of counting words**************************************
void stringWordCount(ifstream &infile)
{
    int stringWordCount1=0;
    string word;
    infile>>word;
    while(!infile.eof())
    {
        stringWordCount1++;
        infile>>word;

    }
    cout << "Word Count:   " << stringWordCount1<< endl;

}
//*****************************************************************************************************************
void countSizeOfWord(ifstream &infile)
{
    int size,count[10]= {0},wordcount=0;
    string word;
    infile >> word;
    while(!infile.eof())
    {
        size = word.length();
        count[size]++;
        wordcount ++;



        infile >> word;
    }
    for(int j=1; j<=9; j++)
        cout<<count[j]<<endl;
}



void print(ifstream &infile)
{
    int stringWordCount1=0;
    string word;
    infile>>word;
    while(!infile.eof())
    {
        stringWordCount1++;//count the words then being used as 10 in line

            cout.width(10);

        cout<<left<<word;

        if (stringWordCount1 % 10 == 0)
            cout << endl;

        infile>>word;

    }
}

