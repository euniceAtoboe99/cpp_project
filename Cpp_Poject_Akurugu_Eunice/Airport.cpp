#include "Airport.h"

Airport::Airport(string line){
    vector<string> field;
    while (getline(line, fieldword, ",")){
        field.push_back(fieldword);
    }
        airportId = stoi(fieldword[0]);
        airportName = fieldword[1];
        City = fieldword[2];
        Country = fieldword[3];
        IATA = fieldword[4];
        ICAO = fieldword[5];
        Latitude = fieldword[6];
        Longitude = fieldword[7];
       
        return 0;

    }
