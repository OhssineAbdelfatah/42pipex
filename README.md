# 42_pipex

This project aims to deepen your understanding of the two concepts : Redirections and Pipes.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Building](#building)

## Introduction

This pipex was created as part of the 1337 coding school curriculum and is designed to be used in various C projects. The goal is to provide a bash functionality coded in c.

## Features

- handle pipes
- handle redirection

## Usage

To use the `pipex` program , follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/OhssineAbdelfatah/42_pipex.git
```

2. build you project:

```bash
make ; make clean
echo "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec sagittis, orci sed condimentum commodo, odio augue tempor ipsum, ut pharetra sem eros a magna. Etiam vitae porta nunc. Vest" >> infile
```

4. Run your program:

```bash
./pipex infile cat "wc -w" outfile
```
## Building

To build your project, run:

```bash
make
```
This will generate the pipex executable.

To clean up the build files, run:

```bash
make clean
```

To remove the `pipex` library and all build files, run:

```bash
make fclean
```
<!-- 
## Contributing

Contributions are welcome! If you would like to contribute to the library, please follow the guidelines in the CONTRIBUTING.md file.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

```vbnet
Remember to replace placeholders like `your-username` and customize the information according to your project.
``` -->
## Author

OhssineAbdelfatah

abdelfatah.ohssine@gmail.com
