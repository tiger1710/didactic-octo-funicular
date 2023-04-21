// 10998 A×B

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let multiplication = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("parse error"))
        .fold(1, |acc, x| acc * x);
    println!("{multiplication}");
}
