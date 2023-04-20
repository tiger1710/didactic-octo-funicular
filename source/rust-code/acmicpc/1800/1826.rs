// 1826 연료 채우기

use std::cmp::Reverse;
use std::io::{self, Read};
use std::collections::BinaryHeap;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("can't parse"));

    let mut gas = BinaryHeap::new();
    let n: usize = input.next().expect("no input");
    (0..n).for_each(|_| {
        let a = input.next().expect("no input");
        let b = input.next().expect("no input");
        gas.push((Reverse(a), b));
    });
    let l = input.next().expect("no input");
    let mut p = input.next().expect("no input");

    let mut pq = BinaryHeap::new();
    let mut stopped = 0;
    while p < l {
        while let Some(&(Reverse(a), _)) = gas.peek() {
            if a <= p {
                pq.push(gas.pop().unwrap().1);
            } else {
                break;
            }
        }

        if pq.is_empty() {
            println!("-1");
            return;
        }

        p += pq.pop().unwrap();
        stopped += 1;
    }

    println!("{stopped}");
}
