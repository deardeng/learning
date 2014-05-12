let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <S-Tab> 
imap <silent> <expr> <F5> (pumvisible() ? "\<Plug>LookupFileCE" : "")."\\<Plug>LookupFile"
inoremap <Plug>LookupFileCE 
cmap <F1> 
imap <F1> 
nmap  h
nmap <NL> j
nmap  k
nmap  l
nmap  :BottomExplorerWindow
nmap  :FirstExplorerWindow
nnoremap <silent> w :CCTreeWindowToggle
nnoremap <silent> y :CCTreeWindowSaveCopy
vnoremap <silent> # :call VisualSearch('b')
vnoremap <silent> * :call VisualSearch('f')
map <silent> ,mm :ShowMarksPlaceMark
map <silent> ,ma :ShowMarksClearAll
map <silent> ,mh :ShowMarksClearMark
map <silent> ,mo :ShowMarksOn
map <silent> ,mt :ShowMarksToggle
map ,mbt <Plug>TMiniBufExplorer
map ,mbu <Plug>UMiniBufExplorer
map ,mbc <Plug>CMiniBufExplorer
map ,mbe <Plug>MiniBufExplorer
nmap ,ihn :IHN
nmap ,is :IHS:A
nmap ,ih :IHS
noremap ,dm mzHmx:%s///ge'xzt'z:delm x z
nmap <silent> ,lv :lv /=expand("<cword>")/ %:lw
nmap ,cw :cw 10
nmap ,cp :cp
nmap ,cn :cn
nmap <silent> ,bb :TagbarToggle
nmap <silent> ,of :FSHere
vmap <silent> ,hr <Plug>MarkRegex
nmap <silent> ,hr <Plug>MarkRegex
vmap <silent> ,hh <Plug>MarkClear
nmap <silent> ,hh <Plug>MarkClear
vmap <silent> ,hl <Plug>MarkSet
nmap <silent> ,hl <Plug>MarkSet
nmap <silent> ,mk :MarksBrowser
nmap <silent> ,lw :LUWalk
nmap <silent> ,ll :LUBufs
nmap <silent> ,lk :LUTags
nmap <silent> ,tt :NERDTreeToggle
nmap <silent> ,wm :WMToggle
nmap <silent> ,tl :Tlist
map ,yr :YRShow
map ,s? z=
map ,sa zg
map ,sp [s
map ,sn ]s
map ,t4 :set shiftwidth=4
map ,t2 :set shiftwidth=2
vmap <silent> ,zo zO
nmap <silent> ,zo zO
map ,ec :tabnew ~/tmp/scratch.txt
map ,es :tabnew:setl buftype=nofile
nmap <silent> ,ws :call DeleteTrailingWS():w
map <silent> ,cd :cd %:p:h
map ,tm :tabmove
map ,tc :tabclose
map ,te :tabedit
map ,tn :tabnew
map ,bd :Bclose
nmap ,fu :se ff=unix
nmap ,fd :se ff=dos
map ,$ :syntax sync fromstart
map ,4 :set ft=javascript
map ,3 :set syntax=python
map ,2 :set syntax=xhtml
map ,1 :set syntax=c
map <silent> ,ee :call SwitchToBuf("~/.vimrc")
map <silent> ,ss :source ~/.vimrc
nmap <silent> ,rr :redraw!
nmap <silent> , :noh
nmap <silent> ,qa :qa
nmap <silent> ,qq :q
nmap <silent> ,qf :q!
nmap <silent> ,qw :wq
nmap <silent> ,wf :w!
nmap <silent> ,ww :w
imap ° 0i
imap ¤ $a
vmap [% [%m'gv``
vmap ]% ]%m'gv``
vmap a% [%v]%
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
nmap <silent> <F5> <Plug>LookupFile
nmap <Nul>d :cs find d =expand("<cword>")
nmap <Nul>i :cs find i ^=expand("<cfile>")$
nmap <Nul>f :cs find f =expand("<cfile>")
nmap <Nul>e :cs find e =expand("<cword>")
nmap <Nul>t :cs find t =expand("<cword>")
nmap <Nul>c :cs find c =expand("<cword>")
nmap <Nul>g :cs find g =expand("<cword>")
nmap <Nul>s :cs find s =expand("<cword>")
vmap <F1> 
nmap <F1> 
cnoremap  <Home>
inoremap  
cnoremap  <End>
inoremap  
imap 	 
inoremap <expr> <NL> pumvisible()?"\<PageDown>\\":"\"
inoremap <expr>  pumvisible()?"\<PageUp>\\":"\"
cnoremap  
inoremap  
inoremap <expr>  pumvisible()?"\":"\"
inoremap <expr>  pumvisible()?"\":"\"
inoremap <expr>  omni#cpp#maycomplete#Complete()
imap  =CtrlXPP()
inoremap  
imap ,ihn :IHN
imap ,is :IHS:A
imap ,ih :IHS
inoremap <expr> . omni#cpp#maycomplete#Dot()
inoremap <expr> : omni#cpp#maycomplete#Scope()
inoremap <expr> > omni#cpp#maycomplete#Arrow()
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autoread
set background=dark
set backspace=eol,start,indent
set cindent
set cmdheight=2
set complete=.,w,b,t
set completeopt=menu
set cscopeprg=/usr/bin/cscope
set cscopetag
set cscopetagorder=1
set cscopeverbose
set diffopt=filler,vertical
set expandtab
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,sjis,euc-kr,ucs-2le,latin1
set guicursor=n-v-c:block,o:hor50,i-ci:hor15,r-cr:hor30,sm:block,a:blinkon0
set helplang=cn
set history=400
set hlsearch
set incsearch
set laststatus=2
set lazyredraw
set omnifunc=omni#cpp#complete#Main
set pastetoggle=<F3>
set ruler
set sessionoptions=blank,buffers,folds,help,options,tabpages,winsize,sesdir
set shiftwidth=4
set smartindent
set smarttab
set switchbuf=useopen
set termencoding=utf-8
set viminfo='10,\"100,:20,n~/.viminfo
set whichwrap=b,s,<,>
set wildmenu
set nowritebackup
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
exe "cd " . escape(expand("<sfile>:p:h"), ' ')
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +0 01list.cpp
args ~/learning/ds2/01list.cpp
edit 01list.cpp
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
argglobal
nnoremap <buffer> <silent> - :CCTreeRecurseDepthMinus
nnoremap <buffer> <silent> = :CCTreeRecurseDepthPlus
map <buffer> ,  :make
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal nobinary
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,t
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=0
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal nolist
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=omni#cpp#complete#Main
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=8
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 38 - ((20 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
38
normal! 0
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
