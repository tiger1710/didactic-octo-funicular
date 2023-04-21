// 1546 평균

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let scores: Vec<usize> = input
        .split_whitespace()
        .skip(1)
        .map(|str| str.parse().expect("parse error"))
        .collect();

    let &max = scores.iter().max().expect("scores is empty");

    let sum: f64 = scores
        .iter()
        .map(|&score| score as f64 / max as f64 * 100.0)
        .sum();
    let avg = sum / scores.len() as f64;
    println!("{avg}");
}
