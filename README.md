# Flight Route Optimization System (C++)

A C++ graph optimization engine that models airline networks as directed graphs with temporal constraints (departure/arrival timestamps). It solves multi-objective pathfinding queries across cities under strict departure time ($t_1$) and arrival deadline ($t_2$) bounds.

---

## Key Features

* **Time-Constrained Graph Modeling:** Represents cities as graph nodes and flights as directed edges carrying timestamp constraints ($t_1 \le t_{\text{dep}} < t_{\text{arr}} \le t_2$) and fare costs.
* **Least Flights & Earliest Arrival (Task 1):** Uses Breadth-First Search (BFS) to identify the route with the minimum number of hops/transfers, prioritizing the earliest total arrival time.
* **Cost-Optimized Routing (Task 2):** Implements Dijkstra's Algorithm using priority queues (`std::priority_queue` with `std::greater`) to compute the overall cheapest route respecting time windows.
* **Least Flights & Cheapest Route (Task 3):** Performs level-wise queue processing to find the route with minimum transfers while minimizing total travel fare.

---

## Code Base Structure

```text
flight-route-optimization/
├── flight.h       # Flight class definition & comparison operator
├── planner.h      # Planner class declaration & search state structs
├── planner.cpp    # Algorithm implementations (BFS, Dijkstra)
├── main.cpp       # Main driver, test cases, and verification harness
├── test_cases.txt # Dataset and expected test outputs
└── README.md      # Project documentation
