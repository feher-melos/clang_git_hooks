#!/bin/bash

CMD=`basename $0`

if [ $# -lt 1 ]; then
    echo
    echo "This script checks and fixes code formatting in git commits."
    echo
    echo "Missing arguments."
    echo
    echo " Usages:"
    echo
    echo "  a) $CMD commit-sha"
    echo "  b) $CMD commit-sha commit-sha"
    echo "  c) $CMD from-commit-sha..to-commit-sha"
    echo "  d) $CMD from-commit-sha^1..to-commit-sha"
    echo "  e) $CMD --check-only ...."
    echo
    echo "Explanation:"
    echo
    echo "  a) Format files that were modified in a given commit."
    echo "  b) Format files that were modified in the given commits."
    echo "  c) Format files that were modified in the given commit range (from-commit-sha is EXCLUDED)."
    echo "  d) Format files that were modified in the given commit range (from-commit-sha is INCLUDED)."
    echo "  e) Check the format of files that were modified in the given commits. Does not format the files."
    echo
    exit 1
fi

CHECK_FAILED="no"
CHECK="no"
if [ "$1" == "--check-only" ]; then
    CHECK="yes"
    shift
fi

function format_file()
{
    echo -n "Formatting $FILE..."
    clang-format -i $FILE
    #clang-tidy --quiet -p=build --fix --format-style=file $FILE 2>/dev/null
    echo "done"
}

function check_file()
{
    echo -n "Checking format of $FILE..."
    local OUTPUT=`clang-format --dry-run $FILE 2>&1`
    if [ -n "$OUTPUT" ]; then
        echo "FAILED"
        CHECK_FAILED="yes"
    else
        echo "ok"
    fi
    #local OUTPUT=`clang-tidy --quiet -p=build $FILE 2>/dev/null | grep 'warning:'`
    #if [ -n "$OUTPUT" ]; then
    #    echo "Code style check FAILED $FILE"
    #    CHECK_FAILED="yes"
    #fi
}

function process_files()
{
    for FILE in "$@"; do
        if [ "$CHECK" == "yes" ]; then
            check_file $FILE
        else
            format_file $FILE
        fi
    done
}

function process_commit_ranges()
{
    for COMMIT_RANGE in "$@"; do
        local FILE_LIST=`git diff-tree --no-commit-id --name-only -r $COMMIT_RANGE | grep -i -E '.*\.(c|cpp|h|hpp)$'`
        if [ -z "$FILE_LIST" ]; then
            continue
        fi
        process_files $FILE_LIST
        if [ "$CHECK_FAILED" == "yes" ]; then
            echo
            echo "Run this to fix the formatting: "
            echo
            echo "  $CMD $COMMIT_RANGE"
            echo "  git commit -a -m 'Code format fix'"
            echo
        fi
    done
}

process_commit_ranges "$@"

if [ "$CHECK_FAILED" == "yes" ]; then
    exit 1
fi
