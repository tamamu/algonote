use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin
        .read_line(&mut buf)
        .unwrap();

    let n: usize = buf.trim().parse().unwrap();
    println!("{}", 24 + (24 - n));
}
