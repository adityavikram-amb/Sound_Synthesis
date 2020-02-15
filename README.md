# Sound Generation

A simple C++ program to generate audio notes.

## Getting Started

Use Console application as 32-bit(x86) mode in Visual Studio.

### Prerequisites

Visual Studio 2019



### Installing

Before running the application include winmm.lib


### And coding style tests

Single line string input.
Let i denote the i<sup>th</sup> index of string str.
```c++
(str[i]%3==0) \\ wil give octave
(str[i]%3==1) \\ wil give note
(str[i]%3==2) \\ sharp note
```
Example: Sweet Child O'Mine
```
4C#5C#4G#4F#5F#4G#5F 4G# 
```

User can also play notes on keyboard.
