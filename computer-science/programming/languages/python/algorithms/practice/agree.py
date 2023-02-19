def main():
    agree = input("Do you agree? ")

    # if agree in ["y", "Y", "Yes", "yes", "YES", "yES", "yeS", "yEs", "YeS", "YEs"]
    agree = agree.lower()

    if agree in ["y", "yes"]: print("Agreed.")
    elif agree in ["n", "no"]: print("Not agreed.")
    else: print(f"{agree} is not an option.")

if __name__ == '__main__':
    main()
