import tkinter as tk
from Graph import GraphVisualizer


def main():
    root = tk.Tk()
    root.title("Undirected Graph Visualizer")
    graph = GraphVisualizer(root)
    btn = tk.Button(root, text="Найти клику", command=graph.drawClique)
    btn.pack(side=tk.TOP, anchor=tk.NW)
    root.mainloop()


if __name__ == "__main__":
    main()
