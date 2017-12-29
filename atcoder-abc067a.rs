use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin
        .read_line(&mut buf)
        .unwrap();

    let d: Vec<usize> = buf.split_whitespace()
        .map(|n| n.parse().unwrap())
        .collect();

    if d[0] % 3 == 0 || d[1] % 3 == 0 || (d[0] + d[1]) % 3 == 0 {
        println!("Possible");
    } else {
        println!("Impossible");
    }
}
