// 7568 덩치

use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let data: Vec<_> = input
        .lines()
        .skip(1)
        .map(|line| {
            let mut l = line
                .split_whitespace()
                .map(|str| str.parse::<usize>().expect("parse error"));
            (
                l.next().expect("Failed to get x"),
                l.next().expect("Failed to get y"),
            )
        })
        .collect();

    for (lhs_x, lhs_y) in &data {
        let rank = data
            .iter()
            .filter(|(rhs_x, rhs_y)| lhs_x < rhs_x && lhs_y < rhs_y)
            .count()
            + 1;

        writeln!(output, "{rank}").expect("Failed to write to output");
    }

    println!("{output}");
}
