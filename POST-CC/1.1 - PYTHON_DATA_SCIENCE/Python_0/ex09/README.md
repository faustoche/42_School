# ft_package

A simple test package.

## Description

This packet gives simple tools for list manipulation. It includes a function allowing to count the number of occurrences of a specific element among a given list.

## Installation

Installation by `pip` thamks to generated files in `dist/` folder:


```bash
pip install ./dist/ft_package-0.0.1.tar.gz
```
or
```bash
pip install ./dist/ft_package-0.0.1-py3-none-any.whl
```

## Use

Here an example of how to import and use the main function:


```python
from ft_package import count_in_list

print(count_in_list(["toto", "tata", "toto"], "toto")) # output: 2
```