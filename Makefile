n=node
e=exception
b=bst
m=main
nr=$(n).h $(n).tpp
er=$(e).h
br=$(nr) $(er) $(b).h $(b).tpp
mr=$(br) $(m).cpp
mc=$(m).cpp

do: compile
	./$(m)

compile: $(mr)
	g++ -o $(m) $(mc)

