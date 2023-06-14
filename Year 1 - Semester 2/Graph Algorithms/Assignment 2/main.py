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
    print("15. Exit application")


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
                y = int(input("Destionation vertex = "))
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