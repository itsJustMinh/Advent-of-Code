pub fn solution(lines: &[String]) {
    println!("part1: {}", part1(lines));
    println!("part2: {}", part2(lines));
}

fn part1(lines: &[String]) -> usize {
    let max_red = 12;
    let max_green = 13;
    let max_blue = 14;

    let mut sum = 0;
    for (idx, line) in lines.iter().enumerate() {
        let game_num = idx + 1;
        let mut valid_game = true;
        let subsets: Vec<&str> = line.split(':').collect::<Vec<&str>>()[1]
            .split(';')
            .map(|subset| subset.trim())
            .collect();
        // dbg!(args);
        for subset in subsets {
            let bags: Vec<&str> = subset.split(',').map(|bag| bag.trim()).collect();

            for bag in &bags {
                let vals = bag.split_at(bag.chars().position(|c| c == ' ').unwrap());
                let num: i32 = vals.0.parse().unwrap();
                // dbg!(num);

                match vals.1.trim() {
                    "red" => {
                        if num > max_red {
                            valid_game = false;
                        }
                    }
                    "green" => {
                        if num > max_green {
                            valid_game = false;
                        }
                    }
                    "blue" => {
                        if num > max_blue {
                            valid_game = false;
                        }
                    }
                    // other => {dbg!(other);},
                    _ => unreachable!(),
                }
            }
        }
        if valid_game {
            sum += game_num;
        }
    }
    sum
}

fn part2(lines: &[String]) -> i32 {
    let mut sum = 0;

    for line in lines {
        let subsets: Vec<&str> = line.split(':').collect::<Vec<&str>>()[1]
            .split(';')
            .map(|subset| subset.trim())
            .collect();

        let mut max_red = 0;
        let mut max_green = 0;
        let mut max_blue = 0;

        for subset in subsets {
            let bags: Vec<&str> = subset.split(',').map(|bag| bag.trim()).collect();

            for bag in &bags {
                let vals = bag.split_at(bag.chars().position(|c| c == ' ').unwrap());
                let num: i32 = vals.0.parse().unwrap();
                // dbg!(num);

                match vals.1.trim() {
                    "red" => max_red = max_red.max(num),
                    "green" => max_green = max_green.max(num),
                    "blue" => max_blue = max_blue.max(num),

                    // other => {dbg!(other);},
                    _ => unreachable!(),
                }
            }
        }

        sum += max_red * max_green * max_blue;
    }
    sum
}
