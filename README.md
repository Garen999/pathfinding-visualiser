# C++ Pathfinding Visualiser

A console-based pathfinding visualiser developed in C++ that uses **Breadth-First Search (BFS)** to find the shortest path through a randomly generated grid containing obstacles.

This project explores graph traversal, data structures and shortest-path algorithms through an independently implemented C++ application.

## Features

- **Breadth-First Search (BFS):** Searches a grid using a first-in, first-out (FIFO) queue.
- **Shortest-path reconstruction:** Uses parent tracking to reconstruct the shortest route from the starting cell to the destination.
- **Random obstacle generation:** Generates grids with an approximately 25% obstacle probability.
- **Console visualisation:** Displays obstacles, explored cells and the shortest path using symbols.
- **Visited-cell tracking:** Prevents cells from being added to the queue multiple times.
- **Unreachable destination detection:** Reports when no valid route exists.
- **Adjustable grid dimensions:** Grid width and height can be configured in the source code, with the destination coordinates currently fixed.

## Technologies

- **Language:** C++
- **Standard Library:** Vector, Queue, Map, Algorithm, Random
- **Algorithm:** Breadth-First Search (BFS)

## How It Works

1. A grid is generated with randomly positioned obstacles.
2. BFS begins at the top-left cell and explores valid neighbouring cells.
3. A queue ensures that cells are processed in breadth-first order.
4. Visited cells are tracked to prevent duplicate discoveries.
5. Each discovered cell stores its predecessor in a parent map.
6. If the destination is reached, the shortest path is reconstructed by following parent relationships backwards.
7. The final grid and path are displayed in the console.

BFS guarantees a shortest path in this grid because all valid movements have equal cost.

## Grid Symbols

| Symbol | Meaning |
|---|---|
| `S` | Starting position |
| `E` | Destination |
| `#` | Obstacle |
| `*` | Shortest path |
| `+` | Discovered cell |
| `.` | Other traversable cell |

The starting position is `(0,0)` and the destination is `(9,9)` in the default 10×10 grid.

## Running the Project

**Requirements:** A C++ compiler supporting C++11 or later.

1. Clone or download this repository.
2. Open the C++ source file in your preferred editor or IDE.
3. Compile the source file using a C++ compiler.
4. Run the compiled program in a terminal.

Each execution generates a new random grid, so the resulting path may differ between runs.

## Limitations

- Currently supports BFS only.
- Uses four-directional movement without diagonals.
- All valid movements have equal cost.
- Visualisation is console-based rather than graphical.
- Obstacles are randomly generated, so a valid route is not guaranteed.
- Grid dimensions require changes to the source code.

## Future Improvements

- Implement Depth-First Search (DFS) and A*.
- Compare algorithm performance using explored-cell counts and execution times.
- Animate the search process.
- Introduce an interactive graphical interface.
- Support weighted grids and additional movement options.

## Project Status

**Version 1 — Basic BFS implementation**

Core BFS traversal, shortest-path reconstruction and console visualisation have been implemented. Further algorithms and visual improvements are planned for future development.