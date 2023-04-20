// 1008 A/B

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");
    let mut input = input.split_whitespace().map(|str| str.parse().expect("can't parse"));
    let a: f64 = input.next().unwrap();
    let b = input.next().unwrap();
    let ans = a / b;

    println!("{ans}");
}
