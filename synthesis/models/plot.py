import itertools
import sys
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats.mstats import gmean

def dumpList(data):
    for d, t1, t2 in data:
        print '%-20s %6.2f %6.2f' % (d, t1, t2)

def read8051():
    filename = 'times/8051.txt'
    flag = 0
    data = []
    for line in open(filename, 'rt'):
        line = line.strip()
        if not line:
            continue

        if flag == 0:
            state = line
        elif flag == 1 or flag == 3:
            t_str = line.split()
            assert t_str[0] == 'time:'
            assert len(t_str) == 2
            if flag == 1:
                t_en = float(t_str[1])
            else:
                t_dis = float(t_str[1])
                state = '8051_' + state
                data.append((state, t_en, t_dis))
        else:
            assert flag == 2
            assert state == line

        flag = (flag + 1) & 0x3

    data.sort()
    return data

def readACC(name, filename, singleline):
    flag = 0
    data = {}
    for line in open(filename, 'rt'):
        line = line.strip()
        if not line:
            continue
        
        if not singleline:
            if flag == 0:
                state = line
            else:
                t = float(line)
                data[name + '_' + state] = t
            flag = (flag + 1) & 1
        else:
            words = line.split()
            assert len(words) == 2
            data[name + '_' + words[0]] = float(words[1])

    return data

def combine(d1, d2):
    assert len(d1) == len(d2)
    data = []
    for k in sorted(d1.keys()):
        data.append((k, d1[k], d2[k]))

    return data

def readBoth(name, fn1, fn2, singleline=False):
    t1 = readACC(name, fn1, singleline)
    t2 = readACC(name, fn2, singleline)
    return combine(t1, t2)

def plot(data):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.set_xscale('log')
    ax.set_yscale('log')
    minxy, maxxy = 0.01, 20000
    ax.set_xlim(minxy, maxxy)
    ax.set_ylim(minxy, maxxy)
    diagx = [minxy, maxxy]
    diagy = [minxy, maxxy]
    ax.plot(diagx, diagy, 'b-')
    ax.set_xlabel('Execution time of parameterized synthesis algorithm (seconds)', fontsize=14)
    ax.set_ylabel('Execution time of baseline algorithm (seconds)', fontsize=14)
    
    speedups = []
    fdata = []

    markers = ['s', '^', 'v', '>', 'x', 'o']
    colors = ['b', 'g', 'c', 'y', 'm', 'r']
    for c, m, d in itertools.izip(colors, markers, data):
        ens, dis = [x[1] for x in d], [y[2] for y in d]
        fdata += [(name, ten, tdis) for (name, ten, tdis) in d if ten >= 1 or tdis >= 1]
        # add .0001 to avoid division by zero
        name = d[0][0]
        name = name[:name.find('_')]
        print name
        print min(ens), max(ens), min(ens), max(dis)
        ax.scatter(ens, dis, marker=m, color=c, label=name)

    ax.grid(True, which='major')
    ax.legend(loc='lower right', scatterpoints=1)

    speedups += [ts[2] / ts[1] for ts in fdata] 
    for d in fdata:
        if d[2] / d[1] > 10:
            print d, (d[2]+1e-4) / (d[1]+1e-4)
    print gmean(speedups), np.average(speedups), max(speedups)

    plt.savefig('times.png')
    plt.savefig('times.pdf')
    plt.show()

if __name__ == '__main__':
    oc8051 = read8051()
    aes1 = readBoth('aes-py', 'times/aes-times-py-en.txt', 'times/aes-times-py-dis.txt')
    aes2 = readBoth('aes-py-uinst', 'times/aes-times-py-uinst-en.txt', 'times/aes-times-py-uinst-dis.txt')
    aes3 = readBoth('aes-verilog-uinst', 'times/aes-times-rtl-uinst-en.txt', 'times/aes-times-rtl-uinst-dis.txt', True)
    sha1 = readBoth('sha1-py', 'times/sha-py-times-en.txt', 'times/sha-py-times-dis.txt', True)
    sha2 = readBoth('sha1-py-uinst', 'times/sha-py-uinst-times-en.txt', 'times/sha-py-uinst-times-dis.txt', True)

    dumpList(oc8051)
    dumpList(aes1)
    dumpList(aes2)
    dumpList(aes3)
    dumpList(sha1)
    dumpList(sha2)

    data = [oc8051, aes1, aes2, aes3, sha1, sha2]
    plot(data)

