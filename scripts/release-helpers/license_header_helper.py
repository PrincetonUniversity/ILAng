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
import os


LICENSE_HEADER_DIR = os.path.join('scripts', 'release-helpers', 'misc')


def GetLicenseHeader(file_name):
    """ Return the license header file based on the file extension """

    if not os.path.exists(file_name) or not os.path.isfile(file_name):
        print('File {} not found.'.format(file_name))
        return None

    _, ext = os.path.splitext(file_name)

    if ext in ['.cc', '.cpp', '.h', '.hpp']:
        return os.path.join(LICENSE_HEADER_DIR, 'license_header.h.in')

    elif ext in ['.py']:
        return os.path.join(LICENSE_HEADER_DIR, 'license_header.py.in')

    elif ext in ['.sh']:
        return os.path.join(LICENSE_HEADER_DIR, 'license_header.sh.in')

    else:
        # add here to support new file formats
        return None


def CheckLicenseHeader(file_name, header_file):
    """ Check if already has the license header """

    with open(header_file, 'r') as f_header:
        # read header file content
        header = f_header.read()

        with open(file_name, 'r') as f_target:
            # read target file content
            target = f_target.read()

            # compare
            if len(target) < len(header):
                return False
            else:
                return target[:len(header)] == header


def UpdateFileWithLicenseHeader(file_name, header_file, add):
    """ Update the file (add/erase) w.r.t. the license header """

    with open(file_name, 'r') as fr:
        original = fr.read()

    with open(header_file, 'r') as fr:
        header = fr.read()

    with open(file_name, 'w') as fw:
        if add:
            fw.write(header)
            fw.write(original)
        else:
            fw.write(original[len(header):])


def VisitFile(file_name, args):
    """ Check a file and update accordingly """

    header = GetLicenseHeader(file_name)
    if not header:
        return None

    has_header = CheckLicenseHeader(file_name, header)

    if has_header and args.erase:
        print('Remove header from {}'.format(file_name))
        if not args.dry:
            UpdateFileWithLicenseHeader(file_name, header, False)

    elif not has_header and not args.erase:
        print('Add header to {}'.format(file_name))
        if not args.dry:
            UpdateFileWithLicenseHeader(file_name, header, True)

    else:
        pass


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Check and update (add/erase) license header')

    # required arguments
    parser.add_argument('path', type=str, help='path to file/dir')

    # optional arguments
    parser.add_argument('-d', '--dry', action='store_true',
                        help='dry run -- only listing the files')
    parser.add_argument('-e', '--erase', action='store_true',
                        help='erase header (default: add)')

    args = parser.parse_args()

    if os.path.isdir(args.path):
        for root, _, files in os.walk(args.path):
            for f in files:
                VisitFile(os.path.join(root, f), args)

    elif os.path.isfile(args.path):
        VisitFile(args.path, args)
