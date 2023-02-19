import csv

def main():
    # file = open("phonebook.csv", "a")

    # name = input("Name: ")
    # number = input("Number: ")

    # writer = csv.writer(file)
    # writer.writerow([name, number])

    # file.close()

    with open("phonebook.csv", "a") as file: # Pythonic way

        name = input("Name: ")
        number = input("Number: ")

        writer = csv.writer(file)
        writer.writerow([name, number])

        file.close()

if __name__ == '__main__':
    main()