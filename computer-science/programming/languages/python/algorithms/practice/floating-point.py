def main():
    x = int(input("x: "))
    y = int(input("y: "))

    z = x / y

    print(f"{z:.50f}") # floating point impresision

if __name__ == '__main__':
    main()