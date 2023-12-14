pub fn solution(lines: &[String]) {
    let mut grid: Vec<Vec<char>> = Vec::new();
    
    for line in lines {
        grid.push(line.chars().collect());
    }

    println!("part1: {}", part1(&grid));
    println!("part2: {}", part2(&grid));
}

fn part1(grid: &Vec<Vec<char>>) -> usize {
    todo!()
}

fn part2(grid: &Vec<Vec<char>>) -> usize {
    todo!()
}
