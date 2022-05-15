# ADSA_ASSG_4

# Dijkstra’s algorithm

Compilation cmd : g++ -std=gnu++11 Djisktra.cpp <br>
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
10. To find shortest path distance from given source vertex to all the n vertices : type apsp source
11. To find shortest path distance from given source vertex to given destination : type sssp source destination
12. Type stop to terminate the program
  
# Sample Input
9 <br>
1 4<br>
5<br>
3<br>
6<br>
2 7 8<br>
2<br>
4<br>
5 7<br>
2 20<br>
3<br>
7<br>
5<br>
1 6 4v
0<br>
2<br>
2 1  <br>
apsp 0<br>
sssp 0 6<br>
sssp 0 7<br>
sssp 5 6<br>
sssp 8 7<br>
stop<br>
<br>  
# Sample Output
0 2 6 13 12 5 18 10 9<br>
18<br>
10<br>
13<br>
1<br>

# Bellman Ford's algorithm

compilation cmd : g++ -std=gnu++11 bellmanford.cpp
Run cmd : ./a.out

# Sample Input

Enter number of vertices and edges : 5 <br>
8<br>
<br>
Enter each edge and its weight (u, v, wt) : 0 1 -1<br>
0 2 4<br>
1 2 3<br>
1 3 2<br>
1 4 2<br>
3 2 5<br>
3 1 1<br>
4 3 -3<br>
<br>
Enter the source vertex : 0<br>
<br>
# Sample Output<br>
Distance of vertex 0 to 0 is 0<br>
Distance of vertex 0 to 1 is -1<br>
Distance of vertex 0 to 2 is 2<br>
Distance of vertex 0 to 3 is -2<br>
Distance of vertex 0 to 4 is 1<br>

