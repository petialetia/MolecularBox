NAME="$1"
DIRECTION="$2"

if [[ $NAME == "" ]]
then
    echo "Enter name of hpp"
    read NAME
fi

if [[ $DIRECTION == "" ]]
then
    echo "Enter direction of hpp"
    read DIRECTION
fi

SCREAMING_SNAKE_NAME=$(./casbab/casbab.sh screamingsnake $NAME)

HPP_FILE=${DIRECTION}/${NAME}.hpp

touch ${HPP_FILE}
echo "#ifndef ${SCREAMING_SNAKE_NAME}_HPP" >> ${HPP_FILE}
echo "#define ${SCREAMING_SNAKE_NAME}_HPP" >> ${HPP_FILE}
echo "" >> ${HPP_FILE}
echo "" >> ${HPP_FILE}
echo "" >> ${HPP_FILE}
echo "#endif /* ${SCREAMING_SNAKE_NAME}_HPP */" >> ${HPP_FILE}