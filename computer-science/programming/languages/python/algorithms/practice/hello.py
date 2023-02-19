def main():
    name = input("What's your name: ")
    other_name = name
    other_name = 'Ramiro'
    print("Hello, ", name, ", this is programming's world", sep="")
    print("Hello, " + name + ", this is programming's world")
    print(f"Hello, {name}, this is programming's world")
    print(id(name))
    print(id(other_name))

if __name__ == '__main__':
    main()
