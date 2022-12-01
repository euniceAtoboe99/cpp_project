#include "Airline.h"


//constructor for Airline
Airline::Airline(string &line){
    vector<string> field;
    string fieldword;
    stringstream s(line);
    while (getline(s, fieldword, ',')){
        field.push_back(fieldword);
    }
        Name = stoi(field[0]);
        Alias = field[1];
        IATA = field[2];
        ICAO = field[3];
        Callsign = field[4];
        Country = field[5];
        Active = field[6];
}