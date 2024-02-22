// 1085 직사각형에서 탈출

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let c: usize = input.next().expect("input error");
    let r = input.next().expect("input error");
    let w = input.next().expect("input error");
    let h = input.next().expect("input error");

    let min = c.min(w - c).min(r).min(h - r);
    println!("{min}");
}
