x #remove cur cusor character
dd # remove cur line 
dw # remove cur cusor word
d$ # remove cursor to line end



:s/old/new/g     # cur line  
:n,m/s/old/new/g # n-m lines
:%s/old/new/g    # whole text
:
