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
        let front_digit_pos = line.chars().position(|c| c.is_ascii_digit());
        let back_digit_pos = line.chars().rev().position(|c| c.is_ascii_digit());

        let mut indices = Vec::new();

        for key in nums.keys() {
            let mut idxs: Vec<(usize, &str)> = line.match_indices(key).collect();
            indices.append(&mut idxs);
        }
        indices.sort();

        let mut num_str: String;

        if indices.is_empty()
            || front_digit_pos.is_some_and(|idx| indices.is_empty() || idx < indices[0].0)
        {
            num_str = line
                .chars()
                .nth(front_digit_pos.unwrap())
                .unwrap()
                .to_string();
        } else {
            num_str = nums.get(indices[0].1).unwrap().to_string();
        }

        if back_digit_pos.is_some_and(|idx| {
            indices.is_empty() || (line.len() - idx - 1) > indices[indices.len() - 1].0
        }) {
            num_str.push_str(
                line.chars()
                    .nth(line.len() - back_digit_pos.unwrap() - 1)
                    .unwrap()
                    .to_string()
                    .as_str(),
            );
        } else {
            num_str.push_str(
                nums.get(indices[indices.len() - 1].1)
                    .unwrap()
            )
        }

        match num_str.parse::<i32>() {
            Ok(res) => sum += res,
            Err(err) => println!("Couldn't parse {} somehow...", err),
        }
    }

    sum
}
