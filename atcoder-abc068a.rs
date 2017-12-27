use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin
        .read_line(&mut buf)
        .expect("can't read");

    let n: usize = buf.trim().parse().unwrap();
    println!("ABC{}", n);
}
