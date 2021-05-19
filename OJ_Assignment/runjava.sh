if test -e ./$1.java
then
    echo javac $1.java -d $1/
    javac $1.java -d $1/
    echo running $1
    cd $1/ && java $1
    echo delete output file
    cd .. && rm -r $1/
else
    echo Error: illegal src file name
    echo Usage: ./runjava.sh [public class name]
fi
