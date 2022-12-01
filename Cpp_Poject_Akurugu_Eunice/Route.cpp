#include "Route.h"


//constructor for Route
Route::Route(vector<string> &route_fields){

        Airline = route_fields[0];
    try {
        AirlineID = stoi(route_fields[1]);
    }catch(const exception& e){
        AirlineID = 0;}
        startAirport = route_fields[2];
        try {startAirportID = stoi(route_fields[3]);
    }catch(const exception& e){
            startAirportID = 0;}
        goalAirport = route_fields[4];
            try {goalAirportID = stoi(route_fields[5]);
    }catch(const exception& e){
                goalAirportID = 0;}
                try {Stops = stoi(route_fields[6]);
    }catch(const exception& e){
                    Stops = 0;
    }
}