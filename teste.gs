reinit
'open model.ctl'
'set display color white'
'clear'
'd ps'
'v=max(ps,x=1,x=73)'
'd max(v, y=1,y=46)'
say result
'd max2d(ps)'
say result

'v=min(ps,x=1,x=73)'
'd min(v, y=1,y=46)'
say result
'd min2d(ps)'
say result

*fim