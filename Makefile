cc=clang
obj=out
src=main.c
flags=-Wall -O3 
$(obj):$(src)
	$(cc) $(src) $(flags) -o $(obj) && strip $(obj)
	@(echo "Compilation done.") 
