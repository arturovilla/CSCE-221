/*
 Arturo Villalobos
 UIN: 827008236
 Sec:503 username: rturovilla
 email: rturovilla@tamu.edu
 */
 
#include <string>

#include <regex>

#include "HashTable.hpp"
#include "CSVEditor.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    regex expr(".*,.*,(.*),(.*)");

    string inputPath = "./input.csv";
    string rosterPath = "./roster.csv";
    string outputPath = "./output.csv";

	int m = 0;
    string line;
    ifstream file("roster.csv");
    while (getline(file, line))
    {
        m+=1;
    }
    file.clear();
    file.close();
    m=2;

	//OBTAIN M HERE

    CSVEditor editor(inputPath, rosterPath, outputPath, expr, m);
    editor.readCSVToTable();
    editor.writeCSVToFile();

	std::tuple<int, int, double> stats = editor.getStats();

	cout << "minimum chain len = " << std::get<0>(stats) << endl;
	cout << "maximum chain len = " << std::get<1>(stats) << endl;
	cout << "average chain len = " << std::get<2>(stats) << endl;
    
//    HashTable<string> mht (40);
//
//    pair<string, int> myp ("75",827008236);
//
//    mht.insert(827008236, "75");
//    list<pair<string,int>> cnt = mht.mtable[827008236%mht.size];
//
//    string* mystring = mht.search(827008236);
//
//
//    //cout<<get<0>(cnt.front())<<endl;
//    cout<<*mystring<<endl;
	
    return 0;
}
