// 10814 나이순 정렬

use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let input: Vec<_> = input.split_whitespace().skip(1).collect();
    let mut v: Vec<_> = input.chunks(2).enumerate().map(|(i, chunk)| {
        (chunk[0].parse::<usize>().expect("parse error"), i, chunk[1])
    }).collect();
    v.sort();


    for (age, _, name) in v {
        writeln!(output, "{age} {name}").expect("Failed to write to output");
    }

    println!("{output}");
}
