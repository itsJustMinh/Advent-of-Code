import re
import sys


def part_1(filename):
    # this is a really naive solution but i'm too lazy to make a more efficient one
    count = 0

    with open(filename) as f_in:
        for line in f_in:
            a_start, a_end, b_start, b_end = tuple(
                map(lambda x: int(x), (re.split('[-,]', line.strip()))))

            set_a = set([x for x in range(a_start, a_end + 1)])
            set_b = set([x for x in range(b_start, b_end + 1)])

            if set_a.issubset(set_b) or set_b.issubset(set_a):
                count += 1

    return count


def part_2(filename):
    count = 0

    with open(filename) as f_in:
        for line in f_in:
            a_start, a_end, b_start, b_end = tuple(
                map(lambda x: int(x), (re.split('[-,]', line.strip()))))

            # if there's an intersection, then there must be an overlap
            set_a = set([x for x in range(a_start, a_end + 1)])
            set_b = set([x for x in range(b_start, b_end + 1)])

            if len(set.intersection(set_a, set_b)):
                count += 1

    return count


def main(filename: str):
    print(f'Part 1 solution: {part_1(filename)}')
    print(f'Part 2 solution: {part_2(filename)}')


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        filename = input('Enter the file name to read in: ')
        main(filename)
