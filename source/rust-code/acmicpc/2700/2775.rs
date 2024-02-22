// 2775 부녀회장이 될테야

use std::io::{self, Read};
use std::fmt::Write;

fn go(dp: &mut Vec<Vec<usize>>, k: usize, n: usize) -> usize {
    if dp[k][n] != 0 {
        return dp[k][n];
    }

    if k == 0 || n == 0 {
        dp[k][n] = n + 1;
        return dp[k][n];
    }

    dp[k][n] = go(dp, k - 1, n) + go(dp, k, n - 1);

    dp[k][n]
}

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input.split_whitespace().map(|str| str.parse().expect("parse error"));
    let t: usize = input.next().expect("input error");

    let mut v = vec![vec![0usize; 14]; 15];
    for _ in 0..t {
        let k: usize = input.next().expect("input error");
        let n: usize = input.next().expect("input error") - 1;

        let ans = go(&mut v, k, n);
        writeln!(output, "{ans}").expect("Failed to write to output");
    }

    print!("{output}");
}
