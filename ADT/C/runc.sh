if test -e ./$1.c
then
    echo Compiling source code
    gcc -std=c11 -O2 $1.c -lm -o $1
    if [ $? -eq 0 ]
    then
        echo Run $1
        ./$1
        echo Delete output file : $1
        rm -f $1
    fi
else
    echo Error: illegal source file name
    echo Usage: ./runc.sh file_name_without_.c
fi
