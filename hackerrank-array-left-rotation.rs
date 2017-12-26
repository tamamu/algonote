use std::io;

fn left_rotate<T: Default>(slice: &[T], idx: usize) -> Vec<&T> {
    let len = slice.len();
    let (a, b) = slice.split_at(idx);
    b.iter().chain(a.iter()).collect()
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin
        .read_line(&mut buf)
        .expect("can't read");
    let p: Vec<usize> = buf.split_whitespace()
        .map(|n| n.parse().unwrap())
        .collect();

    buf = String::new();
    stdin
        .read_line(&mut buf)
        .expect("can't read");
    let mut v: Vec<i32> = buf.split_whitespace()
        .map(|n| n.parse().unwrap())
        .collect();

    let result: Vec<String> = left_rotate(&v, p[1]).iter().map(|x| x.to_string()).collect();
    println!("{}", result.connect(" "));
}
