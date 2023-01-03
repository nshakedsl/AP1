# AP1

To compile the code do the following command:
```
make
```

To run the code do the following command:
```
./server.out file port
```
- **file** is the name of the file of the tagged vectors (can be a relative or full address)
- **port** is the port number of the server to listen on

```
./client.out ip port
```

- **ip** is the ip address of the server (for example 127.0.0.1 localhost)
- **port** is the port number on which the server listens

**Milestone 1 B branch:**

Targil 2 (Milestone 1 B) is on branch Milestone1b

**Milestone 2 branch:**

Targil 3 (Milestone 2) is on branch Milestone2

### **Implementation:**

#### **Milestone 1 A:**
Each of the algorithms has been implemented by following the instructions of the wikipedia page for the algorithm.

#### **Milestone 1 B:**
The csv file is read with fstream and sstream libraries. All the vectors are read from the file and stored in a sorted (by key) multimap in O(n*log(n)) , where the key is the distance from the given vector, and then we iterate over the map and return the k the smallest key values. Thus, the k  closest vectors are returned.

#### **Milestone 2:**
The server and the client communicate using the TCP protocol with sys/socket, arpa/inet, unistd and netinet/in libraries. The server listens on a specified port and serves incoming clients by reading data from them, parsing it, and sending a response back. We moved the implementation of the previous exercise to the following classes: Classification, File, Parser.

### **Optimisations:**

#### **Milestone 1 A:**
An optimisation to prevent code reuse has been using a generic algorithm to implement winkowski, euclidian and Manhetten distances. Since they only differ on the power of the vectors and the root, they can be treated as specific cases of a generic algorithm.

#### **Milestone 1 B:**

#### **Milestone 2:**
We took the length calculation out of the for loop to optimize the code.

**The constant p**

We chose a constant p=3 for the algorithm Minkowski.