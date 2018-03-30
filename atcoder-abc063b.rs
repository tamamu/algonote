use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    let mut c: Vec<char> = buf.chars().collect();
    let len = c.len();

    c.sort();
    c.dedup();

    if c.len() == len {
        println!("yes");
    } else {
        println!("no");
    }
}
