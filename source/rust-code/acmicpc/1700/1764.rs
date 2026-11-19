// 1764 듣보잡

use std::io::{self, Write, BufWriter, Read};
use std::collections::HashSet;

fn main() {
    let mut input = String::new();
    let mut output = BufWriter::new(io::stdout());
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read line");

    let mut input = input.split_whitespace();

    let n: usize = input.next().expect("input error").parse().expect("parse error");
    let _: usize = input.next().expect("input error").parse().expect("parse error");

    let dj: HashSet<&str> = input.by_ref().take(n).collect();
    let bj: HashSet<&str> = input.collect();
    let mut dbj: Vec<&&str> = dj.intersection(&bj).map(|x| x).collect();
    dbj.sort();

    let len = dbj.len();
    writeln!(output, "{len}").expect("write error");
    for name in dbj {
        writeln!(output, "{name}").expect("write error");
    }
}
