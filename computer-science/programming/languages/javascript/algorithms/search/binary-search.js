function binarySearch(list, item) {
    let low = 0;
    let high = list.length;

    while (low <= high) {
        let mid = parseInt((low + high) / 2);
        let guess = list[mid];

        if (guess === item) {
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return null;
}

function main() {
    const arr = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000];
    const num = 90

    console.log(`The position of ${num} is ${binarySearch(arr, num)}`)
}

main()