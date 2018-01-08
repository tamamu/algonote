use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    let rgb: Vec<usize> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();

    if (rgb[0] * 100 + rgb[1] * 10 + rgb[2]) % 4 == 0 {
        println!("YES");
    } else {
        println!("NO");
    }
}
