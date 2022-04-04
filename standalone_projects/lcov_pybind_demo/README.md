# cmake_lcov_demo

cmake work with lcov for code coverage

## How to start

### Prepare env

need [`lcov`](https://github.com/linux-test-project/lcov) pre-installed

### Start demo

```sh
# cmake configure
cmake -DWITH_COVERAGE:STRING=ON -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -S`pwd` -B`pwd`/build

# cmake build
cmake --build `pwd`/build --target all

# run coverage
cmake --build `pwd`/build --target coverage
```
