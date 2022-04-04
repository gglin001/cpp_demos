#!/usr/bin/env bash

# workdir shuould be ${CMAKE_BINARY_DIR}

# http://ltp.sourceforge.net/coverage/lcov/lcov.1.php

# lcov capture
# use --include pattern or --exclude pattern
# to filter records
lcov --capture -d ./ -o coverage.raw.info --rc lcov_branch_coverage=1 \
    --include "*"

# show captured record
lcov -l coverage.raw.info

# # use --extract pattern
# lcov --extract coverage.raw.info \
#     "*" \
#     -o coverage.info \
#     --rc lcov_branch_coverage=1

# or use --remove pattern
# clean C++ std library
lcov --remove coverage.raw.info \
    "*v1*" \
    -o coverage.info \
    --rc lcov_branch_coverage=1

# show final record
lcov -l coverage.info

# show final record summary
lcov --summary coverage.info

# gen html
genhtml coverage.info -o coverage.info.html --rc lcov_branch_coverage=1
