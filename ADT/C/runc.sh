if test -e ./$1.c
then
    echo Compiling source code
    gcc -std=c11 -O2 $1.c -lm -o $1
    echo Run $1
    ./$1
    echo Delete output file : $1
    rm -f $1
else
    echo Error: illegal source file name
    echo Usage: ./runc.sh file_name_without_.c
fi
