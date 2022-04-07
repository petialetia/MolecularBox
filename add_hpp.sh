NAME="$1"

if [[ $NAME == "" ]]
then
    echo "Enter name of hpp"
    read NAME
fi

SCREAMING_SNAKE_NAME=$(./casbab/casbab.sh screamingsnake $NAME)

HPP_FILE=include/${NAME}.hpp

touch ${HPP_FILE}
echo "#ifndef ${SCREAMING_SNAKE_NAME}_HPP" >> ${HPP_FILE}
echo "#define ${SCREAMING_SNAKE_NAME}_HPP" >> ${HPP_FILE}
echo "" >> ${HPP_FILE}
echo "" >> ${HPP_FILE}
echo "" >> ${HPP_FILE}
echo "#endif /* ${SCREAMING_SNAKE_NAME}_HPP */" >> ${HPP_FILE}