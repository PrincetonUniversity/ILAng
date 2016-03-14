import ila

def main():
    n = ila.Node(ila.Type(ila.Types.BOOL))
    n.setName('test passed')
    print n.getName()
    print n.type
    n.doSomething()


if __name__ == '__main__':
    main()
