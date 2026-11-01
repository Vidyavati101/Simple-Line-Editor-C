# Simple Line Editor — Help

## Description
A command-line text editor written in C. It supports inserting, deleting, and displaying lines.

## Compilation
Run:
`gcc line_editor.c -o line_editor`

## Execution
On Windows:
`.\line_editor.exe`

## Commands

### 1. Insert a line
Choose option 1, enter a valid position, and type the text.

Example:
Position: 1
Text: Hello

### 2. Delete a line
Choose option 2 and enter the line number to delete.

Example:
Line number: 1

### 3. Display document
Choose option 3 to display all lines with their line numbers.

### 4. Exit
Choose option 4 to close the program.

## Error Handling
The program reports invalid positions, invalid menu choices, and attempts to delete from an empty document.