#!/bin/zsh
source ~/Downloads/dotfiles/zsh/alias

export HANA="/home/benjamin/Downloads/hana/include/"
export CPPFMT="/home/benjamin/Downloads/cppformat/"
export CPPFMT_LD="/home/benjamin/Downloads/cppformat/build/cppformat/"
clang++ --std=c++14 -stdlib=libstdc++ $@ -static -lstdc++ -I$CPPFMT -L$CPPFMT_LD -lcppformat
