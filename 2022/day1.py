import sys

def part_1(filename):
    max_calories = 0

    with open(filename) as f_in:
        calories = 0
        for line in f_in:
            line = line.strip()
            if line:
                calories += int(line)
            else:
                max_calories = max(calories, max_calories)
                calories = 0

    max_calories = max(calories, max_calories)
    return max_calories

def part_2(filename):
    biggest_calories = []
    
    with open(filename) as f_in:
        calories = 0

        # will read in the last line, but not append to biggest_calories
        for line in f_in:
            line = line.strip()
            if line:
                calories += int(line)
            else:
                biggest_calories.append(calories)

                if len(biggest_calories) > 3:
                    biggest_calories.sort(reverse=True)
                    biggest_calories = biggest_calories[:3]

                calories = 0
        
        biggest_calories.append(calories)
        biggest_calories.sort(reverse=True)
        return sum(biggest_calories[:3])


def main(filename: str):
    print(f'Part 1 solution: {part_1(filename)}')
    print(f'Part 2 solution: {part_2(filename)}')


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        filename = input('Enter the file name to read in: ')
        main(filename)
