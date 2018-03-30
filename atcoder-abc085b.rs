use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let n: usize = buf.trim().parse().unwrap();

    let mut d: Vec<usize> = Vec::new();

    for _i in 0..n {
        buf = String::new();
        stdin.read_line(&mut buf).unwrap();
        d.push(buf.trim().parse().unwrap());
    }

    d.sort();
    d.dedup();

    println!("{}", d.len());
}
