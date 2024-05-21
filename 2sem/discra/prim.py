def bron_kerbosch1(R, P, X):
    if not P and not X and len(R) > 2:
        print(R, " - клика")
    for v in P.copy():
        bron_kerbosch1(R | {v}, P & graph[v], X & graph[v])
        P.remove(v)
        X.add(v)


graph = {
    "A": {"B", "C"},
    "B": {"A", "C", "D"},
    "C": {"A", "B", "F"},
    "D": {"B", "E"},
    "E": {"D", "F"},
    "F": {"C", "E"},
}
P = set(graph.keys())
X = set()
R = set()

bron_kerbosch1(R, P, X)
