from main import *


def test1():
    print("DOLPHIN")
    Graph = nx.read_gml('dolph.gml')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test2():
    print("KARATE")
    Graph = nx.read_gml('karate.gml', label='id')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test3():
    print("FOOTBALL")
    Graph = nx.read_gml('football.gml', label='id')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test4():
    print("KREBS")
    Graph = nx.read_gml('krebs.gml', label='id')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test5():
    print("SHELL")
    Graph = nx.read_gml('shell.gml', label='id')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test6():
    print("LESMIS")
    Graph = nx.read_gml('lesmis.gml', label='id')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test7():
    print("NETSCIENCE")
    Graph = nx.read_gml('netscience.gml', label='id')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")


def test8():
    print("TESTMARE")
    Graph = nx.read_edgelist('testmare.gml')
    structure = genetic_algorithm(Graph, 100, 10, 0.01, 100)
    for i, community in enumerate(structure):
        print(f"Community {i + 1}: {community}")
