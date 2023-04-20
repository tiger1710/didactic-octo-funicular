// 1655 가운데를 말해요

use std::cmp::Reverse;
use std::fmt::Write;
use std::collections::BinaryHeap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");

    let input: Vec<isize> = input
        .split_whitespace()
        .skip(1)
        .filter_map(|str| str.parse().ok())
        .collect();

    let mut min_heap = BinaryHeap::new();
    let mut max_heap = BinaryHeap::new();

    if let Some(first) = input.first() {
        max_heap.push(first);
        writeln!(output, "{first}").expect("write error");
    }

    for n in &input[1..] {
        if max_heap.peek().expect("max_heap is empty") < &n {
            min_heap.push(Reverse(n));
        } else {
            max_heap.push(n);
        }

        if max_heap.len() < min_heap.len() {
            let min = min_heap.pop().expect("min_heap is empty").0;
            max_heap.push(min);
        } else if max_heap.len() > min_heap.len() + 1 {
            let max = max_heap.pop().expect("max_heap is empty");
            min_heap.push(Reverse(max));
        }

        let median = max_heap.peek().expect("max_heap is empty");
        writeln!(output, "{median}").expect("write error");
    }
    print!("{output}");
}
