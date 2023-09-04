codebook.pdf: codebook.tex list.tex
	xelatex codebook.tex
	xelatex codebook.tex

list.tex: GenCodebookList.py
	python3 GenCodebookList.py

clean:
	rm codebook.pdf -f
	rm list.tex -f
