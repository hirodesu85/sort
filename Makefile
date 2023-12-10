sort_collection: sort_collection.o main_sort_collection.o queue.o

main_sort_time: sort_collection.o main_sort_time.o



.PHONY: clean
clean:
	-rm sort_collection main_sort_time sort_collection.o main_sort_collection.o main_sort_time.o queue.o
