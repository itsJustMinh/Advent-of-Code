import sys


def part_1(filename):
    priority_sum = 0

    with open(filename) as f_in:
        for line in f_in:
            rucksack = list(line.strip())
            compartment_one = set(rucksack[:len(rucksack) // 2])
            compartment_two = set(rucksack[len(rucksack) // 2:])

            # there should only be one different character, so just grab it
            intersect = compartment_one.intersection(compartment_two).pop()

            priority_sum += ord(intersect) - ord('A') + \
                26 + 1 if intersect.isupper() else ord(intersect) - ord('a') + 1

    return priority_sum


def part_2(filename):
    badge_priority_sum = 0
    rucksack_group = list()

    with open(filename) as f_in:
        for line in f_in:
            rucksack_group.append(set(line.strip()))

            if len(rucksack_group) == 3:
                intersect = set.intersection(
                    rucksack_group[0], rucksack_group[1], rucksack_group[2]).pop()
                badge_priority_sum += ord(intersect) - ord('A') + \
                    26 + 1 if intersect.isupper() else ord(intersect) - ord('a') + 1
                rucksack_group = list()

    return badge_priority_sum


def main(filename: str):
    print(f'Part 1 solution: {part_1(filename)}')
    print(f'Part 2 solution: {part_2(filename)}')


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        filename = input('Enter the file name to read in: ')
        main(filename)
