def bron_kerbosch1(R, P, X):
    if not P and not X and len(R) > 2:
        some.append(R)
    for v in P.copy():
        print(R | {v}, P & graph[v], X & graph[v])
        bron_kerbosch1(R | {v}, P & graph[v], X & graph[v])
        P.remove(v)
        X.add(v)


# Example usage
graph = {
    "A": {"B", "C"},
    "B": {"A", "C", "D"},
    "C": {"A", "B", "F"},
    "D": {"B", "E"},
    "E": {"D", "F"},
    "F": {"C", "E"},
}

some = []

# Initialize P and X
R = set()
P = set(graph.keys())
X = set()

# Call the function
bron_kerbosch1(R, P, X)
print(some)
