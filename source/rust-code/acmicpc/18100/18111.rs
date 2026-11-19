// 18111 마인크래프트

use std::io::{self, Read};

fn calc_time(map: &[usize], mut b: usize, h: usize) -> usize {
    use std::cmp::Ordering;

    let mut time = 0;
    for m in map.iter() {
        match m.cmp(&h) {
            Ordering::Less => {
                if h - m <= b {
                    b -= h - m;
                    time += h - m;
                } else {
                    return usize::MAX;
                }
            },
            Ordering::Greater => {
                b += m - h;
                time += (m - h) * 2
            },
            _ => {},
        }
    }

    time
}

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let _: usize = input.next().expect("input error");
    let _ = input.next().expect("input error");
    let b = input.next().expect("input error");

    let mut map: Vec<usize> = input.collect();
    map.sort_by(|a, b| b.cmp(a));
    let &min = map.iter().min().expect("map is empty");
    let &max = map.iter().max().expect("map is empty");

    let mut min_time = usize::MAX;
    let mut max_height = 0;

    for h in min..=max {
        let time = calc_time(&map, b, h);
        if time <= min_time {
            min_time = time;
            max_height = max_height.max(h);
        }
    }

    println!("{min_time} {max_height}");
}
