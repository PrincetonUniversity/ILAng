import ila
import string
import random

def rand_varname(n=12):
    firstchars = string.ascii_letters + '_'
    restchars  = string.ascii_letters + string.digits + '_'

    first = random.choice(firstchars)
    rest = ''.join(random.choice(restchars) for _ in range(n-1))
    return first+rest

def assert_notequal(*arr):
    for i in xrange(len(arr)):
        xs = arr[i]
        for j in xrange(len(arr)):
            ys = arr[j]
            if i != j:
                for x in xs:
                    for y in ys:
                        assert not x.equal(y)
def main():
    c = ila.Abstraction("test")

    # create a bunch of boolean variables.
    boolvars = []
    varnames = set()
    for i in xrange(8):
        # make sure variable name is unique
        while True:
            varname = rand_varname()
            if varname not in varnames:
                break
        varnames.add(varname)

        bv = c.bit(varname)
        boolvars.append(bv)
        assert bv.name == varname

    # create boolean constants.
    boolcnsts = []
    for i in xrange(4):
        boolcnsts.append(c.bool(random.choice([True, False])))
        boolcnsts.append(c.bool(random.randint(0, 3)))

    # check equality of boolean constants.
    for bi in boolcnsts:
        assert str(bi) == 'true' or str(bi) == 'false'
        for bj in boolcnsts:
            assert str(bj) == 'true' or str(bj) == 'false'
            if str(bi) == str(bj):
                assert bi.equal(bj)
            else:
                assert not bi.equal(bj)

    # check equality of the variables.
    for i in xrange(len(boolvars)):
        for j in xrange(len(boolvars)):
            if i == j: assert boolvars[i].equal(boolvars[j])
            else: assert not boolvars[i].equal(boolvars[j])

    # create some bitvector variables.
    bvvars = []
    varnames = set()
    for i in xrange(8):
        # make sure variable name is unique
        while True:
            varname = rand_varname()
            if varname not in varnames:
                break
        varnames.add(varname)

        sz = random.choice([4, 8, 16, 32])
        bv = c.reg(varname, sz)
        bvvars.append(bv)
        assert bv.name == varname
        assert sz == bv.type.bitwidth

    # check equality of bitvector variables
    for i in xrange(len(bvvars)):
        for j in xrange(len(bvvars)):
            if i == j:
                assert bvvars[i].equal(bvvars[j])
            else:
                assert not bvvars[i].equal(bvvars[j])

    # create bitvector constants.
    bvals = []
    for i in xrange(8):
        sz = random.choice([4, 8, 16, 32])
        num = random.randint(0, (1<<(sz-1)) - 1)
        bv1 = c.const(num, sz)
        bv2 = c.const(num, sz)
        assert bv1.equal(bv2)
        bvals.append(bv1)
        bvals.append(bv2)
        assert bv1.value == num
        assert bv2.value == num

    for i in xrange(len(bvals)):
        bi = bvals[i]
        for j in xrange(len(bvals)):
            bj = bvals[j]
            if bi.type.bitwidth == bj.type.bitwidth and bi.value == bj.value:
                assert bi.equal(bj)
            else:
                assert not bi.equal(bj)


    assert_notequal(boolcnsts, boolvars, bvvars, bvals)

if __name__ == '__main__':
    main()
