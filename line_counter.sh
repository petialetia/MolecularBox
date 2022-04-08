TOTAL_N_LINES=0

cd src

CPP_FILES=$(find -type f -name "*.cpp")

for file in $CPP_FILES
do
    N_LINES=$(wc -l < "$file")
    ((TOTAL_N_LINES=TOTAL_N_LINES+N_LINES))
done

cd ..

cd include

HPP_FILES=$(find -type f -name "*.hpp")

for file in $HPP_FILES
do  
    N_LINES=$(wc -l < "$file")
    ((TOTAL_N_LINES=TOTAL_N_LINES+N_LINES))
done

cd ..

echo "$TOTAL_N_LINES"