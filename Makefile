GET_WORD = /home/kyle/getWord
wordpairs : main.c crc64.o hashTable.o wordCount.o getWord.o
	gcc -o wordpairs $^ -I ${GET_WORD}/include ${GET_WORD}/lib/libget.a
getWord.o :
	cc -c ${GET_WORD}/include/getWord.c ${GET_WORD}/include/getWord.h
wordCount.o : wordCount.c wordCount.h
	cc -c $^	
hashTable.o : hashTable.c hashTable.h
	cc -c $^
crc64.o : crc64.c crc64.h
	cc -c $^ 	
clean :
	rm wordpairs hashTable.o crc64.o wordCount.o getWord.o
	@echo ${GET_WORD} ${GET_WORD}
