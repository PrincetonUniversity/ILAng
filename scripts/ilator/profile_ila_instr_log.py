import sys

from numpy.core.numeric import extend_all

def profile_ila_log(fname, sortby="avg"):
    logs = open(fname, "r").readlines()
    unit = logs[0].split()[8]
    total_time = dict()
    num_cnt = dict()
    avg_time = dict()
    max_opname_len = 0
    for line in logs:
        split_line = line.split()
        instr_name = split_line[3]
        exec_time = split_line[7]
        if instr_name in total_time:
            num_cnt[instr_name] += 1
            total_time[instr_name] += float(exec_time)
        else:
            num_cnt[instr_name] = 1
            total_time[instr_name] = float(exec_time)
    for key in total_time:
        avg_time[key] = total_time[key] / num_cnt[key]
        max_opname_len = max(len(key), max_opname_len)
    if sortby == "avg":
        print("sorted by avg exec_time")
        sorted_instr = sorted(avg_time.items(), key=lambda x: x[1], reverse=True)
    else:
        print("sorted by total exec_time")
        sorted_instr = sorted(total_time.items(), key=lambda x: x[1], reverse=True)

    for i in sorted_instr:
        print(
            f"{i[0]: <{max_opname_len}}:\t" +
            f"total exec_time: {total_time[i[0]]:.2f} {unit};\t" +
            f"num count: {num_cnt[i[0]]};\t" +
            f"avg. exec_time: {avg_time[i[0]]:.2f} {unit}" 
        )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 profile_ila_instr_log.py [file_path] [sortby]")
        exit(0)
    if len(sys.argv) == 3:
        sortby = sys.argv[2]
    else:
        sortby = "avg"
    profile_ila_log(sys.argv[1], sortby)
