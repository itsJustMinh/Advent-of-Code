import sys


def part_1(filename):
    score = 0

    with open(filename) as f_in:
        for line in f_in:
            opponent, you = line.strip().split()

            if you == 'X':
                score += 1
                score += 3 if opponent == 'A' else 0
                score += 6 if opponent == 'C' else 0
            elif you == 'Y':
                score += 2
                score += 3 if opponent == 'B' else 0
                score += 6 if opponent == 'A' else 0
            elif you == 'Z':
                score += 3
                score += 3 if opponent == 'C' else 0
                score += 6 if opponent == 'B' else 0

        return score


def part_2(filename):
    score = 0

    with open(filename) as f_in:
        for line in f_in:
            opponent, you = line.strip().split()

            if you == 'X':
                score += 0
                if opponent == 'A':
                    score += 3
                elif opponent == 'B':
                    score += 1
                else:
                    score += 2

            elif you == 'Y':
                score += 3
                if opponent == 'A':
                    score += 1
                elif opponent == 'B':
                    score += 2
                else:
                    score += 3

            else:
                score += 6
                if opponent == 'A':
                    score += 2
                elif opponent == 'B':
                    score += 3
                else:
                    score += 1

        return score


def main(filename: str):
    print(f'Part 1 solution: {part_1(filename)}')
    print(f'Part 2 solution: {part_2(filename)}')


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        filename = input('Enter the file name to read in: ')
        main(filename)
