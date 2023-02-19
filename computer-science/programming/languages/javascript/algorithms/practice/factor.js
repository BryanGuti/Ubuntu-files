function factor(numbers) {
    let first = 3;
    const factor = numbers.map(number => {
        let fact = number / first;
        first++;
        return fact;
    });
    console.log(factor)

    const isFactor = factor.every(number => number === factor[0]);

    return isFactor ? factor[0] : false;
}

console.log(factor([27, 36, 45, 54, 63, 72]))