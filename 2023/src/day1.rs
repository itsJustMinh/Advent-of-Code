use std::collections::HashMap;

pub fn solution(lines: &[String]) {
    println!("part1: {}", part1(lines));
    println!("part2: {}", part2(lines));
}

fn part1(lines: &[String]) -> i32 {
    let mut sum = 0;
    for line in lines {
        if let (Some(front), Some(back)) = (
            line.chars().find(|&c| c.is_ascii_digit()),
            line.chars().rev().find(|&c| c.is_ascii_digit()),
        ) {
            let mut num_str = front.to_string();
            num_str.push_str(back.to_string().as_str());
            match num_str.parse::<i32>() {
                Ok(res) => sum += res,
                Err(err) => println!("Couldn't parse {} somehow...", err),
            }
        }
    }

    sum
}

fn part2(lines: &[String]) -> i32 {
    let mut sum = 0;
    let nums = HashMap::from([
        ("zero", "0"),
        ("one", "1"),
        ("two", "2"),
        ("three", "3"),
        ("four", "4"),
        ("five", "5"),
        ("six", "6"),
        ("seven", "7"),
        ("eight", "8"),
        ("nine", "9"),
    ]);

    for line in lines {
        let mut indices = Vec::new();

        if let Some(front_digit_pos) = line.chars().position(|c| c.is_ascii_digit()) {
            indices.push((
                front_digit_pos,
                line.chars().nth(front_digit_pos).unwrap().to_string(),
            ));
        }

        if let Some(back_digit_pos) = line.chars().rev().position(|c| c.is_ascii_digit()) {
            let actual_idx = line.len() - back_digit_pos - 1;
            indices.push((
                actual_idx,
                line.chars()
                    .nth(actual_idx)
                    .unwrap()
                    .to_string(),
            ));
        }

        for key in nums.keys() {
            let mut idxs: Vec<(usize, String)> = line
                .match_indices(key)
                .map(|(k, v)| (k, nums.get(v).unwrap().to_string()))
                .collect();
            indices.append(&mut idxs);
        }
        indices.sort();

        let mut num_str = indices[0].1.clone();
        num_str.push_str(indices[indices.len() - 1].1.as_str());

        match num_str.parse::<i32>() {
            Ok(res) => sum += res,
            Err(_) => println!("Couldn't parse {} somehow...", num_str),
        }
    }

    sum
}
