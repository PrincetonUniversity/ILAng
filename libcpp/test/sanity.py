import ila

def main():
    n = ila.BitvectorVar("test", 16)
    print n.name
    print n.type
    n.doSomething()


if __name__ == '__main__':
    main()
