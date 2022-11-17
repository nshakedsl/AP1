# AP1

 To compile the code do the following command:
```
g++ -std=c++11 main.cpp Distances.h Distances.cpp
```

To run the code do the following command:
```
./a.out
```
**Implementation:**

Each of the algorithms has been implemented by following the instructions of the wikipedia page for the algorithm.

**Optimisations:** 

An optimisation to prevent code reuse has been using a generic algorithm to implement winkowski, euclidian and Manhetten distances. Since they only differ on the power of the vectors and the root, they can be treated as specific cases of a generic algorithm. 

**The constant p**

We chose a constant p=3 for the algorithm Minkowski.