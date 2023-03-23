REPO_DIR='/usr/local/repos'
PROC_GAL_PATH='marcos-22nd-puzzles/process-galore'
BIN_DIR='/usr/local/bin'

cd "$REPO_DIR/$PROC_GAL_PATH"
make >> /dev/null
cp process-galore $BIN_DIR

cd $BIN_DIR
./process-galore & >> /dev/null
