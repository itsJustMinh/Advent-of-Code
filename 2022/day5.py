import re
import sys


def parse_stacks(drawing: list[str]) -> list[list[str]]:
    # the first line should now contain the number of stacks there are
    result = [[] for _ in range(int(drawing.pop().strip()[-1]))]

    drawing.reverse()

    for line in drawing:
        crates = line[1::4]
        for idx, crate in enumerate(crates):
            if crate.isalpha():
                result[idx].append(crate)

    return result


def part_1(filename):
    stacks = []

    # simulate the whole process
    with open(filename) as f_in:
        reading_stacks = True
        drawing = []

        for line in f_in:
            line = line.strip('\n')
            if reading_stacks:
                # read in and parse the drawing
                if len(line) == 0:
                    stacks = parse_stacks(drawing)
                    reading_stacks = False
                else:
                    drawing.append(line)
            else:
                # parse the move _ from _ to _ instructions
                num_to_remove, crate_from, crate_to = [int(x) - 1 if idx != 0 else int(
                    x) for idx, x in enumerate(re.sub(r'move |from |to |', '', line).split())]
                
                for _ in range(num_to_remove):
                    stacks[crate_to].append(stacks[crate_from].pop())

    # grab the first letter from each stack
    return ''.join([stack[-1] for stack in stacks])


def part_2(filename):
    stacks = []

    # simulate the whole process
    with open(filename) as f_in:
        reading_stacks = True
        drawing = []

        for line in f_in:
            line = line.strip('\n')
            if reading_stacks:
                # read in and parse the drawing
                if len(line) == 0:
                    stacks = parse_stacks(drawing)
                    reading_stacks = False
                else:
                    drawing.append(line)
            else:
                # parse the move _ from _ to _ instructions
                num_to_remove, stack_from, stack_to = [int(x) - 1 if idx != 0 else int(
                    x) for idx, x in enumerate(re.sub(r'move |from |to |', '', line).split())]

                stacks[stack_to].extend(stacks[stack_from][-num_to_remove:])
                stacks[stack_from] = stacks[stack_from][:-num_to_remove]
                

    # grab the first letter from each stack
    return ''.join([stack[-1] for stack in stacks])


def main(filename: str):
    print(f'Part 1 solution: {part_1(filename)}')
    print(f'Part 2 solution: {part_2(filename)}')


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        filename = input('Enter the file name to read in: ')
        main(filename)
