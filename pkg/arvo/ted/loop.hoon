/-  spider
=,  strand=strand:spider
^-  thread:spider
|=  arg=vase
=/  m  (strand ,vase)
^-  form:m
~&  'hello'
|=  tin=strand-input:strand
:: =/  poke  [%pass /some/wire %arvo %b %wait (add ~s1 now.bowl.tin)]
=/  poke  [%pass /some/wire %arvo %l %load 'load']
[~[poke] %done arg]
