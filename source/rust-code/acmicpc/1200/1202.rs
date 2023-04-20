// 1202 보석 도둑

use std::collections::BinaryHeap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n = input.next().expect("input error");
    let k = input.next().expect("input error");

    let mut gem  = Vec::new();
    let mut bag  = Vec::new();

    (0..n).for_each(|_| {
        let m = input.next().expect("input error");
        let v = input.next().expect("input error");
        gem.push((m, v));
    });
    (0..k).for_each(|_| {
        let c = input.next().expect("input error");
        bag.push(c);
    });
    gem.sort();
    bag.sort();

    let mut ans = 0usize;
    let mut heap = BinaryHeap::new();
    let mut gem_iter = gem.iter().peekable();
    bag.iter().for_each(|c| {
        while let Some((m, v)) = gem_iter.peek() {
            if m <= c {
                heap.push(v);
                gem_iter.next();
            } else {
                break;
            }
        }

        if let Some(v) = heap.pop() {
            ans += v;
        }
    });

    println!("{ans}");
}
