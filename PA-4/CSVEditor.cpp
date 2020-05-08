/*
Arturo Villalobos
UIN: 827008236
Sec:503 username: rturovilla
email: rturovilla@tamu.edu
*/
#include "CSVEditor.hpp"

CSVEditor::CSVEditor(string& inputPath, string& rosterPath, string& outputPath, regex expr, int m)
{
    //IMPLEMENT
    this->input.open(inputPath);
    this->roster.open(rosterPath);
    this->output.open(outputPath);
    this->hashTable = new HashTable<string>(m);
    this->regexPattern = expr;
}

CSVEditor::~CSVEditor()
{
	//IMPLEMENT
    this->input.clear();
    this->roster.clear();
    this->output.clear();
    delete this->hashTable;
}

void CSVEditor::readCSVToTable()
{
       string temp;
       smatch match;
       while((getline(input,temp)))
       {
           regex_search(temp,match,regexPattern);
           hashTable->insert(stoi(match.str(1)),match.str(2));
       }
}


void CSVEditor::writeCSVToFile()
{
	//IMPLEMENT
    string temp;
    smatch match;
    while(getline(roster,temp))
    {
        regex_search(temp,match,regexPattern);
        if(hashTable->search(stoi(match.str(1))) == nullptr)
        {
            output << temp << endl;
        }
        else
        {
            string* grades = hashTable->search(stoi(match.str(1)));
            output << temp.erase(temp.size()-2,2) << ","<< *grades<< endl;
        }
    }
}

std::tuple<int, int, double> CSVEditor::getStats()
{
    int maxcl = this->hashTable->maxChainLen();
    int mincl = this->hashTable->minChainLen();
    double avgcl = this->hashTable->averageChainLen();
	return std::make_tuple(mincl, maxcl, avgcl);
}
