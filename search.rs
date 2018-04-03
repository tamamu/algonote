// DFS, BFS

type Graph = Vec<Vec<i32>>;

#[derive(PartialEq,Clone)]
enum VertexColor {
    White,
    Gray,
    Black,
}

fn dfs_visit(graph: &Graph, u: usize, pred: &mut Vec<i32>, color: &mut Vec<VertexColor>) {
    color[u] = VertexColor::Gray;

    for (v, w) in graph[u].iter().enumerate() {
        if *w != std::i32::MAX && color[v] == VertexColor::White {
            pred[v] = u as i32;
            dfs_visit(graph, v, pred, color);
        }
    }

    color[u] = VertexColor::Black;
}

fn depth_first_search(graph: &Graph, source: usize) -> Vec<i32> {
    let n = graph.len();
    let mut pred: Vec<i32> = vec![-1;n];
    let mut color: Vec<VertexColor> = vec![VertexColor::White;n];

    dfs_visit(&graph, source, &mut pred, &mut color);

    pred
}

fn breadth_first_search(graph: &Graph, source: usize) -> (Vec<i32>, Vec<i32>) {
    use std::collections::VecDeque;

    let n = graph.len();
    let mut pred: Vec<i32> = vec![-1;n];
    let mut dist: Vec<i32> = vec![std::i32::MAX;n];
    let mut color: Vec<VertexColor> = vec![VertexColor::White;n];

    dist[0] = 0;
    color[source] = VertexColor::Gray;

    let mut q: VecDeque<usize> = VecDeque::new();
    q.push_front(source);

    while !q.is_empty() {
        let u = q.front().unwrap().clone();

        for (v, w) in graph[u].iter().enumerate() {
            if *w != std::i32::MAX && color[v] == VertexColor::White {
                dist[v] = dist[u] + 1;
                pred[v] = u as i32;
                color[v] = VertexColor::Gray;
                q.push_front(v);
            }
        }

        q.pop_front();
        color[u] = VertexColor::Black;
    }

    (pred, dist)
}

fn main() {
    let g = [[0, 1], [0, 8], [0, 6],
             [1, 2], [1, 3],
             [2,10], [2,11],
             [3, 4], [3,12],
             [4, 5], [4,13],
             [5, 6], [5, 9],
             [6, 7],
             [7, 8], [7, 9],
             [8,14],
             [9,15]];
    let mut graph = vec![vec![std::i32::MAX;16];16];

    for e in g.iter() {
        let u = e[0];
        let v = e[1];
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    let pred = depth_first_search(&graph, 0);
    println!("Result of DFS:\n{:?}", pred);

    let (pred, dist) = breadth_first_search(&graph, 0);
    println!("Result of BFS:\n{:?}\n{:?}", pred, dist);
}
