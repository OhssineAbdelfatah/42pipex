# Pipex

This project is an implementation of the Unix `pipe` command in C.

## Description

The goal of this project is to learn more about process creation and redirections in C. `Pipex` is a program that will create two child processes. The first child will execute a command with its output redirected to a pipe, and the second child will execute a second command with its input redirected from the same pipe.

## Installation

Clone the repository and run `make`:

```bash
git clone https://github.com/yourusername/pipex.git
cd pipex
make