#!/bin/bash
set -ev
lcov --directory $1 --capture --outputfile ./coverage.info
lcov --remove ./coverage.info '*/extern/*' '*/test/*' '/usr/*' --output-file ./coverage.info
lcov --list ./coverage.info
coveralls-lcov ./coverage.info 

