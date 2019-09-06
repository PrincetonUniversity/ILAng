#!/usr/bin/python3

import argparse
import distutils.spawn
import os
import os.path
import subprocess

FORMATER = ''


def Format(top):
    if not os.path.exists(top):
        print('dir {0} does not exist'.format(top))
        return

    for root, _, files in os.walk(top):
        for name in files:
            # check if is our source files
            if name[-3:] == '.cc':
                file_path = os.path.join(root, name)
            elif name[-2:] == '.h':
                file_path = os.path.join(root, name)
            else:
                continue

            # format
            subprocess.run([FORMATER, '-i', file_path])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Format files')
    parser.add_argument('--all', action='store_true', help='format all')
    parser.add_argument('--path', type=str, help='top dir to format')
    args = parser.parse_args()

    FORMATER = distutils.spawn.find_executable('clang-format')

    if (args.all or args.path is ''):
        Format('include')
        Format('src')
    else:
        Format(args.path)
