// RepeatExam_CA1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MySet.h"
#include "Ordered_Array.h"
#include "Ordered_Array.cpp"
#include <algorithm> 
#include <fstream>      // file stream
#include <string>       // getline(), stoi(), stod()
#include <sstream>      // string stream
#include <string.h> 
using namespace std;

class JJ_leads {
public:
    string firstName;
    string surName;
    string company;
    string number;
};

void parseLine(string& str, Ordered_Array<JJ_leads>& jj);
void InputFileStream(string file, Ordered_Array<JJ_leads>& jj);
void print(Ordered_Array<JJ_leads>& jj);
//void commonData(Ordered_Array<JJ_leads>& jane, Ordered_Array<JJ_leads>& john, Ordered_Array<JJ_leads>& common);
//void unique(Ordered_Array<JJ_leads>& uni, Ordered_Array<JJ_leads>& main, Ordered_Array<JJ_leads>& sub);
void writeFile(string fileName, Ordered_Array<JJ_leads> & jj);

int main()
{
    
    Ordered_Array<JJ_leads> janes_array(250);
    Ordered_Array<JJ_leads> johns_array(250);
    string johnFile = "johns_leads_250.csv";
    string janeFile = "janes_leads_250.csv";
    InputFileStream(janeFile, janes_array);
    InputFileStream(johnFile, johns_array);

    Ordered_Array<JJ_leads> common(500);
    Ordered_Array<JJ_leads> janeUnique(500);
    //commonData(janes_array, johns_array, common);    //i know need to use operator overload to do it, but dont know how to code it
    //unique(janeUnique, janes_array, johns_array);
    //print(janeUnique);
    
    string file = "test.csv";
    writeFile(file, janes_array);


    
}


void parseLine(string& str, Ordered_Array<JJ_leads>& jj) {

    stringstream strStream(str); //create string stream from the string

    JJ_leads input;
    string firstName;
    string surName;
    string company;
    string number;



    try
    {

        getline(strStream, firstName, ',');
        //cout << firstName + "\n";

        getline(strStream, surName, ',');
        //cout << surName +"\n";

        getline(strStream, company, '(');
        if (!company.empty()) {
            company.erase(std::prev(company.end()));   //because company have common so i choose ( instead, then delete the commo after that at the end of string
        }
       // cout << company + "\n";

        getline(strStream, number, ',');
        number = "(" + number;       //since i use the ( as the delimiter up there, so i add back in.
        //cout << number + "\n";

    }
    catch (std::invalid_argument const& e)
    {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const& e)
    {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }

    
    input.firstName = firstName;
    input.surName = surName;
    input.company = company;
    input.number = number;

    jj.push(input);


}

void InputFileStream(string file, Ordered_Array<JJ_leads>& jj) {
    cout << "Reading from comma-delimited text file." << endl;

    string line;
    ifstream inStream(file); // open file as input file stream

    if (inStream.good())  // if file opened successfully, and not empty
    {
        while (getline(inStream, line))   // read a line until false returned , getline() from <string> library
        {
            parseLine(line, jj);
        }

        inStream.close();

        cout << "Successfully Load from Sales File" << endl;
        cout << endl;
    }
    else
        cout << "Unable to open file, or file is empty.";

}

void print(Ordered_Array<JJ_leads>& jj)
{
    for (int i = 0; i < jj.length(); i++)
    {
        string as = jj.getElement(i).firstName;
        cout << as + "\n";
    }
}

//void commonData(Ordered_Array<JJ_leads>& jane, Ordered_Array<JJ_leads>& john, Ordered_Array<JJ_leads>& common) {  //did not work
//    for (int i = 0; i < jane.length(); i++)
//    {
//        for (int e = 0; e < john.length(); e++)
//        {
//            if (jane.getElement[i] == john.getElement[e])
//            {
//                common.push(jane.getElement[i]);
//            }
//            else if (e == john.length() - 1)
//            {
//                common.push(jane.getElement[i]);
//            }
//        }
//    }
//
//    for (int a = 0; a < john.length(); a++)
//    {
//        for (int b = 0; b < jane.length(); b++)
//        {
//            if (b == (jane.length() - 1) && jane.getElement[b] != john.getElement[a])
//            {
//                common.push(john.getElement[a]);
//            }
//        }
//    }
//
//}
//
//
//void unique(Ordered_Array<JJ_leads>& uni, Ordered_Array<JJ_leads>& main, Ordered_Array<JJ_leads>& sub) {  //did not work
//    for (int i = 0; i < main.length(); i++)
//    {
//        for (int e = 0; e < sub.length(); e++)
//        {
//            if (main.getElement[i] != sub.getElement[e] && e == sub.length() - 1)
//            {
//                JJ_leads input;
//                input.firstName = main.getElement(i).firstName;
//                input.surName = main.getElement(i).surName;
//                input.company = main.getElement(i).company;
//                input.number = main.getElement(i).number;
//
//                uni.push(input);
//            }
//            else if (e == john.length() - 1)
//            {
//                common.push(jane.getElement[i]);
//            }
//        }
//    }
//
//}

void writeFile(string fileName, Ordered_Array<JJ_leads>& jj) {
    ofstream MyFile(fileName);

    for (int i = 0; i < jj.length(); i++) {
        string firstname = jj.getElement(i).firstName;
        string surName = jj.getElement(i).surName;
        string company = jj.getElement(i).company;
        string number = jj.getElement(i).number;

        MyFile << firstname << "," << surName << "," << company << "," << number << "\n";

    }


    // Close the file
    MyFile.close();
}