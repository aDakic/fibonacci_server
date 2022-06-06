# fibonacci_server
Small C++17 web server for calculating fib(n), based on gRPC. Besides web sever, small client and library for further extensions are available.

## Build
Download dependencies:
```bash
mkdir build
conan install     -s compiler=gcc \
                  -s compiler.version=9 \
                  -s compiler.libcxx=libstdc++11 \
                  -if build .
```

Setup CMake and build
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Usage
Server supports following comand line options:
```console
  -h [ --help ]                  Display this help message
  --ip_address arg (=localhost)  Server IP address
  -p [ --port ] arg              Server port
  -l [ --log_level ] arg (=info) Log level: error, info, debug
```

Client supports following command line options:
```console
  -h [ --help ]                  Display this help message
  --ip_address arg (=localhost)  Server IP address
  -p [ --port ] arg              Server port
  -l [ --log_level ] arg (=info) Log level: error, info, debug
  --numbers arg                  Numbers for calculation
```

### Example
#### Server side
```bash
./fib-server --port 5000 --log_level debug
```
Output:
```console
[2022-06-06 09:53:02.925] [info] Starting fibonacci server...
[2022-06-06 09:53:02.926] [debug] gRPC receiver successfully created.
[2022-06-06 09:53:02.926] [debug] Fibonacci server successfully created.
[2022-06-06 09:53:02.926] [debug] gRPC receiver successfully started.
[2022-06-06 09:53:02.926] [debug] Fibonacci server is successfully started.
```

#### Client side
``` bash
./fib-client --port 5000 --numbers 1 5 45 100
```

Output:
``` console
[2022-06-06 09:56:23.165] [info] fib(1): 0 timestamp: 0 count: 1
[2022-06-06 09:56:23.165] [info] fib(5): 5 timestamp: 0 count: 1
[2022-06-06 09:56:23.165] [info] fib(45): 1134903170 timestamp: 0 count: 1
[2022-06-06 09:56:23.165] [info] fib(100): 354224848179261915075 timestamp: 0 count: 1
```

