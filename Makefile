include Makefile.in

check: lope_test_image.lock
	${DOCKER} run --rm -v ./:/lope_test:ro lope_test_image

lope_test_image.lock:
	${DOCKER} build -f ./test/Dockerfile -t lope_test_image .
	touch lope_test_image.lock

install:
	cp lope ${PREFIX}

Makefile.in:
	./configure

clean:
	rm lope_test_image.lock || :
	rm Makefile.in || :
