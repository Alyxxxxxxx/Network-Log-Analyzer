# Network-Log-Analyzer
This repository contains a collection of projects that implement different data structures and algorithms to process network logs, each addressing a specific activity. Each project is organized in a separate folder and uses a distinct data structure to solve problems related to IP address analysis, dates, and network connections.

This repository hosts a suite of C++ projects designed to analyze network log data using various data structures and algorithms. Each project is contained within a dedicated directory, addressing specific requirements of network log processing tasks, such as sorting, searching, and graph-based analysis. The projects demonstrate proficiency in implementing fundamental and advanced data structures to solve real-world network analysis problems efficiently.

## Table of Contents
1. [Repository Structure](#repository-structure)
2. [Project Descriptions](#project-descriptions)
   - [VectorDateSort (Activity 1.3)](#vectordatesort-activity-13)
   - [DoublyLinkedListSort (Activity 2.3)](#doublylinkedlistsort-activity-23)
   - [HeapIPSort (Activity 3.3)](#heapipsort-activity-33)
   - [GraphNetworkAnalysis (Activity 4.3)](#graphnetworkanalysis-activity-43)
   - [HashIPSummary (Activity 5.2)](#hashipsummary-activity-52)
3. [Usage Instructions](#usage-instructions)
4. [Prerequisites](#prerequisites)
5. [Notes](#notes)
6. [License](#license)

## Repository Structure

- **VectorDateSort**: Activity 1.3 - Basic Concepts and Fundamental Algorithms
- **DoublyLinkedListSort**: Activity 2.3 - Linear Data Structures
- **HeapIPSort**: Activity 3.3 - Binary Search Tree and Heap Structures
- **GraphNetworkAnalysis**: Activity 4.3 - Graph-Based Analysis
- **HashIPSummary**: Activity 5.2 - Hash Table Implementation

## Project Descriptions

### VectorDateSort (Activity 1.3)
This project processes a network log stored in a vector, sorting entries by timestamp (month, day, hour, minutes, seconds) using two algorithms: an inefficient algorithm (Bubble Sort) for comparison and an efficient algorithm (QuickSort). It supports range-based queries for log entries within user-specified timestamps using binary search.

- **Input**: `bitacora.txt` (format specified in `Formato del archivo bitacora.pdf`)
- **Output**: 
  - `bitacora_ordenada.txt`: Log sorted by timestamp
  - Console output: Log entries within the specified timestamp range
  - Performance metrics: Comparison of sorting algorithms (comparisons and swaps)
- **Data Structure**: Vector
- **Algorithms**: Bubble Sort, QuickSort, Binary Search
- **Test Cases**: Validated with `TestCasesAct1.3.zip`

### DoublyLinkedListSort (Activity 2.3)
This project implements a network log stored in a doubly linked list, sorted by timestamp using Merge Sort. It supports range-based queries for log entries using binary search, ensuring efficient retrieval of records within a closed timestamp interval.

- **Input**: `bitacora.txt` (format specified in `Formato del archivo bitacora.pdf`)
- **Output**: 
  - `bitacora_ordenada.txt`: Log sorted by timestamp
  - `resultado_busqueda.txt`: Log entries within the specified timestamp range
  - Console output: Matching log entries
- **Data Structure**: Doubly Linked List
- **Algorithms**: Merge Sort, Binary Search
- **Test Cases**: Validated with `TestCasesAct1.3.zip`

### HeapIPSort (Activity 3.3)
This project sorts a network log by IP address (excluding ports) using Heap Sort. It employs a hierarchical data structure to count IP access frequencies and identifies the top 10 IPs with the highest access counts.

- **Input**: `bitacoraHeap.txt`
- **Output**: 
  - `bitacora_ordenada.txt`: Log sorted by IP address
  - `ips_con_mayor_acceso.txt`: Top 10 IPs with access counts
  - Console output: Top 10 IPs and their access counts
- **Data Structure**: Max-Heap
- **Algorithms**: Heap Sort

### GraphNetworkAnalysis (Activity 4.3)
This project models a network log as a directed graph using an adjacency list. It computes out-degrees for each IP, identifies the top 5 IPs with the highest out-degrees, and calculates shortest paths from a presumed "boot master" IP to all other nodes using Dijkstra’s algorithm. It also identifies the IP requiring the most effort to attack.

- **Input**: `bitacoraGrafos.txt` (format specified in `Formato_Bitacora_Grafos.pdf`)
- **Output**: 
  - `grados_ips.txt`: Out-degrees for each IP
  - `mayores_grados_ips.txt`: Top 5 IPs with highest out-degrees
  - `distancia_bootmaster.txt`: Shortest path distances from the boot master
  - Console output: Boot master IP and most effort-intensive IP
- **Data Structure**: Adjacency List (Directed Graph)
- **Algorithms**: Heap Sort, Dijkstra’s Algorithm

### HashIPSummary (Activity 5.2)
This project stores IP-related data in a hash table with quadratic probing for collision resolution. It summarizes IP information, including outgoing and incoming access counts, and provides sorted lists of accessed IPs for a user-specified IP.

- **Input**: `bitacoraGrafos.txt` (format specified in `Formato_Bitacora_Grafos.pdf`)
- **Output**: 
  - Console output: Collision count, IP summary (access counts), and sorted list of accessed IPs
- **Data Structure**: Hash Table
- **Algorithms**: Hashing with Quadratic Probing

## Usage Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/username/NetworkLogAnalysis.git
   ```
2. Navigate to the desired project directory:
   ```bash
   cd NetworkLogAnalysis/<directory_name>
   ```
3. Compile the project using the provided Makefile or manually:
   ```bash
   g++ -std=c++11 *.cpp -o <project_name>
   ```
4. Place the required input file (`bitacora.txt`, `bitacoraHeap.txt`, or `bitacoraGrafos.txt`) in the project directory.
5. Run the executable:
   ```bash
   ./<project_name>
   ```
6. Follow on-screen prompts for input (e.g., timestamp ranges or IP addresses) where applicable.

## Prerequisites

- **Compiler**: GCC (g++ 7.0 or later) or any C++11-compliant compiler
- **Operating System**: Linux, macOS, or Windows with a compatible terminal
- **Input Files**: Provided log files (`bitacora.txt`, `bitacoraHeap.txt`, `bitacoraGrafos.txt`)
- **Test Cases**: `TestCasesAct1.3.zip` for VectorDateSort and DoublyLinkedListSort

## Notes

- Each project adheres to the specifications of a data structures course, focusing on practical applications of algorithms and data structures.
- Input file formats are documented in `Formato del archivo bitacora.pdf` and `Formato_Bitacora_Grafos.pdf`.
- Test cases ensure correctness for VectorDateSort and DoublyLinkedListSort projects.
- Projects are implemented in C++ for portability and performance.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
