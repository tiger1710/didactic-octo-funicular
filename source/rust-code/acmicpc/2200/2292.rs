// 2292 벌집

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n: usize = input.next().expect("input error");
    
    let mut i = 1;
    let mut sum = 1;
    while sum < n {
        sum += 6 * i;
        i += 1;
    }
    println!("{i}");
}