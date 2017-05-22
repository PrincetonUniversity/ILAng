# this is to use to add _GLOBAL__I_a(); to proper location

with open('vWrapper.c') as fin:
    lines = fin.readlines()

state = 0
with open('vWrapper.c','wt') as fout:
    for line in lines:
        if state == 2 :
            if len(line.split()) == 0:
                line = '  _GLOBAL__I_a();'
            else:
                print 'unexpected content:',line
                exit(1)
        fout.write(line)
    	if state == 0:
    	    if 'unsigned int main(void) {' in line:
    	        state = 1
    	    else:
    	        state = 0
        elif state == 1:
            state = 2
        else:
            state = 0
                
print '[Done]'

