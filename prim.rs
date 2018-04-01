// Prim's algorithm

use std::collections::BinaryHeap;
use std::cmp::Ordering;

type Graph = Vec<Vec<i32>>;
struct WeightedVertex {
    index: usize,
    weight: i32
}

impl Ord for WeightedVertex {
    fn cmp(&self, other: &WeightedVertex) -> Ordering {
        self.weight.cmp(&other.weight).reverse()
    }
}

impl PartialOrd for WeightedVertex {
    fn partial_cmp(&self, other: &WeightedVertex) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Eq for WeightedVertex {}

impl PartialEq for WeightedVertex {
    fn eq(&self, other: &WeightedVertex) -> bool {
        self.weight == other.weight
    }
}

fn prim(graph: &Graph) -> Vec<i32> {
    let n = graph.len();
    let mut pred: Vec<i32> = vec![-1; n];
    let mut key: Vec<i32> = vec![std::i32::MAX; n];
    key[0] = 0;
    let mut pq: BinaryHeap<WeightedVertex> = BinaryHeap::new();
    let mut in_queue: Vec<bool> = vec![true; n];
    for v in 0..n {
        pq.push(WeightedVertex{index: v, weight: key[v]});
    }

    while !pq.is_empty() {
        let ud = pq.pop().unwrap();
        let u = ud.index;
        let d = ud.weight;
        in_queue[u] = false;

        for (v, w) in graph[u].iter().enumerate() {
            if *w != std::i32::MAX && in_queue[v] && *w < key[v] {
                pred[v] = u as i32;
                key[v] = *w;
                let x: Vec<WeightedVertex> = pq.iter().map(|ref wv|{
                    if wv.index == v {
                        WeightedVertex { index: v, weight: *w }
                    } else {
                        WeightedVertex { index: wv.index, weight: wv.weight }
                    }
                }).collect();
                pq = BinaryHeap::from(x);
            }
        }
    }

    pred
}

fn main() {
    let g = [[0,1,2], [0,3,8], [0,4,4], [1,2,3], [2,4,1], [2,3,5], [3,4,7]];
    let mut graph = vec![vec![std::i32::MAX;5];5];
    for e in g.iter() {
        let a = e[0];
        let b = e[1];
        let w = e[2];
        graph[a][b] = w as i32;
        graph[b][a] = w as i32;
    }

    let result = prim(&graph);
    println!("{:?}", result);
}
