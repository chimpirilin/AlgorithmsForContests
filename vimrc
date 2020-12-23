map <F9> :w :<C-U>!g++ -O2 -std=c++14 -Wall %:r.cpp -o %:r<CR>
map <F5> :<C-U>!./%:r<CR>
:set number
:set tabstop=4
:set shiftwidth=4
:set expandtab
:set smartindent
:set autochdir
inoremap {<CR> {<CR>}<ESC>O
