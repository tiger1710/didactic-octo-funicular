// 1715 카드 정렬하기

use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");

    let mut heap: BinaryHeap<Reverse<usize>> = input
        .split_whitespace()
        .skip(1)
        .map(|str| Reverse(str.parse().expect("can't parse")))
        .collect();

    let mut ans = 0;
    while let (Some(Reverse(i)), Some(Reverse(k))) = (heap.pop(), heap.pop()) {
        ans += i + k;
        heap.push(Reverse(i + k));
    }
    println!("{ans:?}");
}
