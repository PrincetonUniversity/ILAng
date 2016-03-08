import ila

def main():
    n = ila.Node()
    n.setName('test passed')
    print n.getName()
    n.doSomething()


if __name__ == '__main__':
    main()
