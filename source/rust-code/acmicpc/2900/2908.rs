// 2908 상수

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let a = input.next().expect("input error");
    let b = input.next().expect("input error");
    let a: String = a.chars().rev().collect();
    let b: String = b.chars().rev().collect();

    match a.cmp(&b) {
        std::cmp::Ordering::Greater => println!("{a}"),
        std::cmp::Ordering::Less => println!("{b}"),
        _ => unreachable!(),
    }
}
