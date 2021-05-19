if test -e ./$1.c
then
    echo Compiling source code
    gcc -g -std=c11 $1.c -lm -o $1
    if [ $? -eq 0 ]
    then
        echo Run $1
        ./$1
        echo delete output file : $1
        rm -f $1
    fi
else
    echo Error: illegal source file name
    echo Usage: ./gdbc.sh file_name_without_.c
fi
