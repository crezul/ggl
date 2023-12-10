# google search from terminal
 Author: @crezul
 https://github.com/crezul
 2023-12-09




## Environment setup
### macOS
> Tested on macOS Sonoma

```shell
brew install cmake
```

```shell
mkdir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
```


## To build the project
```shell
cd build && make
```


