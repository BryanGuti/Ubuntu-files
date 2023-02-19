function solution(num) {
    const primes = []

    if (num === 1) return primes;

    for (let i = 2; i <= num; i++){
        for (let j = 2; j <= num; j++){
            if (i % j > 0) continue;
            if ((i % j === 0) && (i > j)) break;
            primes.push(i);
        }
    }
    return primes;
}

console.log(solution(19));
console.log('🔥');