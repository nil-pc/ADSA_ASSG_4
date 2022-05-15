# ADSA_ASSG_4

Dijkstra’s algorithm

Compilation cmd : g++ -std=gnu++11 Djisktra.cpp
Rum cmd : ./a.out

Input format
1. Enter number of vertices (0 to n-1).
2. Enter the adjacency list for each of the vertex in a single line spanned over n lines.
3. Eg: Graph : 0->1->2->3 2->4 3->0 will be given as input in the following manner
4. 5 (n)
5. 1 (Adjacency list of vertex 0)
6. 2 (Adjacency list of vertex 1)
7. 3 4 (Adjacency list of vertex 2)
8. 0 (Adjacency list of vertex 3)
9.   (Adjacency list of vertex 4 - intentionally left blank if no edge is present)
10. To find shortest path distance from given source vertex to all the n vertices : type apsp <source>
11. To find shortest path distance from given source vertex to given destination : type sssp <source> <destination>
12. Type stop to terminate the program
  
# Sample Input
9
1 4
5
3
6
2 7 8
2
4
5 7
2 20
3
7
5
1 6 4
0
2
2 1  
apsp 0
sssp 0 6
sssp 0 7
sssp 5 6
sssp 8 7
stop
  
# Sample Output
0 2 6 13 12 5 18 10 9
1810
13
1
