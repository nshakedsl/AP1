# AP1REAL

 To compile the code do the following command:
```
make
```

To run the code do the following command:
```
./a.out k file distance
```
- **k** is the number of neighbors (any positive int value)
- **file** is the name of the file of the tagged vectors (can be a relative or full address)
- **distance** is the distance metric: (the representing string value is written next to each one)
1) Euclidean distance - AUC
2) Manhattan distance - MAN
3) Distance Chebyshev - CHB
4) Distance Canberra - CAN
5) Minkowski distance - MIN

### **Implementation:**

#### **Milestone 1 A:**
Each of the algorithms has been implemented by following the instructions of the wikipedia page for the algorithm.

#### **Milestone 1 B:**
The csv file is read with fstream and sstream libraries. All the vectors are read from the file and stored in a sorted (by key) multimap in O(n*log(n)) , where the key is the distance from the given vector, and then we iterate over the map and return the k the smallest key values. Thus, the k  closest vectors are returned.

### **Optimisations:** 

#### **Milestone 1 A:**
An optimisation to prevent code reuse has been using a generic algorithm to implement winkowski, euclidian and Manhetten distances. Since they only differ on the power of the vectors and the root, they can be treated as specific cases of a generic algorithm.

#### **Milestone 1 B:**
**The constant p**

We chose a constant p=3 for the algorithm Minkowski.