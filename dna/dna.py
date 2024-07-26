import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage:")
        sys.exit(1)

    # TODO: Read database file into a variable
    rows = []
    i = 0
    with open(sys.argv[1], 'r') as file:
        firster = file.readline()
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
            i += 1

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        content = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    longests = []
    k = 0
    for item in firster[1 : ]:
        longest = longest_match(content, item)
        longests.append(longest)
        k += 1

    # TODO: Check database for matching profiles
    l = 0
    for p in range(1, i, 1):
        l = 0
        for j in range(k):
            if longests[j] != list(rows[p].value())[j]:
                break
            else:
                l += 1
        if l == k:
            print(f"{rows[p][0]}")
            sys.exit(0)
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
