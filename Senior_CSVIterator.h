//
// Created by tshah on 7/18/2016.
//

#ifndef BUILD_KDTREE_CSVITERATOR_H
#define BUILD_KDTREE_CSVITERATOR_H

#include <vector>
#include <string>
#include <sstream>
using namespace std;

class CSVParser{
public:
    vector<vector<float>> parse(string path);
    int getNumFields(string fpath);
};

int CSVParser::getNumFields(string fpath){
    ifstream ifileHandle (fpath);
    string s;
    getline(ifileHandle, s);
    int numFields = 0;
    for(int i = 0 ; i< s.length(); ++i){
        if(s[i] == ',')
            ++numFields;
    }
    return numFields+1;
}

vector<vector<float>> CSVParser::parse(string fpath){
    ifstream ifileHandle (fpath);
    if(!ifileHandle){
        //TODO: Raise exception
        cout << "File not found!" << endl;
    }
    int numFields = getNumFields(fpath);
    vector<vector<float>> dataMatrix;
    while (!ifileHandle.eof())
    {
        vector <float> record;
        for(int i = 0 ; i < numFields; ++i){
            string elem;
            while(true){
                char ch;
                if(ifileHandle.eof()) return dataMatrix;
                ifileHandle.get(ch);
                //cout << ch ;
                if(ch == ',' || ch=='\n' || ifileHandle.eof()) break;
                elem += ch;
                //elem.append(&ch);
            }
            //getline(ifileHandle, elem, ',' );
            istringstream ibuf(elem);
            float f ;
            ibuf >> f;
            record.push_back( f );
        }
        dataMatrix.push_back(record);
    }
    return dataMatrix;
}

#endif //BUILD_KDTREE_CSVITERATOR_H
