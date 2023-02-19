def binary_search(list, item):
    low = 0
    high = len(list)

    while low <=high:
        mid = (low + high) // 2
        guess = list[mid]

        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1

    return None


def main():
    arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600]
    number = int(input('Type the number you are looking for: '))

    print(f'The position of {number} is {binary_search(arr, number)}')


if __name__ == '__main__':
    main()