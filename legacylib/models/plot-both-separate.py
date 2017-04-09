import itertools
import sys
import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from scipy.stats.mstats import gmean


from plot import readBoth, read8051

def plot8051(ax):
    data = read8051()
    data.sort(key=lambda p: p[2])
    en_times = {}
    dis_times = {}
    speedup = []
    for k, t_en, t_dis in data:
        en_times[k] = t_en
        dis_times[k] = t_dis
        s = t_dis/t_en
        speedup.append(s)

        print k, t_en, t_dis, s

    gmspeedup = gmean(speedup)
    avgspeedup = np.average(speedup)
    print gmspeedup
    print avgspeedup

    order = [
        '8051_XRAM_DATA_OUT', '8051_XRAM_ADDR',
        '8051_PC', '8051_ACC',
        '8051_DPL', '8051_DPH',
        '8051_PCON', '8051_TCON', '8051_TMOD',
        '8051_TL0', '8051_TH0',
        '8051_TH1', '8051_TL1',
        '8051_SP',
        '8051_P0', '8051_P1', '8051_P2', '8051_P3',
        '8051_SBUF', '8051_SCON',
        '8051_IE', '8051_IP',
        '8051_B', '8051_PSW', '8051_IRAM'
    ]

    bars_en  = []
    bars_dis = []

    for k in order:
        bars_en.append(en_times[k])
        bars_dis.append(dis_times[k])


    ax.set_yscale('log')
    ax.grid(True, which='major')

    x1s = np.arange(float(len(order))) + 0.1
    x2s = np.arange(float(len(order))) + 0.5

    b1s = ax.bar(x1s, bars_en, width=0.4, log=True, color='yellow')
    b2s = ax.bar(x2s, bars_dis, width=0.4, log=True, color='blue')

    xlabels = []
    for o in order:
        n = o[5:]
        if n == 'XRAM_DATA_OUT': n = 'XDAT'
        elif n == 'XRAM_ADDR': n = 'XADR'
        xlabels.append( n )

    ax.set_xticks(x2s)
    ax.set_xticklabels(xlabels, rotation=90, fontsize=14)
    ax.legend(('SynPARAM', 'SynCEGIS'), loc='upper left')
    ax.set_title('(a) 8051 ILA', fontsize=14)
    ax.set_ylabel('Time (s)')

def plotbars(start, ax, data):

    bars_en  = []
    bars_dis = []

    for k, t_en, t_dis in data:
        bars_en.append(t_en)
        bars_dis.append(t_dis)

    N = float(len(data))
    x1s = np.arange(N) + 0.1 + start
    x2s = np.arange(N) + 0.5 + start

    b1s = ax.bar(x1s, bars_en, width=0.4, log=True, color='yellow')
    b2s = ax.bar(x2s, bars_dis, width=0.4, log=True, color='blue')

    return start + N + 1, (start + N/2.0)

def stats(data):
    speedups = []
    for k, t_en, t_dis in data:
        if t_en != 0:
            s = t_dis / t_en
            speedups.append(s)
    print np.average(speedups), gmean(speedups)

def main():
    oc51 = read8051()
    aes1 = readBoth('aes-py', 'times/aes-times-py-en.txt', 'times/aes-times-py-dis.txt')
    aes2 = readBoth('aes-py-uinst', 'times/aes-times-py-uinst-en.txt', 'times/aes-times-py-uinst-dis.txt')
    aes3 = readBoth('aes-verilog-uinst', 'times/aes-times-rtl-uinst-en.txt', 'times/aes-times-rtl-uinst-dis.txt', True)
    sha1 = readBoth('sha1-py', 'times/sha-py-times-en.txt', 'times/sha-py-times-dis.txt', True)
    sha2 = readBoth('sha1-py-uinst', 'times/sha-py-uinst-times-en.txt', 'times/sha-py-uinst-times-dis.txt', True)

    oc51.sort(key=lambda p: p[2])
    aes1.sort(key=lambda p: p[2])
    aes2.sort(key=lambda p: p[2])
    aes3.sort(key=lambda p: p[2])
    sha1.sort(key=lambda p: p[2])
    sha2.sort(key=lambda p: p[2])

    total = aes1 + aes2 + aes3 + sha1 + sha2
    stats(total)

    matplotlib.rcParams.update({'font.size': 16})

    fig = plt.figure(figsize=(8,6))
    ax1 = fig.add_subplot(111)
    plot8051(ax1)
    plt.tight_layout()
    plt.savefig('images/8051times.svg')

    fig = plt.figure(figsize=(8,6))
    ax = fig.add_subplot(111)
    ax.set_yscale('log')
    ax.grid(True, which='major')
    ax.set_title('(b) Accelerator ILAs', fontsize=14)

    start = 1
    start, m1 = plotbars(start, ax, sha2)
    start, m2 = plotbars(start, ax, sha1)
    start, m3 = plotbars(start, ax, aes2)
    start, m4 = plotbars(start, ax, aes3)
    start, m5 = plotbars(start, ax, aes1)

    ax.set_xticks([m1, m2, m3, m4, m5])
    ax.set_xticklabels(['sha-py-uinst', 'sha-py', 'aes-py-uinst', 'aes-verilog-uinst', 'aes-py'], rotation=10)
    ax.set_xlim((0.5,start-0.5))
    ax.legend(('SynPARAM', 'SynCEGIS'), loc='upper left')
    ax.set_ylabel('Time (s)')

    plt.tight_layout()
    plt.savefig('images/acctimes.svg')

if __name__ == '__main__':
    main()



