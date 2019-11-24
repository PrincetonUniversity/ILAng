#!/usr/bin/env python3

# ==============================================================================
# MIT License
#
# Copyright (c) 2019 Princeton University
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ==============================================================================


import argparse
import distutils.spawn
import os
import subprocess

CX_FORMATTER = None
PY_FORMATTER = None


def FormatFile(file_name):
    """ Format the file based on its file extension """

    # sanity check
    if not os.path.exists(file_name) or not os.path.isfile(file_name):
        print('File {} not found'.format(file_name))
        return None

    # get the file extension
    _, ext = os.path.splitext(file_name)

    # c++ source/headers
    if ext in ['.cc', '.cpp', '.h', '.hpp']:
        if CX_FORMATTER:
            subprocess.run([CX_FORMATTER, '-i', file_name])

    # PYthon scripts
    elif ext in ['.py']:
        if PY_FORMATTER:
            subprocess.run([PY_FORMATTER, '-i', file_name])

    else:
        # add here to support new file formats
        return None


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Format (in-place) files')
    parser.add_argument('path', type=str, help='path to file/dir')
    args = parser.parse_args()

    CX_FORMATTER = distutils.spawn.find_executable('clang-format')
    PY_FORMATTER = distutils.spawn.find_executable('autopep8')

    if CX_FORMATTER:
        print('Find formatter {} for c++ source/headers'.format(CX_FORMATTER))

    if PY_FORMATTER:
        print('Find formatter {} for Python scripts'.format(PY_FORMATTER))

    if os.path.isdir(args.path):
        for root, _, files in os.walk(args.path):
            for f in files:
                FormatFile(os.path.join(root, f))

    elif os.path.isfile(args.path):
        FormatFile(args.path)
