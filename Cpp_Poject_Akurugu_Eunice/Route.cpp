
#include "Route.h"
//constructor for Route
Route::Route(string line){
    vector<string> route_fields;
    while (getline(line, fieldword, ",")){
        route_fields.push_back(fieldword);
    }
        AirlineID = stoi(fieldword[0]);
        startAirport = fieldword[1];
        startAirportID = stoi(fieldword[2]);
        goalAirport = fieldword[3];
        goalAirportID = stoi(fieldword[4]);
        Codeshare = fieldword[5];
        Stops = stoi(fieldword[6]);
        Equipment = fieldword[7];
        return 0;

    }