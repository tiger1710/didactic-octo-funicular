// 3052 나머지

use std::collections::HashSet;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let map: HashSet<_> = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("parse error") % 42)
        .collect();
    let remainder = map.len();
    println!("{remainder}");
}
