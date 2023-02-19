def is_prime(number):
    if number <= 1: return False

    for i in range(2, number + 1):
        if number % i > 0: continue
        if number % i == 0 and i < number: return False
        return True

def main():
    try:
        number = int(input("Type a number: "))

        if is_prime(number):
            print("It's prime number!!!")
            return
        print("It's not prime number :(")
    except:
        print("You must type an integer value\n")
        main()

if __name__ == '__main__':
    main()