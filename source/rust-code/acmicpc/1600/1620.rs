// 1620 나는야 포켓몬 마스터 이다솜

use std::io::{self, Write, BufWriter, Read};
use std::collections::HashMap;

fn main() {
    let mut input = String::new();
    let mut output = BufWriter::new(io::stdout());
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read line");

    let mut input = input.split_whitespace();

    let n: usize = input.next().expect("input error").parse().expect("parse error");
    let m: usize = input.next().expect("input error").parse().expect("parse error");

    let mut num2name: HashMap<usize, &str> = HashMap::new();
    let mut name2num: HashMap<&str, usize> = HashMap::new();

    for i in 0..n {
        let poketmon = input.next().expect("input error");
        num2name.insert(i + 1, poketmon);
        name2num.insert(poketmon, i + 1);
    }

    for _ in 0..m {
        let question = input.next().expect("input error");
        if let Ok(num) = question.parse::<usize>() {
            let name = num2name.get(&num).expect("find error");
            writeln!(output, "{name}").expect("write error");
        } else {
            let index = name2num.get(question).expect("find error");
            writeln!(output, "{index}").expect("write error");
        }
    }
}
