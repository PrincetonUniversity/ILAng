pdfs: concurrency.pdf interrupt.pdf timing.pdf

all: $(pdfs)

%.pdf: *.tex code/* images/* #*.bib
	pdflatex -halt-on-error -pdf -bib $*.tex
	#bibtex $*
	pdflatex -halt-on-error -pdf -bib $*.tex
	pdflatex -halt-on-error -pdf -bib $*.tex

clean:
	rm -f *.bbl *.blg *.log *.out *.aux *.pdf
