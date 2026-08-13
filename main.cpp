#include <bits/stdc++.h>
#include "planner.h"
using namespace std;

bool compare_routes(vector<Flight> r1, vector<Flight> r2) {
    if(r1.size() != r2.size()) return false;
    for(int i = 0; i < r1.size(); i++) {
        if(!(r1[i] == r2[i])) return false;
    }
    return true;
}

int main() {
    vector<Flight> flights = {
        Flight(0, 0, 0, 1, 30, 50),
        Flight(1, 0, 0, 3, 80, 200),
        Flight(2, 1, 40, 2, 60, 20),
        Flight(3, 1, 50, 2, 100, 120),
        Flight(4, 2, 120, 4, 200, 100),
        Flight(5, 3, 100, 4, 150, 500),
        Flight(6, 3, 100, 4, 250, 300)
    };

    Planner flight_planner(flights);

    vector<Flight> route1 = flight_planner.least_flights_earliest_route(0, 4, 0, 300);
    vector<Flight> route2 = flight_planner.cheapest_route(0, 4, 0, 300);
    vector<Flight> route3 = flight_planner.least_flights_cheapest_route(0, 4, 0, 300);

    vector<Flight> expected_route1 = {flights[1], flights[5]};
    vector<Flight> expected_route2 = {flights[0], flights[3], flights[4]};
    vector<Flight> expected_route3 = {flights[1], flights[6]};

    if(compare_routes(route1, expected_route1)) cout << "Task 1 PASSED\n";
    if(compare_routes(route2, expected_route2)) cout << "Task 2 PASSED\n";
    if(compare_routes(route3, expected_route3)) cout << "Task 3 PASSED\n";

    return 0;
}