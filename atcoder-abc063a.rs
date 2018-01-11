use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    let ab: Vec<usize> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();

    let n = ab[0] + ab[1];

    if n >= 10 {
        println!("error");
    } else {
        println!("{}", n);
    }
}
