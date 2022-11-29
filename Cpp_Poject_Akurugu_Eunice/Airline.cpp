#include "Airline.h"
//constructor for Airline
Airline::Airline(string line){
    vector<string> field;
    while (getline(line, fieldword, ",")){
        field.push_back(fieldword);
    }
        airlineName = stoi(fieldword[0]);
        Alias = fieldword[1];
        IATA = fieldword[2];
        ICAO = fieldword[3];
        Callsign = fieldword[4];
        Country = fieldword[5];
        Active = fieldword[6];
        return 0;
}  