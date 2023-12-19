---
date: 2023-09-28
tags:
---
# LPC Vim settings
This are settings to quickly setup vim by memory and to change keyboard layout in order to work efficiently on the Debian virtual machine in the UNI Lab.
First to use the us keyboard layout:
```bash
> setxkbmap us
```
For setting the us QWERTY layout.
```bash
> setxkbmap us -variant dvorak
```
For setting the us dvorak layout.

In order to make CAPSLOCK behave as ESC run:
```bash
> setxkbmap -option caps:escape 
```

Finally create `.vimrc` in `$HOME` and add these four lines:
```vim
set number
set relativenumber
set tabstop=4
syntax on
```
These are pretty self-explanatory: they set line numbers and relative line numbers, make tab indents four spaces long and enable syntax highlighting in
some languages like C and C++.\
Remember that running \<CTRL-N> and \<CTRL-P> on a partially written word in insert mode will show completions and cycle them.

---
# Riferimenti

