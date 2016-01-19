#!/bin/bash

case $1 in
  ("homebrew")
    brew install cmake pcre ;;
  ("ubuntu")
    apt-get install cmake build-essential yodl bison ;;
  (*)
    echo "Usage: ./install_prereqs.sh package_manager"
    echo "where package_manager is one of the following: "
    echo "  homebrew"
    echo "  ubuntu"
    exit 1 ;;
esac
