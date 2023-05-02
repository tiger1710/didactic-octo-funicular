// 4949 균형잡힌 세상

use std::io::{self, Read};
// use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");


    for line in input.lines() {
        let mut stack = Vec::new();
        let mut is_balanced = true;
        if line == "." {
            break;
        }
        for c in line.chars() {
            match c {
                '(' | '[' => stack.push(c),
                ')' => {
                    if stack.pop() != Some('(') {
                        is_balanced = false;
                        break;
                    }
                },
                ']' => {
                    if stack.pop() != Some('[') {
                        is_balanced = false;
                        break;
                    }
                },
                _ => (),
            }
        }
        if is_balanced && stack.is_empty() {
            output.push_str("yes\n");
        } else {
            output.push_str("no\n");
        }
    }

    println!("{output}");
}
