import random
import networkx as nx
import test


# Define the fitness function
def fitness_f(individual, G):
    partitions = {}
    for node, community in zip(G.nodes(), individual):
        if community not in partitions:
            partitions[community] = set()
        partitions[community].add(node)
    modularity = nx.algorithms.community.modularity(G, list(partitions.values()))
    return modularity,


# Define the genetic algorithm
def genetic_algorithm(G, population_size, elite_size, mutation_rate, generations):
    # Create the initial population
    population = []
    for i in range(population_size):
        individual = [random.randint(0, population_size) for node in G.nodes()]
        population.append(individual)

    for generation in range(generations):
        # Evaluate the fitness of each individual
        fitness = [fitness_f(individual, G) for individual in population]

        # Select the elite individuals
        elite = sorted(range(len(fitness)), key=lambda i: fitness[i], reverse=True)[:elite_size]

        # Create the next generation
        next_generation = []
        for i in range(population_size - elite_size):
            # Select two parents
            parent1 = population[random.randint(0, population_size - 1)]
            parent2 = population[random.randint(0, population_size - 1)]

            # Crossover the parents
            crossover_point = random.randint(1, len(parent1) - 1)
            child = parent1[:crossover_point] + parent2[crossover_point:]

            # Mutate the child
            for j in range(len(child)):
                if random.random() < mutation_rate:
                    child[j] = random.randint(0, population_size)

            next_generation.append(child)

        # Add the elite individuals to the next generation
        for i in elite:
            next_generation.append(population[i])

        population = next_generation

    # Select the best individual
    fitness = [fitness_f(individual, G) for individual in population]
    best_individual = population[max(range(len(fitness)), key=lambda i: fitness[i])]

    # Construct the partition from the best individual
    partition = {}
    for node, community in zip(G.nodes(), best_individual):
        if community not in partition:
            partition[community] = set()
        partition[community].add(node)

    return partition.values()


if __name__ == '__main__':
    test.test7()
