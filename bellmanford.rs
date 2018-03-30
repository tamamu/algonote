// BellmanFord

use std::collections::LinkedList;
use std::collections::HashMap;

#[derive(Debug)]
struct Vertex {
    distance: i32,
    predecessor: Option<String>
}

struct Edge {
    weight: i32,
    source: String,
    destination: String
}

fn bellman_ford(vertices: &mut HashMap<String, Vertex>, edges: LinkedList<Edge>, source: String) {
    // Initialize the graph
    for (label, vertex) in vertices.iter_mut() {
        if *label == source {
            vertex.distance = 0;
        } else {
            vertex.distance = 9999;
        }
        vertex.predecessor = None;
    }

    // Iterate
    for i in 1..vertices.len()-1 {
        for uv in edges.iter() {
            let mut ud;
            {
                let u = vertices.get(&uv.source).unwrap();
                ud = u.distance;
            }
            let v = vertices.get_mut(&uv.destination);
            v.map(|_v|{
                if _v.distance > ud + uv.weight {
                    _v.distance = ud + uv.weight;
                    _v.predecessor = Some(uv.source.clone());
                }
            });
        }
    }

    // Check
    for uv in edges.iter() {
        let u = vertices.get(&uv.source);
        let v = vertices.get(&uv.destination);
        u.map(|_u|{
            v.map(|_v|{
                if _u.distance + uv.weight < _v.distance {
                    panic!("Graph contains a negative-weight cycle");
                }
            });
        });
    }
}

fn main() {
    let mut vertices: HashMap<String, Vertex> = HashMap::new();
    let mut edges: LinkedList<Edge> = LinkedList::new();

    let start = Vertex { distance: 9999, predecessor: None };
    vertices.insert(String::from("0"), start);

    for i in 1..10 {
        let w = 0 + i * 7 % 4;
        let s = i.to_string();
        //let d = (i * 4 % 10).to_string();
        let d = ((i + 1) % 10).to_string();
        let v = Vertex { distance: 9999, predecessor: None };
        let e = Edge { weight: w, source: s.clone(), destination: d };
        vertices.insert(s, v);
        edges.push_front(e);
    }

    bellman_ford(&mut vertices, edges, String::from("5"));
    println!("{:?}", vertices);
    let mut pre = &vertices.get("0").unwrap().predecessor;
    while let &Some(ref source) = pre {
        print!("{} ", source);
        pre = &vertices.get(source).unwrap().predecessor;
    }
}
