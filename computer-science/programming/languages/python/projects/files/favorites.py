import csv

def main():
    with open("favorites.csv", "r") as file:
# First way

        # reader = csv.reader(file)
        # for row in reader:
        #     print(row[2])

# Second way

        # reader = csv.DictReader(file)
        # for row in reader:
        #     print(f"{row['name']} is {row['age']} years old and programs in {row['language']} language")

# Third way

        # reader = csv.DictReader(file)
        # javascript = 0
        # for row in reader:
        #     if row['language'] == 'javascript':
        #         javascript += 1
        # print(f"{javascript} people like javascript")

# Fourth way

        reader = csv.DictReader(file)
        counts = {}

        for row in reader:
            favorite = row['language']
            if favorite in counts:
                counts[favorite] += 1
                continue
            counts[favorite] = 1

        for language in counts:
            print(f"{language}: {counts[language]}")


if __name__ == '__main__':
    main()