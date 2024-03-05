import sys

def is_sorted(lst):
    return all(lst[i] <= lst[i+1] for i in range(len(lst)-1))

def main():
    # Convert command line arguments (excluding the script name) to integers
    numbers = list(map(int, sys.argv[1:]))
    print("Is the list sorted?:", is_sorted(numbers))

if __name__ == "__main__":
    main()

