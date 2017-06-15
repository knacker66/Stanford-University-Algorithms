1. Consider a connected undirected graph G with edge costs, which need not be distinct. Prove the following statement or provide a counterexample: for every MST T of G, there exists a way to sort G's edges in nondecreasing order of cost so that Kruskal's algorithm outputs the tree T.
2. Recall the definition of a minimum bottleneck spanning tree from Problem Set #2. Give a linear-time (i.e., O(m)) algorithm for computing a minimum bottleneck spanning tree of a connected undirected graph. [Hint: make use of a non-trivial linear-time algorithm discussed in Part 1 of the specialization.]
3. Consider a connected undirected graph G with distinct edge costs that are positive integers between 1 and n3, where n is the number of vertices of G. How fast can you compute the MST of G?
4. Read about [matroids](https://en.wikipedia.org/wiki/Matroid). Prove that the [greedy algorithm](https://en.wikipedia.org/wiki/Matroid#Greedy_algorithm) correctly computes a maximum-weight basis. For the matroid of spanning trees of a graph, this algorithm becomes Kruskal's algorithm. Can you formulate an analog of Prim's MST algorithm for matroids?
5. Prove that our analysis of union-find with lazy unions and union by rank (but without path compression) is asymptotically optimal (i.e., there are sequences of operations where you do Θ(logn) work on most of the operations).
6. Prove that in our union-find data structure with lazy unions, union by rank, and path compression, some operations might require Θ(logn) time.