// Floyd-Warshall

use std::collections::LinkedList;
use std::i32::MAX;

struct Edge {
    weight: i32,
    source: usize,
    destination: usize
}

fn num_vertices(graph: &LinkedList<Edge>) -> usize {
    let mut labels: Vec<usize> = Vec::new();
    for e in graph.iter() {
        labels.push(e.source);
        labels.push(e.destination);
    }
    labels.sort();
    labels.dedup();
    labels.len()
}

fn floyd_warshall(graph: &LinkedList<Edge>) -> (Vec<Vec<i32>>, Vec<Vec<i32>>) {
    let n = num_vertices(graph);
    let mut dist: Vec<Vec<i32>> = Vec::new();
    let mut pred: Vec<Vec<i32>> = Vec::new();

    for i in 0..n {
        let mut dist_row = vec![std::i32::MAX; n];
        dist_row[i] = 0;
        let mut pred_row = vec![-1; n];
        dist.push(dist_row);
        pred.push(pred_row);
    }

    for e in graph.iter() {
        let u = e.source;
        let v = e.destination;
        dist[u][v] = e.weight;
        pred[u][v] = u as i32;
    }

    for k in 0..n {
        for i in 0..n {
            if dist[i][k] != std::i32::MAX {
                for j in 0..n {
                    let newLen: i64 = dist[i][k] as i64 + dist[k][j] as i64;

                    if newLen < dist[i][j] as i64 {
                        dist[i][j] = newLen as i32;
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
    }

    (dist, pred)
}

fn main() {
    let mut edges: LinkedList<Edge> = LinkedList::new();
    let data = [[0,1,2], [0,4,4], [1,2,3], [2,3,5], [2,4,1], [3,0,8], [4,3,7]];
    for e in data.iter() {
        let edge = Edge { source: e[0], destination: e[1], weight: e[2] as i32 };
        edges.push_front(edge);
    }

    let (dist, pred) = floyd_warshall(&edges);
    println!("{:?}", dist);
    println!("{:?}", pred);
}
