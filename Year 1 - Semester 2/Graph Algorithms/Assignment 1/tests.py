import unittest

from main import Graph, create_random_graph, write_graph, read_graph
class Tests(unittest.TestCase):

    def test_functions(self):
        g = create_random_graph(10, 20)
        self.assertTrue(g.get_nr_edges() == 20)
        self.assertTrue(g.get_nr_vertices() == 10)
        g = read_graph("graph1k.txt")
        g.remove_edge(0, 154)
        self.assertTrue(g.is_edge(0, 154) == False)
        self.assertTrue(g.get_cost_edge(0, 161) == 63)
        g.modify_cost_edge(0, 161, 10)
        self.assertTrue(g.get_cost_edge(0, 161) == 10)
        u = [784, 109, 854, 447]
        self.assertTrue(g.in_neighbours(1) == u)
        self.assertTrue(g.in_degree(1) == 4)
        self.assertTrue(g.out_degree(1) == 3)
        g.remove_vertex(1)
        self.assertTrue(g.in_degree(1) == 0)






