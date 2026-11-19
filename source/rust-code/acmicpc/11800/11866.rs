// 11866 요세푸스 문제 0

use std::collections::VecDeque;
use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n = input.next().expect("input error");
    let k = input.next().expect("input error") - 1usize;
    let mut buf: VecDeque<_> = (1..=n).collect();
    
    output.push_str("<");
    while !buf.is_empty() {
        for _ in 0..k {
            let tmp = buf.pop_front().expect("buf is empty");
            buf.push_back(tmp);
        }
        let pop = buf.pop_front().expect("buf is empty");
        write!(output, "{pop}, ").expect("write error");
    }

    output.pop();
    output.pop();
    output.push('>');
    println!("{output}");
}
