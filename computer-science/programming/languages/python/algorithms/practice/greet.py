import sys

def main():
    # if (len(argv) > 1):
    #     # for i in range(1, len(argv)):
    #     #     print(f"Hello, {argv[i]}")
    #     for arg in argv[1:]: print(f"Hello, {arg}")
    # else: print("Hello, world")
    if len(sys.argv) < 2:
        print("Missing command-line argument")
        sys.exit(1)

    for arg in sys.argv[1:]:
        print(f"Hello, {arg}")

    sys.exit(0)

if __name__ == '__main__':
    main()