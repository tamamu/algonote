use std::io;
 
fn main() {
	let stdin = io::stdin();
    let mut buf = String::new();
    
    stdin.read_line(&mut buf).unwrap();
    let xab: Vec<isize> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();

    if -xab[0] <= xab[1] - xab[2]  {
        if xab[1] - xab[2] >= 0 {
            println!("delicious");
        } else {
    	    println!("safe");
    	}
    } else {
    	println!("dangerous");
    }
}
