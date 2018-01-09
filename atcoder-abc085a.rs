use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    print!("2018");
    println!("{}", buf.split_at(4).1);
}
