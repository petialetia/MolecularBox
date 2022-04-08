TOTAL_N_LINES=0

START_FOLDER=$(pwd)

function CountLines {
    cd "$1"
    FILES=$(find -type f -name "*.$2")

    for file in $FILES
    do
        N_LINES=$(wc -l < "$file")
        ((TOTAL_N_LINES=TOTAL_N_LINES+N_LINES))
    done

    cd "$START_FOLDER"
}

CountLines src cpp
CountLines include hpp

echo "$TOTAL_N_LINES"