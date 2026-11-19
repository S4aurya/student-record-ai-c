# Student Record System in C

This is my project for PRC1001 Programming in C at UPES.

## What it does

It is a menu based program made in C language. You can store student records and do different operations on them.

Features:
- Add student details
- Search a student by SAP ID
- Show all students
- Delete a student
- Calculate CGPA
- Find average CGPA year wise
- Sort by SAP ID or Name
- Academic advisor based on CGPA (AI assisted feature)

## How to run

First compile it using gcc:

```
gcc 590042392.c -o program
```

Then run:

```
program.exe
```

## Files

- 590042392.c - main c program
- README.md - this file
- AI_USAGE_LOG.md - how i used ai tools
- tests/ - sample input and output files

## AI Feature

I used ChatGPT to get ideas for the academic advisor part. Based on the CGPA it shows different messages like excellent performance or needs improvement. I wrote the if else logic myself in C after getting the idea from ChatGPT. More details in AI_USAGE_LOG.md
