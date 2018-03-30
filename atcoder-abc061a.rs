use std::io;

fn main() {
        let stdin = io::stdin();
        let mut buf = String::new();

        stdin.read_line(&mut buf).unwrap();

        let abc: Vec<i32> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();

        if abc[0] <= abc[2] && abc[2] <= abc[1] {
                println!("Yes");
        } else {
                println!("No");
        }
}
