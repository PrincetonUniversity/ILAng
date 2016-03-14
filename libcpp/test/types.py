import ila

# create each type
t1 = ila.Type()
s1 = str(t1)
assert s1 == '(type invalid)'
print s1

t2 = ila.Type(ila.Types.BOOL)
s2 = str(t2)
assert s2 == '(type bool)'
print s2

# create bitvector type.
t4 = ila.Type(ila.Types.BITVECTOR, 16)
s4 = str(t4)
assert s4 == '(type bitvector 16)'
print s4

# create a mem type.
t5 = ila.Type(ila.Types.MEM, 8, 8)
s5 = str(t5)
assert s5 == '(type mem 8 8)'
print s5

s3 = str(ila.Types.BOOL)
assert s3 == 'BOOL'
print s3

s3 = str(ila.Types.BITVECTOR)
assert s3 == 'BITVECTOR'
print s3

s3 = str(ila.Types.MEM)
assert s3 == 'MEM'
print s3

# check for type exceptions.
try:
    t3 = ila.Type(ila.Types.BITVECTOR)
except TypeError:
    print 'caught exception trying to construct a bitvector type without a size.'

try:
    t4 = ila.Type(ila.Types.MEM, 16)
except TypeError:
    print 'caught exception trying to construct a memory type without addr and data sizes.'

# try out the nonzero operator.
assert not t1
print '__nonzero__ test1 works.'
assert t2
print '__nonzero__ test2 works.'
assert not not t4
print '__nonzero__ test3 works.'
assert not not not t1
print '__nonzero__ test4 works.'
