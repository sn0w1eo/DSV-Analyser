//
// Created by Sn0w1eo on 07.12.2017.
//
#include "DSV_Analyser.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
//    string filename = R"(D:\Trash\csv_files\10Million.csv)";
    string filename = R"(D:\Trash\csv_files\sample.csv)";

    cout << "ANALYSE STARTED..." << endl;
    clock_t start = clock();
    DSV_Analyser obj(filename.c_str() , ',', '.' );
    obj.Analyse(true);
    clock_t finish = clock();
    double elapsed_time = double(finish-start)/1000;
    cout << "TIME ELAPSED IN SEC: " << elapsed_time << endl;

    cout << "STATISTICS:" << endl;
    cout << "Total Columns:" << obj.Columns.size();
    for (int i=0; i < obj.Columns.size(); i++) {
        cout << "TITLE: " << obj.Columns[i].Title << setw(10) << "LENGTH: " << obj.Columns[i].Length << "TYPE: ";
        if (obj.Columns[i].Type & 1) {
            cout << "Text";
        } else if(obj.Columns[i].Type & 2) {
            cout << "Number";
        } else if(obj.Columns[i].Type & 4) {
            cout << "Double";
        } else {
            cout << "Undefined";
        }
        cout << endl;
    }
    cout << endl;
}
