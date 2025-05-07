# DatabaseStructuresRepo

This repository contains a collection of projects that implement different data structures and algorithms to process network logs, each addressing a specific activity. Each project is organized in a separate folder and uses a distinct data structure to solve problems related to IP address analysis, dates, and network connections.

## Table of Contents
1. [Repository Structure](#repository-structure)
2. [Project Descriptions](#project-descriptions)
   - [BasicSorting (Activity 1.3)](#basicsorting-activity-13)
   - [DoublyLinkedList (Activity 2.3)](#doublylinkedlist-activity-23)
   - [HeapSortIP (Activity 3.3)](#heapsortip-activity-33)
   - [GraphAnalysis (Activity 4.3)](#graphanalysis-activity-43)
   - [HashTableIP (Activity 5.2)](#hashtableip-activity-52)
3. [Usage Instructions](#usage-instructions)
4. [Requirements](#requirements)
5. [Notes](#notes)

## Repository Structure

- **BasicSorting**: Activity 1.3 - Basic Concepts and Fundamental Algorithms
- **DoublyLinkedList**: Activity 2.3 - Linear Data Structures
- **HeapSortIP**: Activity 3.3 - Binary Search Tree (BST)
- **GraphAnalysis**: Activity 4.3 - Graphs
- **HashTableIP**: Activity 5.2 - Hash Codes

## Project Descriptions

### BasicSorting (Activity 1.3)
Processes a log stored in a vector, sorted by date (month, day, hour, minutes, seconds) using two sorting algorithms: an inefficient one (e.g., Bubble Sort) and an efficient one (e.g., QuickSort). Supports searching records within a date range using binary search.

- **Input**: `bitacora.txt`
- **Output**: 
  - `bitacora_ordenada.txt` (sorted log)
  - On-screen results for date ranges
- **Data Structure**: Vector
- **Algorithms**: Bubble Sort, QuickSort, Binary Search

### DoublyLinkedList (Activity 2.3)
Implements a log stored in a doubly linked list, sorted by date and time using Merge Sort. Supports date range searches using binary search.

- **Input**: `bitacora.txt`
- **Output**: 
  - `bitacora_ordenada.txt` (sorted log)
  - `resultado_busqueda.txt` (records within date range)
- **Data Structure**: Doubly Linked List
- **Algorithms**: Merge Sort, Binary Search

### HeapSortIP (Activity 3.3)
Sorts a log by IP address (ignoring ports) using Heap Sort. Counts IP accesses using a hierarchical data structure and identifies the top 10 IPs with the most accesses.

- **Input**: `bitacoraHeap.txt`
- **Output**: 
  - `bitacora_ordenada.txt` (log sorted by IP)
  - `ips_con_mayor_acceso.txt` (top 10 IPs with most accesses)
- **Data Structure**: Heap
- **Algorithms**: Heap Sort

### GraphAnalysis (Activity 4.3)
Analyzes a log represented as a directed graph using an adjacency list. Computes out-degrees, identifies the top 5 IPs with the highest out-degree, and calculates the shortest paths from the "boot master" to other IPs.

- **Input**: `bitacoraGrafos.txt`
- **Output**: 
  - `grados_ips.txt` (out-degrees per IP)
  - `mayores_grados_ips.txt` (top 5 IPs with highest out-degree)
  - `distancia_bootmaster.txt` (distances from boot master)
- **Data Structure**: Adjacency List (Graph)
- **Algorithms**: Heap Sort, Dijkstra

### HashTableIP (Activity 5.2)
Stores IP information in a hash table with quadratic probing for collision resolution. Provides summaries of IPs (outgoing and incoming accesses) and lists of accessed IPs.

- **Input**: `bitacoraGrafos.txt`
- **Output**: 
  - IP summary on screen
  - Number of collisions on screen
- **Data Structure**: Hash Table
- **Algorithms**: Hashing with Quadratic Probing

## Usage Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/username/DatabaseStructuresRepo.git
   ```
2. Navigate to the desired project folder:
   ```bash
   cd DatabaseStructuresRepo/folder_name
   ```
3. Compile and run each project according to its specific instructions (usually with a Makefile or manual C++ compilation).
4. Ensure input files (`bitacora.txt`, `bitacoraHeap.txt`, `bitacoraGrafos.txt`) are in the corresponding directory.

## Requirements

- C++ compiler (g++ recommended)
- Operating system supporting file input/output
- Input files provided for each activity

## Notes

- The projects are designed to meet the requirements of integral activities in a data structures course.
- Each project includes test cases where applicable (e.g., `TestCasesAct1.3.zip` for BasicSorting and DoublyLinkedList).
- Input file formats are specified in the corresponding documents (`Formato_Bitacora_Grafos.pdf`, `Formato del archivo bitacora.pdf`).
