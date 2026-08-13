#include "planner.h"

Planner::Planner(vector<Flight> f_list) {
    flights = f_list;
}

// Task 1: Least flights, then earliest arrival
vector<Flight> Planner::least_flights_earliest_route(int start_city, int end_city, int t1, int t2) {
    queue<SearchState> q;
    q.push({start_city, t1, {}});

    vector<Flight> best_route;
    int earliest_arrival = INT_MAX;
    bool found = false;

    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            SearchState curr = q.front();
            q.pop();

            if(curr.city == end_city) {
                found = true;
                if(curr.current_time < earliest_arrival) {
                    earliest_arrival = curr.current_time;
                    best_route = curr.route;
                }
                continue;
            }

            for(auto f : flights) {
                if(f.start_city == curr.city and f.departure_time >= curr.current_time and f.arrival_time <= t2) {
                    auto next_route = curr.route;
                    next_route.push_back(f);
                    q.push({f.end_city, f.arrival_time, next_route});
                }
            }
        }
        if(found) break;
    }
    return best_route;
}

// Task 2: Cheapest route (Dijkstra)
vector<Flight> Planner::cheapest_route(int start_city, int end_city, int t1, int t2) {
    priority_queue<DijkstraState, vector<DijkstraState>, greater<DijkstraState>> pq;
    pq.push({0, start_city, t1, {}});

    while(!pq.empty()) {
        DijkstraState curr = pq.top();
        pq.pop();

        if(curr.city == end_city) return curr.route;

        for(auto f : flights) {
            if(f.start_city == curr.city and f.departure_time >= curr.current_time and f.arrival_time <= t2) {
                auto next_route = curr.route;
                next_route.push_back(f);
                pq.push({curr.fare + f.fare, f.end_city, f.arrival_time, next_route});
            }
        }
    }
    return {};
}

// Task 3: Least flights, then cheapest route
vector<Flight> Planner::least_flights_cheapest_route(int start_city, int end_city, int t1, int t2) {
    queue<SearchState> q;
    q.push({start_city, t1, {}});

    vector<Flight> best_route;
    int min_fare = INT_MAX;
    bool found = false;

    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            SearchState curr = q.front();
            q.pop();

            if(curr.city == end_city) {
                found = true;
                int total_fare = 0;
                for(auto f : curr.route) total_fare += f.fare;

                if(total_fare < min_fare) {
                    min_fare = total_fare;
                    best_route = curr.route;
                }
                continue;
            }

            for(auto f : flights) {
                if(f.start_city == curr.city and f.departure_time >= curr.current_time and f.arrival_time <= t2) {
                    auto next_route = curr.route;
                    next_route.push_back(f);
                    q.push({f.end_city, f.arrival_time, next_route});
                }
            }
        }
        if(found) break;
    }
    return best_route;
}