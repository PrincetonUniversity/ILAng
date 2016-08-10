import itertools
import sys
import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from scipy.stats.mstats import gmean


from plot import read8051

def main():
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
    print gmspeedup

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

    matplotlib.rcParams.update({'font.size': 16})

    fig = plt.figure(figsize=(8,4))
    ax = fig.add_subplot(111)
    ax.set_yscale('log')
    ax.grid(True, which='major', color='black', linestyle='dashed')
    ax.grid(True, which='minor', color='gray', linestyle='dotted')

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
    ax.set_xticklabels(xlabels, rotation=90)
    ax.legend(('SynPARAM', 'SynCEGIS'), loc='upper left')
    ax.set_ylabel('Time (s)')
    plt.tight_layout()
    plt.savefig('plots/8051times.pdf')

    plt.show()

if __name__ == '__main__':
    main()


