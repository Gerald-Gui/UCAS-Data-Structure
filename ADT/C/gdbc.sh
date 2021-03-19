if test -e ./$1.cpp
then
    echo Compiling source code
    gcc -g $1.c -o $1
    echo Run $1
    ./$1
    echo delete output file : $1
    rm -f $1
else
    echo Error: illegal source file name
    echo Usage: ./gdbc.sh <file_name_without_.c>
fi
