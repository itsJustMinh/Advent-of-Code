import sys


def part_1(filename):
    num_distinct = 4
    results = []
    with open(filename) as f_in:
        # in the actual dataset, there's only one line, but for my test
        # there are multiple test lines
        for line in f_in:
            line = line.strip()
            for idx in range(len(line) - num_distinct):
                if len(set(line[idx:idx + num_distinct])) == num_distinct:
                    results.append(idx + num_distinct)
                    break
    return results


def part_2(filename):
    num_distinct = 14
    results = []
    with open(filename) as f_in:
        # in the actual dataset, there's only one line, but for my test
        # there are multiple test lines
        for line in f_in:
            line = line.strip()
            for idx in range(len(line) - num_distinct):
                if len(set(line[idx:idx + num_distinct])) == num_distinct:
                    results.append(idx + num_distinct)
                    break
    return results


def main(filename: str):
    print(f'Part 1 solution: {part_1(filename)}')
    print(f'Part 2 solution: {part_2(filename)}')


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        filename = input('Enter the file name to read in: ')
        main(filename)
