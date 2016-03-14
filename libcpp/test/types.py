import ila

t1 = ila.Type()
s1 = str(t1)
assert s1 == '(type invalid)'
print s1

t2 = ila.Type(ila.Types.BOOL)
s2 = str(t2)
assert s2 == '(type bool)'
print s2

s3 = str(ila.Types.BOOL)
assert s3 == 'BOOL'
print s3

