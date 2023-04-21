// 4153 직각삼각형

use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");
    let mut chunks = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    for chunk in chunks.chunks_mut(3) {
        chunk.sort();
        if chunk[0] == 0 {
            break;
        }
        if chunk[0].pow(2) + chunk[1].pow(2) == chunk[2].pow(2) {
            writeln!(output, "right").unwrap();
        } else {
            writeln!(output, "wrong").unwrap();
        }
    }

    print!("{output}");
}
