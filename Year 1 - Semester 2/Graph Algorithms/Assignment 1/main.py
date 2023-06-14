import math
import random

class Graph:
    def __init__(self, vertices):
        """
        :param vertices: an interable, containing the vertices of the graph
        """
        self.__graph = {}
        self.__in = {}
        self.__out = {}
        for v in vertices:
            self.__in[v] = set()
            self.__out[v] = set()


    def __str__(self):
        res = "Outbounds:\n"
        for x in self.get_vertices():
            res = res + f"{x}: "
            for y in self.out_neighbours(x):
                res = res + f"{y} "
            res = res + "\n"

        res = res + "\nInbounds:\n"
        for y in self.get_vertices():
            res = res + f"{y}: "
            for x in self.in_neighbours(y):
                res = res + f"{x} "
            res = res + "\n"

        return res


    def add_edge(self, x, y, c):
        if x >= self.get_nr_vertices() or y >= self.get_nr_vertices():
            raise Exception("Vertices doesn't exist!")
        self.__out[x].add(y)
        self.__in[y].add(x)
        self.__graph[(x, y)] = c


    def get_nr_vertices(self):
        return len(self.__out)


    def get_nr_edges(self):
        return len(self.__graph)


    def get_vertices(self):
        return [v for v in self.__out]


    def is_edge(self, x, y):
        return y in self.__out[x]


    def out_degree(self, v):
        return len(self.__out[v])


    def in_degree(self, v):
        return len(self.__in[v])


    def out_neighbours(self, x):
        res = []
        for y in self.__out[x]:
            res.append(y)
        return res


    def in_neighbours(self, y):
        res = []
        for x in self.__in[y]:
            res.append(x)
        return res


    def modify_cost_edge(self, x, y, new_c):
        if (x, y) not in self.__graph:
            raise Exception("The edge doesn't exist!")

        self.__graph[(x, y)] = new_c


    def get_cost_edge(self, x, y):
        if (x, y) not in self.__graph:
            raise Exception("The edge doesn't exist!")
        return self.__graph[(x, y)]


    def remove_vertex(self, v):
        if v not in self.get_vertices():
            raise Exception("The vertex doesn't exist!")

        new_graph = {}
        for key in self.__graph:
            if key[0] == v or key[1] == v:
                continue
            else:
                new_graph[key] = self.__graph[key]

        self.__graph = new_graph
        self.__in[v].clear()
        for x in self.__in:
            if v in self.__in[x]:
                self.__in[x].remove(v)

        self.__out[v].clear()


    def remove_edge(self, x, y):
        if (x, y) not in self.__graph:
            raise Exception("The edge doesn't exist!")
        self.__graph.pop((x, y))
        self.__out[x].remove(y)


    def create_copy(self):
        new_graph = Graph(self.get_vertices())
        for key in self.__graph:
            new_graph.add_edge(key[0], key[1], self.__graph[key])
        return new_graph



def read_graph(txt_file: str):
    with open(txt_file, "r") as f:
        l = f.readline()
        tokens = l.split()
        n, m = int(tokens[0]), int(tokens[1])
        g = Graph([x for x in range(0, n)])
        for i in range(0, m):
            l = f.readline()
            tokens = l.split()
            x, y, c = int(tokens[0]), int(tokens[1]), int(tokens[2])
            g.add_edge(x, y, c)
        return g


def write_graph(g:Graph, txt_file: str):
    with open(txt_file, "w") as f:
        res = f"{g.get_nr_vertices()} {g.get_nr_edges()}\n"
        for x in g.get_vertices():
            for y in g.out_neighbours(x):
                c = g.get_cost_edge(x, y)
                res = res + f"{x} {y} {c}\n"

            for y in g.in_neighbours(x):
                c = g.get_cost_edge(y, x)
                res = res + f"{y} {x} {c}\n"
        f.write(res)


def create_random_graph(n:int, m:int):
    if m > n*(n-1):
        raise Exception("Too many edges!")

    g = Graph([x for x in range(0, n)])
    while m > 0:
        x = random.randrange(0, n)
        y = random.randrange(0, n)
        if x != y and not g.is_edge(x, y):
            c = random.randrange(0, 1000001)
            g.add_edge(x, y, c)
            m -= 1
    return g


def bfs(g: Graph, v1: int, v2: int):
    if v1 >= g.get_nr_vertices() or v2 >= g.get_nr_vertices(): # if the vertices are out of range
        raise Exception("Invalid vertices!")
    if v1 == v2: # if the source vertex is the same as the destination vertex
        return [v1, v2]
    queue = []
    visited = [False for i in range(g.get_nr_vertices())] # mark list which will check if a node was visited or not
    max_val = g.get_nr_edges() + 1 # a max value
    dist = [max_val for i in range(g.get_nr_vertices())] # list which contains the distances from the node x to any other node
    pred = [-1 for i in range(g.get_nr_vertices())]# list which contains the pred of a certain node in the shortest path
    visited[v1] = True
    dist[v1] = 0
    queue.append(v1)
    ok = False # true if a path exists, false otherwise
    while len(queue) != 0:  # while we have values in our queue
        u = queue[0] # assign to u the current node
        queue.pop(0) # pop u from the queue because we don't need it anymore
        for y in g.out_neighbours(u):   # iterate through all the out neighbour of u
            if visited[y] == False: # if it wasn't visited
                visited[y] = True
                dist[y] = dist[u] + 1 # increment the distance with one
                pred[y] = u # store the parent of node y
                queue.append(y)
                if y == v2: # if we arrived at destination we can stop
                    ok = True
                    break

    if ok == False: # if the destination wasn't found, than we don't have a path, thus we return None
        return None

    path = []   # store the path
    e = v2
    path.append(e)
    while pred[e] != -1:
        path.append(pred[e])
        e = pred[e]

    path.reverse()
    return path


def Floyd_Warshall(g: Graph, x1: int, x2: int):
    """
    :param g: Graph
    :param x1: Source vertex
    :param x2: Destination vertex
    :return: tuple, the cost + the minimum cost path
    """
    nr_vert = g.get_nr_vertices()

    if not(0 <= x1 < nr_vert or 0 <= x2 < nr_vert):
        raise Exception("Invalid vertices")

    # array of minimum distances initialized to displaystyle infinity
    dist = [[math.inf for i in range(nr_vert)] for j in range(nr_vert)]

    # array of vertex indices initialized to -1
    # used for reconstructing the path
    next = [[-1 for i in range(nr_vert)] for j in range(nr_vert)]

    # initializing the min distance matrix
    for i in range(0, nr_vert):
        for j in range(0, nr_vert):
            if g.is_edge(i, j) == True:
                dist[i][j] = g.get_cost_edge(i, j)
                next[i][j] = j

    for i in range(0, nr_vert):
        dist[i][i] = 0
        next[i][i] = i

    # Floyd-Warshall Algorithm
    for k in range(0, nr_vert):
        for i in range(0, nr_vert):
            for j in range(0, nr_vert):
                if dist[i][j] > dist[i][k] + dist[k][j]: # if there's a shorter path from i to j through the vertex k
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next[i][j] = next[i][k]

    # in case there's no path
    if next[x1][x2] == -1:
        return NULL, NULL

    u, v = x1, x2
    path = [u]
    while u != v:
        u = next[u][v]
        path.append(u)
    return dist[x1][x2], path


def Activities(nrvertices: int, filename: str):
    g = Graph([x for x in range(0, nrvertices)])
    with open(filename, "r") as f:
        f.readline()
        lines = f.readlines()
        for line in lines:
            line = line.split()
            outvertices = line[2].split(",")
            in_vertex = int(line[0])
            for x in outvertices:
                out_vertex = int(x)
                cost = int(line[1])
                g.add_edge(out_vertex, in_vertex, cost)

    print(g)

    # Topological sort
    sorted = []
    queue = []
    count = {}

    for x in g.get_vertices():
        count[x] = len(g.in_neighbours(x))
        if count[x] == 0:
            queue.append(x)


    while not len(queue) == 0:
        x = queue[0]
        queue.remove(x)
        sorted.append(x)

        for y in g.out_neighbours(x):
            count[y] -= 1
            if count[y] == 0:
                queue.append(y)

    if len(sorted) < g.get_nr_vertices():
        raise Exception("not a DAG!")

    print("A topological order is: ", sorted)

    #Schedule

    timing = {}
    timing[0] = [0, 0]
    sorted.remove(0)

    for x in sorted:
        timing[x] = []
        max_time = 0
        for y in g.in_neighbours(x):
            some_previous_node = y
            if timing[y][1] > max_time:
                max_time = timing[y][1]
        duration = g.get_cost_edge(some_previous_node, x)
        timing[x].append(max_time)
        timing[x].append(max_time + duration)

    print("early scheduling:", timing)

    sorted.reverse()

    Ltiming = {}
    Ltiming[sorted[0]] = [0, 0]
    sorted.remove(sorted[0])
    sorted.append(0)

    for x in sorted:
        Ltiming[x] = []
        min_time = 0
        for y in g.out_neighbours(x):
            if Ltiming[y][0] < min_time:
                min_time = Ltiming[y][0]
        if x == 0:
            duration = 0
        else:
            duration = -g.get_cost_edge(g.in_neighbours(x)[0], x)

        Ltiming[x].append(min_time + duration)
        Ltiming[x].append(min_time)

    print("\n")
    #Critical activities
    total_time = -Ltiming[0][0]
    critical_points =[]
    for x in Ltiming:
        Ltiming[x][0] = Ltiming[x][0] + total_time
        Ltiming[x][1] = Ltiming[x][1] + total_time
        if Ltiming[x][0] == timing[x][0] and Ltiming[x][1] == timing[x][1]:
            critical_points.append(x)

    print("later scheduling:", Ltiming, "\n")
    print("critical activities are: ", critical_points)




def print_menu():
    print("1. Add edge")
    print("2. Get nr of vertices")
    print("3. Get nr of edges")
    print("4. Check edge")
    print("5. Get the out degree of vertex")
    print("6. Get the in degree of vertex")
    print("7. Get the out neighbours of a vertex")
    print("8. Get the in neighbours of a vertex")
    print("9. Get the cost of an edge")
    print("10. Modify the cost of an edge")
    print("11. Remove a vertex")
    print("12. Remove an edge")
    print("13. Save graph in file")
    print("14. Print graph")
    print("15. Shortest path from node1 to node2 using BFS")
    print("16. Minimum cost path from node1 to node2 using Floyd-Warshall")
    print("17. Is DAG? Show topoligical order, earliest and latest time for each activity and the total time of the project, critical activities")
    print("18. Exit application")


def menu(g:Graph):
    while True:
        print_menu()
        try:
            option = int(input("option = "))
        except Exception as e:
            print(e)

        if option == 1:
            try:
                x = int(input("Source vertex = "))
                y = int(input("Destination vertex = "))
                c = int(input("Edge cost = "))
                g.add_edge(x, y, c)
            except Exception as e:
                print(e)
        elif option == 2:
            try:
                print(g.get_nr_vertices())
            except Exception as e:
                print(e)
        elif option == 3:
            try:
                print(g.get_nr_edges())
            except Exception as e:
                print(e)
        elif option == 4:
            try:
                    x = int(input("Source vertex = "))
                    y = int(input("Destionation vertex = "))
                    print(g.is_edge(x, y))
            except Exception as e:
                print(e)
        elif option == 5:
            try:
                x = int(input("vertex = "))
                print(g.out_degree(x))
            except Exception as e:
                print(e)
        elif option == 6:
            try:
                x = int(input("vertex = "))
                print(g.in_degree(x))
            except Exception as e:
                print(e)
        elif option == 7:
            try:
                x = int(input("vertex = "))
                print(g.out_neighbours(x))
            except Exception as e:
                print(e)
        elif option == 8:
            try:
                x = int(input("vertex = "))
                print(g.in_neighbours(x))
            except Exception as e:
                print(e)
        elif option == 9:
            try:
                x = int(input("Source vertex = "))
                y = int(input("Destionation vertex = "))
                print(g.get_cost_edge(x, y))
            except Exception as e:
                print(e)
        elif option == 10:
            try:
                x = int(input("Source vertex = "))
                y = int(input("Destionation vertex = "))
                c = int(input("The new cost of an edge = "))
                g.modify_cost_edge(x, y, c)
            except Exception as e:
                print(e)
        elif option == 11:
            try:
                x = int(input("Vertex = "))
                g.remove_vertex(x)
            except Exception as e:
                print(e)
        elif option == 12:
            try:
                x = int(input("Source vertex = "))
                y = int(input("Destination vertex = "))
                g.remove_edge(x, y)
            except Exception as e:
                print(e)
        elif option == 13:
            try:
                f = input("File name = ")
                write_graph(g, f)
            except Exception as e:
                print(e)
        elif option == 14:
            try:
                print(g)
            except Exception as e:
                print(e)
        elif option == 15:
            try:
                x = int(input("Source vertex = "))
                y = int(input("Destination vertex = "))
                print(bfs(g, x, y))
            except Exception as e:
                print(e)
        elif option == 16:
            try:
                x = int(input("Source vertex = "))
                y = int(input("Destination vertex = "))
                print(Floyd_Warshall(g, x, y))
            except Exception as e:
                print(e)
        elif option == 17:
             try:
                filename = input("filename = ")
                maxVertex = 0
                with open(filename, "r") as f:
                    lines = f.readlines()
                    for line in lines:
                        if (int(line[0]) > maxVertex):
                            maxVertex = int(line[0])

                    Activities(maxVertex+1, filename)
             except Exception as e:
                print(e)
        elif option == 18:
            exit(0)


def mini_menu():
    print("1. Generate random graph")
    print("2. Read graph from file")
    print("3. Exit application")


def run():
    while True:
        mini_menu()
        option = int(input("option = "))
        if option == 1:
            n = int(input("Number vertices = "))
            m = int(input("Number edges = "))
            try:
                g = create_random_graph(n, m)
            except Exception as e:
                print(e)
            else:
                break
        elif option == 2:
            f = input("File name = ")
            try:
                g = read_graph(f)
            except Exception as e:
                print(e)
            else:
                break
        elif option == 3:
            exit(0)
        else:
            print("Bad option! Try again!")
    menu(g)


run()

# next - problem 2