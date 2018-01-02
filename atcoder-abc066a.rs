use std::io;
use std::cmp;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin
        .read_line(&mut buf)
        .unwrap();

    let abc: Vec<usize> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();
    println!("{}", cmp::min(cmp::min(abc[0]+abc[1], abc[1]+abc[2]), abc[0]+abc[2]))
}
