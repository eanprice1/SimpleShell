# Algorithm

## Language Grammar

* command line -> cmd [< fn] [| cmd]* [> fn] [&]
* cmd -> cn [arg]*
* cn -> string //command name
* fn -> string //file name
* arg -> string //argument
* Ex: cat file.txt < test | test2 > test3 &


## Input Validation

1. check for empty input
    * if empty, restart input prompt
    * if not empty, continue to step 2
2. check for exit command and end shell if exit is requested
3. Check if command is first string in command line
    * iterate through each character until whitespace or EOL is detected
    * if current character is |, <, or > then return -1
    * return current index when end of string is reached
4. Iterate to 1st character of next string
    * if < then validate < filename
    * if | then validate pipe command
    * if > then validate > filename
    * if & then done
    * else validate cmd arg