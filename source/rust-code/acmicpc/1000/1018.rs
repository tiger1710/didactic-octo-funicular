// 1018 체스판 다시 칠하기

use std::io::{self, Read};

const BOARD_SIZE: usize = 8;
const W_BOARD: &str = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
const B_BOARD: &str = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");
    let mut input = input.split_whitespace();

    let n = input
        .next()
        .expect("Failed to read n")
        .parse::<usize>()
        .expect("Failed to parse n")
        - BOARD_SIZE
        + 1;
    let m = input
        .next()
        .expect("Failed to read m")
        .parse::<usize>()
        .expect("Failed to parse m")
        - BOARD_SIZE
        + 1;
    let board: Vec<_> = input.collect();

    let mut repaint = BOARD_SIZE * BOARD_SIZE;
    (0..n).for_each(|r| {
        (0..m).for_each(|c| {
            let check = board[r..r + BOARD_SIZE]
                .iter()
                .flat_map(|row| row[c..c + BOARD_SIZE].chars());
            let w_diff = check
                .clone()
                .zip(W_BOARD.chars())
                .filter(|(a, b)| a != b)
                .count();
            let b_diff = check
                .clone()
                .zip(B_BOARD.chars())
                .filter(|(a, b)| a != b)
                .count();
            repaint = repaint.min(w_diff).min(b_diff);
        })
    });

    println!("{repaint}");
}
