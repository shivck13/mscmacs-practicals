"Collection of all the practicals for MMTE-001 - Graph Theory" 

### Index
1. Program 1: Write a program that constructs the adjacency matrix $A$ of an undirected, unweighted graph, given a sequence of edges as input. The program must perform the following operations:
* print the degree sequence of the graph.
* print the neighbours of a given vertex.
* compute $Ak^$ for any positive integer $k$ given by the user.
* print the number of walks of length $k$, between any two vertices.

2. Program 2: Write a program to check whether a given graph is connected or not. (See Theorem 5 of Unit 2)
    > Theorem 5: Let G be a graph with $V(G)$ = {$v_1, v_2, ...., v_n$} and the adjacency matrix A. Then G is connected iff every nondiagonal entry of the matrix $M = A + A^2 + ... + A^{n-1}$ is nonzero.

3. Program 3: Write a program that uses the adjacency lists for storing a graph. The program takes a sequence of edges as input, and must perform the following tasks:
* print the degree sequence of the graph
* print all the neighbours of a given vertex
* check whether any two given vertices are adjacent or not

4. Program 4: Write a program that stores a weighted graph using adjacency list representation, and prints the weight of any input subgraph of it.

5. Program 5: Write a program that constructs and prints the incidence matrix of a given undirected graph. The program takes a list of pairs ($v_i, e_j$) as input, where $v_i$ is an endpoint of $e_j$. The program must perform the following tasks:
* print the degree sequence of the graph
* print the adjacency matrix of the graph using the relation $A = BB^T - D$

6. Program 6: Write a program that implements Kruskal’s Algorithm to find a minimum weight spanning tree in a weighted connected graph.

7. Program 7: Write a program that uses the BFS Algorithm to find a rooted spanning tree in a given connected graph. The program should print the list of edges of the spanning tree.

8. Program 8: Using Dijkstra’s Algorithm write a program to find the distances from a root vertex to all the vertices in a connected weighted graph. (Use the adjacency list representation for storing the graph.)

9. Program 9:
* Write a function namely ff_algorithm ($N, f$) which takes as input a network $N, a$ flow $f$ and returns an $f$-augmenting chain or a set $S$.
* (ii) Write a program that calls the function $ff\_algorithm(N, f)$ repeatedly and computes the maximum flow in a given network. Run your program for some small networks.