/**
Author1: Joseph Akurugu Avoka(akurugu.avoka@aucampus.onmicrosoft.com)
Author2: Eunice Atoboe Atabem
Date:    01/12/2022
Course:  Intermediate Computer Programming
Instructor:  Professor Robert Sowah


This code produces a route containing a series of Airports, routes, an Airlines from a given start Airport to an end goal Airport.
It takes a text file input containing the search query and returns an output text file containing the solution route.
*/

#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include "Airline.cpp"
#include "Route.cpp"
#include "Airport.cpp"
using namespace std;

vector<vector<string>>  find(vector<string> Searchkeys, vector<int> SearchIndex,const  string &filename);
bool IsExplored(const vector<string> &ExploredSet, const string &AirportName);
vector<Airport> SolutionRoute(const string& fileName);
string printSolution(vector<Airport> solutionSet);
int main(){

    printSolution(SolutionRoute("Accra_Helsinki.txt"));
}


/**
Function   : Distance

Description: Calculates the distance between two Airports using the Haversine Formula

Parameters : Start    - An airport object of the start Airport
             goal    - An airport object of the goal Airport

Return     : the float value of the distance between both Airports
 */

float distance(const Airport& Start,const Airport& goal)
{
    float pi = 3.14159265359;
    float lat1 = Start.getLatitude()* (pi / 180);
    float lon1 = Start.getLongitude()* (pi / 180);
    float lat2 = goal.getLatitude()* (pi / 180);
    float lon2 = goal.getLongitude()* (pi / 180);

    float earthRadius = 6371.01; //Kilometers

    float distance = earthRadius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
    return distance;
}
/**
Function   : find

Description: This function takes a csv file, search keys, and search indices,
 sarches through the csv files and returns all the rows which have the given searchkeys.

Parameters : Searchkeys - these are strings which are keys for identifying a particular row within the csv file
             SearchIndex - the index at which each of the Search keys are located within the csv file
             filename - the name of the csv file that is being queried

Return     : returns the solution route as an a vector of string vectors containing all matching entries in the csv file.
 Each matching entry is a string vector at index i of the return output
 */

vector<vector<string>>  find(vector<string> Searchkeys, vector<int> SearchIndex, const string& filename){
    vector<vector<string>> results;// This vector will be returned. It contains all string instances which fulfil the given condition
    fstream query;
    query.open(filename);

    string line;
    while(query.peek()!=EOF){ //while not end of the file
        int count = 0;
        getline(query, line); //get line
        vector<string> fields;
        stringstream s(line);
        string fieldword;
        while (getline(s, fieldword, ',')){
            fields.push_back(fieldword);
        }
        for (int i = 0; i<Searchkeys.size();i++){ // for each element in the SearchKey
//            cout<<SearchIndex[3]<<endl;
            if (Searchkeys[i] != fields[SearchIndex[i]]){  // if not in string break from for loop
                break;
            }
            else if (Searchkeys[i] == fields[SearchIndex[i]]){// if in string increment count by one
                count++;

                if (count == Searchkeys.size()){// if count is equal to the size of Searchkeys, print out line
                    /** Assumption: count would be equal to the size of Searchkeys if all the elements in Searchkeys can be found in the string*/
                    stringstream s(line);
                    string word;
                    vector<string> fields;
                    while (getline(s, word, ',')) {
                        fields.push_back(word);
                    }
                    results.push_back(fields);
//                    count = 0;//reset counter back to 0 to search for next instance
//                    cout<<line<<endl;
                    break; // Break out of while loop into for loop
                }
            }
        }
    }
//    cout<<"reached end of file";
    return results;
}


/**
Function   : SolutionRoute

Description: This function produces a route containing a series of Airports, routes, an Airlines from a given start Airport to an end goal Airport.
It takes a txt file input containing the search query and returns an output text file containing the solution route.

Parameters : fileName - takes the name of the file containing the query as a string

Return     : returns the solution route as an Airport object vector.
 */

 vector<Airport> SolutionRoute(const string& fileName) {
     fstream requestfile;
     requestfile.open(fileName);
     vector<string> Request;
     vector<string> temp;


     string line, word;
     while(requestfile.peek()!=EOF){
         getline(requestfile, line);
         stringstream stream(line);
         while (getline(stream, word, ',')) {
             Request.push_back(word);
         }
     }
     vector<Airport> solutionSet;
     Airport Start(find({Request[0], Request[1]}, {2, 3}, "airports.csv")[0]);
     vector<string> ExploredSet;

     vector<vector<string>> goalSet  = find({Request[2], Request[3]}, {2, 3}, "airports.csv");
     vector<vector<string>> goals;
     for(int i = 0; i<goalSet.size();i++){
         try {
             goals = find({goalSet[i][0]}, {5}, "routes.csv");
             if (!goals.empty()){
                 break;
             }
         }catch(exception &e){e.what();}

     }
     Airport goal(find({goals[0][5]}, {0}, "airports.csv")[0]);
     solutionSet.push_back(Start);
     Airport State = Start;
     cout<<State.getAirportName()<<endl;

     ;
    int count  = 0;
     while (State.getAirportName() != goal.getAirportName()) {
         vector<vector<string>> Transitionmodel = find({to_string(State.getAirportId())}, {3},"routes.csv");//all routes where the source Airport is state.AirportID
         count  = 0;
         for (auto & i : Transitionmodel) {
             vector<vector<string>> Entry = find({i[5]}, {0}, "airports.csv");

             if (Entry.empty()){
                 continue;
             }
//             count++;
             Airport node(find({i[5]}, {0}, "airports.csv")[0]);



////        # if node is the destination airport:
             if (node.getAirportName() == goal.getAirportName()) {
                 cout<<node.getAirportName()<<endl;
                 cout << "Found Solution!" << endl;
                 solutionSet.push_back(node);
                 return solutionSet;
             }
             else if ( distance(node, goal) < distance(State, goal)) {
                 State = node;
                 continue;
             }
         }


         solutionSet.push_back(State);
         cout<<State.getAirportName()<<endl;
     }
     return solutionSet;
 }


/**
Function   : printSolution

Description: Writes the solution route unto an output txt file

Parameters : solutionSet - takes the solutionSet as an Airport Object vector


Return     : the filename of the output file as a string
 */
 string printSolution(vector<Airport> solutionSet){
     string filename = solutionSet[0].getCity() + "_" + solutionSet[solutionSet.size()-1].getCity() + "_output.txt";
     ofstream solutionfile( filename);
     int stops;
     for ( int c = 0; c< solutionSet.size()-1;c++){
         vector<string> routeEntry =  find({to_string(solutionSet[c].getAirportId()),to_string(solutionSet[c+1].getAirportId())},{3,5},"routes.csv")[0];
         Route solutionRoute (routeEntry);
         solutionfile<<to_string(c+1) + ". " + solutionRoute.getAirline() + " from "+ solutionRoute.getstartAirport() + " to " +  solutionRoute.getgoalAirport() + " " +
         to_string(solutionRoute.getStops())+ " stops\n";
         stops = stops + solutionRoute.getStops();
     }
     solutionfile<<"Total flights: " + to_string(solutionSet.size()-1) + "\n";
     solutionfile<<"Total Additional Stops: " + to_string(stops);
     solutionfile.close();
     return filename;

}


