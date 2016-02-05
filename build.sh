#!/bin/zsh
source ~/Downloads/dotfiles/zsh/alias

export HANA="/home/benjamin/Downloads/hana/include/"
clang++ --std=c++14 -stdlib=libc++ $@ -static -lstdc++ -I $HANA
